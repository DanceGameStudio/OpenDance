#include <opencv2/core.hpp>
#include "GameLogic.hpp"
#include "MainWindow.cpp"
#include "../Interfaces/GuiInterface.hpp"
#include <thread>

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    auto intf = std::make_shared<Interface::GuiInterface>();

    std::thread thrd_game([&]() {
        std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>(intf);
        while (true) {
            game->loop();
        }
    });
    
    std::thread thrd_gui([&]() {
        GUI gui(intf);
        gui.run(argc, argv);
    });

    thrd_game.join();
    thrd_gui.join();

    return 0;
}