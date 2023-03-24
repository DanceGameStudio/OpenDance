#pragma once

#include "Input.hpp"

namespace Input {

class Camera : public Input 
{
    // cv::Mat& read() override;

    void resize(const int width, const int height) override;

    void change_color_space(const ColorSpace colorSpace) override;

};

}
