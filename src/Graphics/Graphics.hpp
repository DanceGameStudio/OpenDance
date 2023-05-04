#pragma once

#include <memory>
#include "VisualFX.hpp"
#include "Camera.hpp"
#include "Video.hpp"
#include "Settings.hpp"

namespace Graphics {

class Graphics 
{
public:
    cv::Mat get_camera_image();

    cv::Mat get_video_image();

    void get_preprocessed();

    void flip_camera_image();

    void apply_settings(std::unique_ptr<Settings::Settings>& settings);

private:
    std::unique_ptr<VisualFX> visual_fx_   = std::make_unique<VisualFX>();
    std::unique_ptr<Input::Camera> camera_ = std::make_unique<Input::Camera>();
    std::unique_ptr<Input::Video> video_   = std::make_unique<Input::Video>();
};

}