#include <chrono>
#include <openpose/wrapper/enumClasses.hpp>
#include "PoseDetector.hpp"

namespace PoseEstimation {

PoseDetector::PoseDetector()
{
    configureWrapper(op_wrapper_);
    if (wrapper_configured_) {
        op_wrapper_.start();
    }
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
    std::vector<Keypoint> detected_keypoints;
    try {
        if (wrapper_configured_) {
            auto datumProcessed = op_wrapper_.emplaceAndPop(OP_CV2OPCONSTMAT(image));
            if (datumProcessed != nullptr && !datumProcessed->empty()) {
                op::Array<float> keypoints = datumProcessed->at(0)->poseKeypoints;
                int coco_keypoint_size = 18;
                // Berwertung nur für Person 0 und 2D
                for (int i = 0; i < coco_keypoint_size; i++) {
                    Keypoint point = { keypoints[0, i, 0], keypoints[0, i, 1], 0 };
                    detected_keypoints.push_back(point);
                }
            }
        }
    } catch (...) {
        std::cout << "Keypoint Array broken!" << std::endl;
    }
    return detected_keypoints;
}

void PoseDetector::configureWrapper(op::Wrapper& opWrapper)
{
    try {
        wrapper_configured_ = true;
    } catch (const std::exception& e) {
        wrapper_configured_ = false;
        std::cerr << "OpenPose failed to load Wrapper. Exception: " << e.what() << std::endl;
    }
}
}