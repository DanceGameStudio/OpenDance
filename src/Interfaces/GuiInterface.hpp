#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class GuiInterface {
public:
    void set_settings(const Settings& settings);

    const Settings& get_settings();

    const Graphics& get_graphics();

    const ScoreBoard& get_scoreboard();
};

}