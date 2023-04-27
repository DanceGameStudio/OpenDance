#include <opencv2/core.hpp>
#include "GameLogic.hpp"
#include "MainWindow.cpp"
#include "../Interfaces/GuiInterface.hpp"

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    auto intf = std::make_shared<Interface::GuiInterface>();

    std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>(intf);
    game->loop();

    GUI gui(intf);
    gui.run(argc, argv);

    return 0;
}