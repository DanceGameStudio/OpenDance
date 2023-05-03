#pragma once

#include "Video.hpp"
#include <iostream>

namespace Input {

Video::Video()
{
}

void Video::run()
{
    while (running_) {
        bool success = capture_.read(image_);
        if (!success) {
            image_ = cv::Mat::zeros(cv::Size(width_, height_), CV_8UC4);
        } else if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
            cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
        }
        std::this_thread::sleep_for(std::chrono::seconds(fps_));
    }
}

void Video::start()
{
    running_ = true;
    video_thread_ = std::thread([&]() {
        run();
    });
}

void Video::stop()
{
    running_ = false;
    if (video_thread_.joinable()) {
        video_thread_.join();
    }
}

cv::Mat Video::get_image()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return image_.clone();
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
