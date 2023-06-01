#pragma once

#include "PoseDetector.hpp"

namespace Graphics {

class VisualFX 
{
public:
    void draw_keypoints(cv::Mat& image, const std::vector<PoseEstimation::Keypoint>& keypoints);
};

}