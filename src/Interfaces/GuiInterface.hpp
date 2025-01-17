#pragma once

#include "InterfaceStructs.hpp"

namespace Interface {

class GuiInterface {
private:
    GameStatus game_status_;
    int score_ = 0;
    std::string videoPath_;
    bool settings_changed_ = false;

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
    bool get_settings_changed();

    void set_score(int score);
    void set_settings(const Settings& settings);
    void set_scoreboard(ScoreBoard& score_board);
    void set_graphics(Graphics& graphics);
    void set_game_status(GameStatus status);

    std::string get_videoPath() { return videoPath_; }
    void set_videoPath(std::string path) {
        videoPath_ = path;
        settings_changed_ = true;
    }

    void set_settings_changed(bool changed) {
        settings_changed_ = changed;
    }

    std::shared_ptr<Graphics> graphics_ = std::make_shared<Interface::Graphics>();
    Settings settings_;
    ScoreBoard score_board_;
};

}