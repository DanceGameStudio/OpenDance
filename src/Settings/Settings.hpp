#pragma once

#include <memory>
#include <ConfigFile.hpp>

#include "Audio.hpp"

namespace Settings {

class Settings {
public:
    int get_camera_id();

    std::string& get_video_path();

    void set_camera_id(int id);

    void set_video_path(std::string path);

private:
    std::unique_ptr<Utility::ConfigFile> config_ = std::make_unique<Utility::ConfigFile>();
    std::unique_ptr<Audio> audio_ = std::make_unique<Audio>();

    std::string video_path_;
    int camera_device_id_ = 0;
};
}