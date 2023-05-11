#pragma once 

#include <opencv2/opencv.hpp>
#include <openpose/headers.hpp>

#include "PoseEstimationStructs.hpp"

namespace PoseEstimation {

class PoseDetector 
{
public:
    PoseDetector();
    Pose get_pose(const cv::Mat& image);

private:
    std::vector<Keypoint> detect_keypoints(const cv::Mat& image);

    std::vector<Pose> poses_;

    op::Wrapper op_wrapper_ { op::ThreadManagerMode::Asynchronous };

    bool wrapper_configured_ = false;

    void configureWrapper(op::Wrapper& opWrapper);
};
}