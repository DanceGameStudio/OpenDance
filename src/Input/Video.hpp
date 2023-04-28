#pragma once

#include "Input.hpp"

namespace Input {

class Video : public Input 
{
public:
    Video();

    cv::Mat read() override;

    void resize(const int width, const int height) override;

    void change_video_path(std::string& path);

    bool connect() override;

private:
    cv::VideoCapture capture_;
    std::string video_path_ = "";
    cv::Mat image_;
    int width_ = 640;
    int height_ = 480;
};

}