#pragma once

#include "Video.hpp"

#include "opencv2/highgui.hpp"
#include "../PoseEstimation/PoseDetector.hpp"

#include <iostream>

namespace Input {

Video::Video()
{
}

cv::Mat Video::read() 
{
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);

    if (!capture_.isOpened()) {
        std::cerr << "Unable to open video\n";
    }

    capture_.read(image);

    return image;
}

void Video::resize(const int width, const int height)
{
    width_ = width;
    height_ = height;
}

void Video::change_color_space(const ColorSpace colorSpace)
{
}

void Video::change_video_path(std::string& path)
{
    video_path_ = path;
    bool connected = connect();
    if (!connected) {
        std::cerr << "Unable to open video\n";
    }
}

bool Video::connect()
{
    capture_.open(video_path_);
    if (!capture_.isOpened()) {
        return false;
    }
    return true;
}

}
