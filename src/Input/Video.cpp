#pragma once

#include "Video.hpp"

#include "opencv2/highgui.hpp"
#include "../PoseEstimation/PoseDetector.hpp"

#include <iostream>

namespace Input {

cv::Mat Video::read(const cv::String& path) 
{
    cv::VideoCapture capture;
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    capture.open(path);

    if (!capture.isOpened()) {
        std::cerr << "Unable to open video\n";
    }

    capture >> image;

    return image;
}

void Video::resize(const int width, const int height)
{
    
}

void Video::change_color_space(const ColorSpace colorSpace)
{
}

}
