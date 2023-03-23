#pragma once

#include "Graphics.hpp"
#include "PoseAnalyser.hpp"
#include "ScoreBoard.hpp"
#include "Settings.hpp"

namespace GameLogic {

class GameLogic
{
public:
    GameLogic();
    void loop();

private:
    void load_configuration();

    std::unique_ptr<Graphics::Graphics> graphics_                = std::make_unique<Graphics::Graphics>();
    std::unique_ptr<PoseEstimation::PoseAnalyser> pose_analyser_ = std::make_unique<PoseEstimation::PoseAnalyser>();
    std::unique_ptr<ScoreBoard::ScoreBoard> score_board_         = std::make_unique<ScoreBoard::ScoreBoard>();
    std::unique_ptr<Settings::Settings> settings_                = std::make_unique<Settings::Settings>();
};

}