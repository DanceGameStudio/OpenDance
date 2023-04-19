#pragma once

#include "Video.hpp"

namespace Input {

cv::Mat& Video::read()
{
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    return image;
}

void Video::resize(const int width, const int height)
{
    
}

void Video::change_color_space(const ColorSpace colorSpace)
{
}

}