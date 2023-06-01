#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class GuiInterface {
private:
    GameStatus game_status_;
    int score_ = 0;

public:
    GuiInterface()
    {
        game_status_ = Paused;
    }

    Settings& get_settings();
    std::shared_ptr<Graphics> get_graphics();
    ScoreBoard& get_scoreboard();
    GameStatus get_game_status() const;
    int get_score();

    void set_score(int score);
    void set_settings(const Settings& settings);
    void set_scoreboard(ScoreBoard& score_board);
    void set_graphics(Graphics& graphics);
    void set_game_status(GameStatus status);

    std::shared_ptr<Graphics> graphics_ = std::make_shared<Interface::Graphics>();
    Settings settings_;
    ScoreBoard score_board_;
};

}