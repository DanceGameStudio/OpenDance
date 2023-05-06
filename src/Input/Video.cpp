#pragma once

#include "Video.hpp"
#include <iostream>

namespace Input {

Video::Video()
{
}

void Video::read(cv::Mat& image)
{
    bool success = capture_.read(image_);
    if (!capture_.isOpened() || !success) {
        connect();
    } else if (image_.empty()) {
        image_ = cv::Mat(height_, width_, CV_8UC3, cv::Scalar(0, 0, 0));
    }
    image_.copyTo(image);
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
    fps_ = capture_.get(cv::CAP_PROP_FPS);
    capture_.set(cv::CAP_PROP_FPS, fps_);
    if (!capture_.isOpened()) {
        return false;
    }
    return true;
}
}
