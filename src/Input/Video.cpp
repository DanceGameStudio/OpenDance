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
        cv::Mat image;
        capture_.read(image);
        std::lock_guard<std::mutex> lock(mutex_);
        image.copyTo(image_);
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

void Video::get_image(cv::Mat& image)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (image_.empty()) {
        image_ = cv::Mat(height_, width_, CV_8UC3, cv::Scalar(0, 0, 0));
    } else if (image_.size().height != height_ || image_.size().width != width_ && !image_.empty()) {
        cv::resize(image_, image_, cv::Size(width_, height_), cv::INTER_LINEAR);
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
    fps_ = capture_.get(cv::CAP_PROP_FRAME_COUNT);
    capture_.set(cv::CAP_PROP_FPS, fps_);
    if (!capture_.isOpened()) {
        return false;
    }
    return true;
}
}
