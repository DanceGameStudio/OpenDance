#pragma once

#include "Input.hpp"

namespace Input {

class Video : public Input 
{
public:
    Video();

    void run();

    void stop();

    void start();

    cv::Mat get_image();

    void resize(const int width, const int height) override;

    void change_video_path(std::string& path);

    bool connect() override;

private:
    std::thread video_thread_;
    std::mutex mutex_;

    cv::VideoCapture capture_;
    std::string video_path_ = "";
    cv::Mat image_;
 
    int width_ = 640;
    int height_ = 480;
    int fps_ = 60;
    bool running_ = false;
};

}