#include "Graphics.hpp"

namespace Graphics {

cv::Mat Graphics::get_camera_image()
{
    cv::Mat image;
	camera_->read(image);
    return image;
}

cv::Mat Graphics::get_video_image()
{
    cv::Mat image;
    video_->read(image);
    return image;
}

int Graphics::get_video_fps()
{
    return video_->get_fps();
}

void Graphics::get_preprocessed()
{

}

void Graphics::flip_camera_image()
{

}

cv::Mat Graphics::draw_keypoints_to_image(cv::Mat& image, const std::vector<PoseEstimation::Keypoint>& keypoints)
{
    cv::Mat landmark_image = image.clone();
    for (const auto& keypoint : keypoints) {
        cv::Point2f point(keypoint.x * landmark_image.cols, keypoint.y * landmark_image.rows);
        cv::circle(landmark_image, point, 3, cv::Scalar(0, 255, 0), cv::FILLED);
    }
    return landmark_image;
}

void Graphics::apply_settings(std::unique_ptr<Settings::Settings>& settings)
{
    camera_->change_device_id(settings->get_camera_id());
    video_->change_video_path(settings->get_video_path());
}

}