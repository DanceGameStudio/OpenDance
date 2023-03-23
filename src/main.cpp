#include "GameLogic.hpp"

int main([[maybe_used]] int argc, [[maybe_used]] char** argv)
{
    std::unique_ptr<GameLogic::GameLogic> game = std::make_unique<GameLogic::GameLogic>();
    game->loop();
}