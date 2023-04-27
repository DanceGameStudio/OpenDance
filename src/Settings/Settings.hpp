#pragma once

#include <memory>
#include <ConfigFile.hpp>

#include "Audio.hpp"

namespace Settings {

class Settings {
   
private:
    std::unique_ptr<Utility::ConfigFile> config_ = std::make_unique<Utility::ConfigFile>();
    std::unique_ptr<Audio> audio_ = std::make_unique<Audio>();
};
}