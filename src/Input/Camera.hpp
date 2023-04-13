#pragma once

#include <opencv2/core.hpp>
#include "Input.hpp"

namespace Input {

class Camera : public Input 
{
public:
    //cv::Mat& read() override;

    void resize(const int width, const int height) override;

    void change_color_space(const ColorSpace colorSpace) override;

private:
    cv::Mat image_;
};

}
