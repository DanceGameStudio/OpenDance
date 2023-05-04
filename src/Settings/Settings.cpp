#include "Settings.hpp"

namespace Settings {

int Settings::get_camera_id()
{
    return camera_device_id_;
}

std::string& Settings::get_video_path()
{
    return video_path_;
}

void Settings::set_camera_id(int id)
{
    camera_device_id_ = id;
}

void Settings::set_video_path(std::string path)
{
    video_path_ = path;
}
}