#include "GuiInterface.hpp"

namespace Interface {

std::shared_ptr<Graphics> GuiInterface::get_graphics()
{
    return graphics_;
}

void GuiInterface::set_graphics(Graphics& graphics)
{
    *graphics_ = graphics;
}

Settings& GuiInterface::get_settings()
{
    return settings_;
}

void GuiInterface::set_settings(const Settings& settings)
{
    settings_ = settings;
}

ScoreBoard& GuiInterface::get_scoreboard()
{
    return score_board_;
}

void GuiInterface::set_scoreboard(ScoreBoard& score_board)
{
    score_board_ = score_board;
}

void GuiInterface::set_game_status(GameStatus status)
{
    game_status_ = status;
}

int GuiInterface::get_score() 
{
    return score_;
}

void GuiInterface::set_score(int score)
{
    score_ = score;
}

GameStatus GuiInterface::get_game_status() const
{
    return game_status_;
}

bool GuiInterface::get_settings_changed()
{
    return settings_changed_;
}

}