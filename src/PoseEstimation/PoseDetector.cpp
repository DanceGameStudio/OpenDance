#include <chrono>
#include "PoseDetector.hpp"

namespace PoseEstimation {

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
    // Create an instance of the ORB feature detector
    cv::Ptr<cv::ORB> detector = cv::ORB::create();

    // Detect keypoints in the image
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(image, keypoints);

    // Convert the OpenCV KeyPoint objects to Keypoint objects
    std::vector<Keypoint> keypoints_out;
    for (const auto& kp : keypoints) {
        keypoints_out.emplace_back(kp.pt.x, kp.pt.y);
    }

    return keypoints_out;
}

}
