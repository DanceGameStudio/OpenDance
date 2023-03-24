#include <string>
#include <chrono>

namespace ScoreBoard {

struct Player 
{
    std::string name;
    double score;
    const std::chrono::steady_clock::time_point timestamp;
};
}