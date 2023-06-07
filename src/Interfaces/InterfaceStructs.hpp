#pragma once 

#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

namespace Interface {

struct Settings {
    int gain = 0;
};

struct Graphics {
    cv::Mat video_image;
    cv::Mat camera_image;
};

struct Player {
    std::string name;
    std::string score;
    std::string timespamp;
};

struct ScoreBoard {
    std::vector<Player> player_list;
};

enum GameStatus {
    Running = 1,
    Paused = 2,
    Stopped = 3
};

}