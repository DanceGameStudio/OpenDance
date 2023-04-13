#pragma once

#include "Input.hpp"

namespace Input {

class Video : public Input 
{
    Video(const std::string& filename)
        : filename_(filename);
  
    //cv::Mat& read() override;
   
    void resize(const int width, const int height) override;

    void change_color_space(const ColorSpace colorSpace) override;

private:
    std::string filename_;
};

}