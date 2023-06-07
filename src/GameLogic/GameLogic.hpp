#pragma once

#include "Graphics.hpp"
#include "PoseAnalyser.hpp"
#include "ScoreBoard.hpp"
#include "Settings.hpp"
#include "../Interfaces/GuiInterface.hpp"
#include "../Interfaces/InterfaceStructs.hpp"

namespace GameLogic {

class GameLogic
{
public:
    GameLogic(std::shared_ptr<Interface::GuiInterface> gui_interface)
        : interface_(gui_interface) {

        load_configuration();
    };

   ~GameLogic();

    void loop();

private:
    void load_configuration();

    int calc_score(float similarity);

    std::shared_ptr<Interface::GuiInterface> interface_;
    std::unique_ptr<Graphics::Graphics> graphics_                = std::make_unique<Graphics::Graphics>();
    std::unique_ptr<PoseEstimation::PoseAnalyser> pose_analyser_ = std::make_unique<PoseEstimation::PoseAnalyser>();
    std::unique_ptr<ScoreBoard::ScoreBoard> score_board_         = std::make_unique<ScoreBoard::ScoreBoard>();
    std::unique_ptr<Settings::Settings> settings_                = std::make_unique<Settings::Settings>();
    std::unique_ptr<Utility::ConfigFile> config_                 = std::make_unique<Utility::ConfigFile>();
};

}