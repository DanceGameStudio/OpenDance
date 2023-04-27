#pragma once 

#include <opencv2/opencv.hpp>

#include "PoseEstimationStructs.hpp"

namespace PoseEstimation {

class PoseDetector 
{
public:
    Pose get_pose(const cv::Mat& image);

private:
    std::vector<Keypoint> detect_keypoints(const cv::Mat& image);

    std::vector<Pose> poses_;
};
}