#pragma once

#include "Camera.hpp"
#include <iostream>

namespace Input {

Camera::Camera()
{
}

cv::Mat Camera::read() 
{
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    if (capture_.isOpened()) {
        capture_.read(image);
    }
 
    if (image.size().height != height_ && image.size().width != width_ && !image.empty()) {
        cv::resize(image, image, cv::Size(width_, height_), cv::INTER_LINEAR);
    }
    return image;
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