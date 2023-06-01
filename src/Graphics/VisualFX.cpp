#include "VisualFX.hpp"

namespace Graphics {

void VisualFX::draw_keypoints(cv::Mat& image, const std::vector<PoseEstimation::Keypoint>& keypoints)
{
    for (const auto& keypoint : keypoints) {
        cv::Point2f point(keypoint.x * image.rows, keypoint.y * image.cols);
        cv::circle(image, point, 2, cv::Scalar(0, 255, 0), cv::FILLED);
    }
}

}
