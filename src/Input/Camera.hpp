#pragma once

#include "Input.hpp"

namespace Input {

class Camera : public Input 
{
public:
    Camera();

    void read(cv::Mat& image);

    void resize(const int width, const int height) override;

    void change_device_id(int id);

    bool connect() override;

private:
    cv::VideoCapture capture_;
    cv::Mat image_;
    int width_  = 640;
    int height_ = 480;
    int device_id_ = 0;
};

}
