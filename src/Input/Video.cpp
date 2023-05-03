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
            image_ = cv::Mat(height_, width_, CV_8UC3, cv::Scalar(0, 0, 0));          
        } else if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
            cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
        }
        auto now = std::chrono::system_clock::now();
        std::ostringstream oss;
        oss << now;
        std::string time = oss.str();

        if (!image_.empty()) {
            cv::putText(image_, // target image
                time, // text
                cv::Point(10, image_.rows / 2), // top-left position
                cv::FONT_HERSHEY_DUPLEX,
                1.0,
                CV_RGB(118, 185, 0), // font color
                2);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
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
