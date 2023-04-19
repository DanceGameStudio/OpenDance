#pragma once

#include "Camera.hpp"
#include <iostream>

namespace Input {

cv::Mat& Camera::read() 
{
    cv::VideoCapture capture;
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    int device_id = 0;
    capture.open(device_id);
    
    if (!capture.isOpened()) {
        std::cerr << "Unable to open camera\n";
    }

    capture.read(image);
    return image;
}

void Camera::resize(const int width, const int height) 
{
    width_  = width;
    height_ = height;
}

void Camera::change_color_space(const ColorSpace colorSpace) 
{

}

}