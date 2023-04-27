#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class GuiInterface {
public:
    void set_settings(const Settings& settings);

    Settings& get_settings();

    Graphics& get_graphics();

    ScoreBoard& get_scoreboard();

    void set_scoreboard(ScoreBoard& score_board);

    void set_graphics(Graphics& graphics);

    Graphics graphics_;
    Settings settings_;
    ScoreBoard score_board_;
};

}