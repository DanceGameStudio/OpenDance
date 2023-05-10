#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class GuiInterface {
private:
    GameStatus game_status_;

public:
    GuiInterface()
    {
        game_status_ = Paused;
    }

    void set_settings(const Settings& settings);

    Settings& get_settings();

    std::shared_ptr<Graphics> get_graphics();

    ScoreBoard& get_scoreboard();

    void set_scoreboard(ScoreBoard& score_board);

    void set_graphics(Graphics& graphics);

    std::shared_ptr<Graphics> graphics_ = std::make_shared<Interface::Graphics>();
    Settings settings_;
    ScoreBoard score_board_;

    void set_game_status(GameStatus status);
    GameStatus get_game_status() const;
};

}