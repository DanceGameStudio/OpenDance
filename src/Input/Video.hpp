#pragma once

#include "Input.hpp"

namespace Input {

class Video : public Input 
{
public:
    Video();

    void read();

    cv::Mat get_image();

    void resize(const int width, const int height) override;

    void change_video_path(std::string& path);

    bool connect() override;

    void set_read_mode(bool mode);

    std::mutex video_mutex_; 
private:
    cv::VideoCapture capture_;
    std::string video_path_ = "";
    cv::Mat image_;
    int width_ = 640;
    int height_ = 480;
    int fps_ = 1;
    bool read_mode_ = false;
};

}