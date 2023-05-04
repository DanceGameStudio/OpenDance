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

void Graphics::get_preprocessed()
{

}

void Graphics::flip_camera_image()
{

}

void Graphics::apply_settings(std::unique_ptr<Settings::Settings>& settings)
{
    camera_->change_device_id(settings->get_camera_id());
    video_->change_video_path(settings->get_video_path());
}

}