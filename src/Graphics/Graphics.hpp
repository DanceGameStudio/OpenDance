#pragma once

#include <memory>
#include "VisualFX.hpp"

namespace Graphics {

class Graphics 
{

private:
	//cv::Mat camera_image_
	//cv::Mat video_image_
    std::unique_ptr<VisualFX> visual_fx_ = std::make_unique<VisualFX>();
};

}