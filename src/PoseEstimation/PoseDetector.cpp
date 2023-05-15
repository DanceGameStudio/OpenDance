#include <chrono>
#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include "Python.h"
#include "PoseDetector.hpp"

namespace py = pybind11;

namespace PoseEstimation {

const std::string pose_detection = R"(
import traceback
import sys
try:
    import numpy as np
    import cv2
    import mediapipe as mp

    def detect_pose(image):
        with mp.solutions.pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5) as pose:
            results = pose.process(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
            keypoints = []
            for landmark in results.pose_landmarks.landmark:
                keypoints.append((landmark.x, landmark.y, landmark.z))
            return np.array(keypoints, dtype=np.float32)
except Exception as e:
    traceback.print_exc()
)";

PoseDetector::PoseDetector()
{
}

Pose PoseDetector::get_pose(const cv::Mat& image)
{
    Pose pose;
    pose.timestamp = std::chrono::steady_clock::now();
    pose.keypoints = detect_keypoints(image);
    poses_.push_back(pose);
    return pose;
}

std::vector<Keypoint> PoseDetector::detect_keypoints(const cv::Mat& image)
{
    py::scoped_interpreter guard {};
    std::vector<Keypoint> keypoints;
    // Import module and function
    py::object globals = py::globals();
    py::object locals = py::dict();
    try {
        py::exec(pose_detection, globals, locals);
        py::function detect_pose = locals["detect_pose"];

        // Call function with a test image
        py::array_t<uint8_t> np_image = py::array_t<uint8_t>({ image.rows, image.cols, image.channels() }, image.data);
        py::array_t<float> np_keypoints = detect_pose(np_image).cast<py::array_t<float>>();

        // Convert Numpy array to std::vector<Keypoint>
        auto buffer = np_keypoints.request();
        auto ptr = static_cast<float*>(buffer.ptr);
        // for (size_t i = 0; i < buffer.shape(0); i++) {
        //     keypoints.push_back({ ptr[3 * i], ptr[3 * i + 1], ptr[3 * i + 2] });
        // }
    } catch (...) {
        std::cout << "Pyhton failed!" << std::endl;
    }
    return keypoints;
}

}