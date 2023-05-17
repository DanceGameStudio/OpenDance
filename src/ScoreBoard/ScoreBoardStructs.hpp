#include <string>
#include <chrono>

namespace ScoreBoard {

struct Player 
{
    Player(std::chrono::system_clock::time_point time) : timestamp(time) {}
    
    std::string name;
    int score;
    const std::chrono::system_clock::time_point timestamp;
};
}