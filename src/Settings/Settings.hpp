#pragma once

#include <memory>

#include "Audio.hpp"

namespace Settings {

class Settings {
    Settings();

private:
    std::unique_ptr<Audio> audio_ = std::make_unique<Audio>();
};
}