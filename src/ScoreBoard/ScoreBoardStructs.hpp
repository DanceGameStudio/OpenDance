#include <string>
#include <chrono>

namespace ScoreBoard {

struct Player 
{
    std::string name;
    int score;
    const std::chrono::steady_clock::time_point timestamp;
};
}