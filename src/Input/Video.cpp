#pragma once

#include "Video.hpp"
#include <iostream>

namespace Input {

Video::Video()
{
}

cv::Mat Video::read() 
{
    cv::Mat image = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
    if (capture_.isOpened()) {
        capture_.read(image);
    }
    
    if (image.size().height != height_ || image.size().width != width_ && !image.empty()) {
        cv::resize(image, image, cv::Size(width_, height_), cv::INTER_LINEAR);
    }
    return image;
}

void Video::resize(const int width, const int height)
{
    width_ = width;
    height_ = height;
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
