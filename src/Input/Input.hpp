#pragma once

#include<opencv2/opencv.hpp>

namespace Input {

class Input {
public:
    virtual ~Input() { }
    virtual cv::Mat read() = 0;
    virtual bool connect() = 0;
    virtual void resize(const int width, const int height) = 0;
};

}