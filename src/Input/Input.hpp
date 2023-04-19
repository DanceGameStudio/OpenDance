#pragma once

#include <opencv2/videoio.hpp>
//#include <opencv2/core.hpp>

namespace Input {

enum ColorSpace {
    RGB,
    HSV,
    LAB,
    CMYK
};

class Input {
public:
    virtual ~Input() { }
    virtual cv::Mat& read() = 0;
    virtual void resize(const int width, const int height) = 0;
    virtual void change_color_space(const ColorSpace color_space) = 0;
};

}