#include <chrono>
#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include <Python.h>
#include "PoseDetector.hpp"

namespace py = pybind11;

namespace PoseEstimation {

const std::string pose_detection = R"(
import traceback
import cv2
import numpy as np
import mediapipe as mp

def detect_pose(image):
    with mp.solutions.pose.Pose(min_detection_confidence=0.5, min_tracking_confidence=0.5, static_image_mode=True, enable_segmentation=False) as pose:
        results = pose.process(cv2.cvtColor(image, cv2.COLOR_BGR2RGB))
    keypoints = []
    if results.pose_landmarks is not None:
        for landmark in results.pose_landmarks.landmark:
            keypoints.append((landmark.x, landmark.y, landmark.z))
    return np.array(keypoints, dtype=np.float16)
)";


py::scoped_interpreter guard {};
py::object globals = py::globals();
py::object locals = py::dict();

void initialize_interpreter() {
    py::exec(pose_detection, globals, locals);
}

PoseDetector::PoseDetector()
{
    initialize_interpreter();
}

Pose PoseDetector::get_pose(const cv::Mat& image)
{
    Pose pose;
    pose.timestamp = std::chrono::steady_clock::now();
    pose.keypoints = detect_keypoints(image);
    //poses_.push_back(pose);
    return pose;
}

std::vector<Keypoint> PoseDetector::detect_keypoints(const cv::Mat& image)
{
    std::vector<Keypoint> keypoints;
   // py::scoped_interpreter guard {};
    try {
        //py::exec(pose_detection, globals, locals);
        py::function detect_pose = locals["detect_pose"];

        // Bild auf die Zielgröße skalieren
        cv::Mat process_image;
        image.copyTo(process_image);
        const int image_width = 300;
        const int image_height = 300;
        const cv::Size targetSize(image_width, image_height);
        if (!process_image.empty() && process_image.size() != targetSize) {
            cv::resize(process_image, process_image, targetSize);
        }

        // Call function with a test image
        py::array_t<uint8_t> np_image = py::array_t<uint8_t>({ process_image.rows, process_image.cols, process_image.channels() }, process_image.data);
      
        py::array_t<float> np_keypoints = detect_pose(np_image).cast<py::array_t<float>>();
        //py::array_t<float> np_keypoints;
        py::print("Number of Keypoints:");
        py::print(np_keypoints.shape());
        // Convert Numpy array to std::vector<Keypoint>
        auto buffer = np_keypoints.request();
        float* data_ptr = static_cast<float*>(buffer.ptr);
        size_t num_keypoints = buffer.size / 3;

        keypoints.reserve(num_keypoints);

        for (size_t i = 0; i < num_keypoints; ++i) {
            size_t index = i * 3;
            keypoints.emplace_back(Keypoint{ data_ptr[index], data_ptr[index + 1], data_ptr[index + 2] });
        }
        //for (const auto& keypoint : keypoints) {
        //    cv::Point2f point(keypoint.x * image_width, keypoint.y * image_height);
        //    cv::circle(process_image, point, 2, cv::Scalar(255, 255, 0), cv::FILLED);
        //}
        //cv::imshow("Image", process_image);
        //cv::waitKey(1);
    } catch (const py::error_already_set& ex) {
        py::print("Exception caught:");
        //py::print(ex.what());
        py::print("Stacktrace:");
        //py::print(ex.trace());
    }
    return keypoints;
}

}