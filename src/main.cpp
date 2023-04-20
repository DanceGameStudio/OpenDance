#include <opencv2/core.hpp>
#include "GameLogic.hpp"
#include "MainWindow.hpp"
#include <iostream>

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    Interface::Interface* intf = new Interface::Interface();

    /*
    std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>();
    game->loop();
    */

    GUI gui(intf);
    gui.run(argc, argv);
}