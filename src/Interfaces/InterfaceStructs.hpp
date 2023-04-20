#pragma once 

#include <string>
#include <vector>

namespace Interface {

struct Settings {
    int gain = 0;
};

struct Graphics {
    // cv::Mat video_image;
    // cv::Mat camera_image;
};

struct Player {
    std::string name;
    std::string score;
    std::string timespamp;
};

struct ScoreBoard {
    std::vector<Player> player_list;
};

}