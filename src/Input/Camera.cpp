#pragma once

#include "Camera.hpp"
#include <iostream>

namespace Input {

Camera::Camera()
{
}

void Camera::read(cv::Mat& image) 
{
    cv::Mat image_;
    bool success = capture_.read(image_);
    if (!success) {
        image_ = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    } else if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
        cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
    }
    image_.copyTo(image);
}

void Camera::resize(const int width, const int height) 
{
    width_  = width;
    height_ = height;
}

void Camera::change_device_id(int id)
{
    device_id_ = id;
    bool connected = connect();
    if (!connected) {
        std::cerr << "Unable to open camera\n";
    }
}

bool Camera::connect()
{
    capture_.open(device_id_);
    if (!capture_.isOpened()) {
        return false;
    }
    return true;
}

}