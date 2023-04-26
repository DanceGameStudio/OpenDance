#include <opencv2/core.hpp>
#include "GameLogic.hpp"
#include "MainWindow.cpp"
#include "GuiInterface.hpp"

int main(int argc, char** argv)
{
    Interface::GuiInterface* intf = new Interface::GuiInterface();

    /*
    std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>();
    game->loop();
    start_gui(argc, argv);
    */

    GUI gui(intf);
    gui.run(argc, argv);
}