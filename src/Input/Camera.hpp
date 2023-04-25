#pragma once

#include "Input.hpp"

namespace Input {

class Camera : public Input 
{
public:

    cv::Mat read();

    void resize(const int width, const int height) override;

    void change_color_space(const ColorSpace colorSpace) override;

private:
    cv::Mat image_;
    int width_;
    int height_;
};

}
