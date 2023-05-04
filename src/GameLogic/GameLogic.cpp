#include "GameLogic.hpp"
#include "opencv2/highgui.hpp"

namespace GameLogic {

void GameLogic::loop()
{
    // Image Processing
    //cv::Mat camera_image = graphics_->camera_->read();
    cv::Mat video_image;
    cv::Mat camera_image;
    PoseEstimation::Pose camera_pose;
    PoseEstimation::Pose video_pose;
    ScoreBoard::Player player;
    player.name = "Tim";
    score_board_->player_list_.push_back(player);
    auto graphics = interface_->get_graphics();
    auto scoreboard = interface_->get_scoreboard();

    while (true) {
        camera_image = graphics_->get_camera_image();
        video_image  = graphics_->get_video_image();

        camera_pose = pose_analyser_->detector_->get_pose(camera_image);
        video_pose = pose_analyser_->detector_->get_pose(video_image);

        float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
        std::cout << "Similarity: " << cosine_similarity << "\n";
        
        score_board_->player_list_.at(0).score = calc_score(cosine_similarity);

        // Communication with the gui
        camera_image.copyTo(graphics->camera_image);
        video_image.copyTo(graphics->video_image);
    }
}

void GameLogic::load_configuration()
{
    settings_->set_video_path("C:/Users/Munir/source/repos/DanceGameStudio/OpenDance/video/Beispiel_02.mp4");
    graphics_->apply_settings(settings_);
}

int GameLogic::calc_score(float similarity)
{
    return std::abs(similarity * 100);
}

}