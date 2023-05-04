#include "../Interfaces/GuiInterface.hpp"
#include "GameLogic.hpp"
#include "MainWindow.cpp"
#include <opencv2/core.hpp>
#include <thread>

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    auto gui_interface = std::make_shared<Interface::GuiInterface>();

    bool stopGame = false;

    std::thread thrd_game([&]() {
        std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>(intf);
        game->loop();
    });

    std::thread thrd_gui([&]() {
        std::unique_ptr<GUI> gui = std::make_unique<GUI>(gui_interface);
        gui->run(argc, argv);
        stopGame = true;
    });

    thrd_gui.join();
    thrd_game.join();

    return 0;
}