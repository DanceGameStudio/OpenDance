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
                image_ = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
                read_mode_ = false;
            }

            if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
                cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
            }
            std::this_thread::sleep_for(std::chrono::seconds(fps_));
        }
    });
    input_thread.join();
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
