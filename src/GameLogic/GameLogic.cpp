#include "GameLogic.hpp"
#include "opencv2/highgui.hpp"
#include <filesystem>

namespace GameLogic {

void GameLogic::loop()
{
    // Image Processing
    //cv::Mat camera_image = graphics_->camera_->read();
    cv::Mat video_image;
    cv::Mat camera_image;
    PoseEstimation::Pose camera_pose;
    PoseEstimation::Pose video_pose;
    auto graphics = interface_->get_graphics();

    while (true) {
        camera_image = graphics_->get_camera_image();
        video_image  = graphics_->get_video_image();

        //camera_pose = pose_analyser_->detector_->get_pose(camera_image);
        //video_pose = pose_analyser_->detector_->get_pose(video_image);

        //float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
        //std::cout << "Similarity: " << cosine_similarity << "\n";
        
        // Communication with the gui
        camera_image.copyTo(graphics->camera_image);
        video_image.copyTo(graphics->video_image);
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void GameLogic::load_configuration()
{
    std::filesystem::path current_path = std::filesystem::current_path() / "video" / "Beispiel_01.mp4";
    settings_->set_video_path(current_path.string());
    graphics_->apply_settings(settings_);
}

int GameLogic::calc_score(float similarity)
{
    return std::abs(similarity * 100);
}

}