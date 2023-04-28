#pragma once

#include "Input.hpp"

namespace Input {

class Camera : public Input 
{
public:
    Camera();

    cv::Mat read() override;

    void resize(const int width, const int height) override;

    void change_color_space(const ColorSpace colorSpace) override;

    void change_device_id(int id);

    bool connect() override;

private:
    cv::VideoCapture capture_;
    cv::Mat image_;
    int width_;
    int height_;
    int device_id_ = 0;
};

}
