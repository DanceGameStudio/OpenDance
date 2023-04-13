#pragma once

#include <memory>
#include "VisualFX.hpp"
#include "Camera.hpp"
#include "Video.hpp"

namespace Graphics {

class Graphics 
{

private:
    std::unique_ptr<VisualFX> visual_fx_   = std::make_unique<VisualFX>();
    std::unique_ptr<Input::Camera> camera_ = std::make_unique<Input::Camera>();
    std::unique_ptr<Input::Video> video_   = std::make_unique<Input::Video>();
};

}