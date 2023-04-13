#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class Interface {
public:
    void set_settings(const Settings& settings);

    const Settings& getSettings();

    const Graphics& get_graphics();

    const ScoreBoard& get_scoreboard();
};

}