#include <opencv2/core.hpp>
#include "GameLogic.hpp"
#include "MainWindow.cpp"
#include "GuiInterface.hpp"

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    Interface::GuiInterface gui_interface;
    std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>();   
    game->loop();
    */

    GUI gui(intf);
    gui.run(argc, argv);
}