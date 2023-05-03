#pragma once

#include "Video.hpp"
#include <iostream>

namespace Input {

Video::Video()
{
}

void Video::read() 
{
    read_mode_ = true;
    std::thread input_thread([&]() {     
        while (read_mode_) {
            bool success = capture_.read(image_);
            if (!success) {
                video_mutex_.lock();
                image_ = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC3);
                video_mutex_.unlock();
            }

            if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
                video_mutex_.lock();
                cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
                video_mutex_.unlock();
            }
            std::this_thread::sleep_for(std::chrono::seconds(fps_));
        }
    });
}

cv::Mat Video::get_image()
{
    return image_;
}

void Video::set_read_mode(bool mode)
{
    read_mode_ = mode;
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
