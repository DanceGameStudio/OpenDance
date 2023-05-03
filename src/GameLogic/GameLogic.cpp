#include "GameLogic.hpp"

namespace GameLogic {

void GameLogic::loop()
{
    // Image Processing
    //cv::Mat camera_image = graphics_->camera_->read();
    cv::Mat video_image = graphics_->video_->read();

    cv::Mat camera_image = graphics_test_->video_->read();
    
    PoseEstimation::Pose camera_pose = pose_analyser_->detector_->get_pose(camera_image);
    PoseEstimation::Pose video_pose = pose_analyser_->detector_->get_pose(video_image);
    
    float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
    std::cout << "Similarity: " << cosine_similarity << "\n";

    // Communication with the gui
    auto graphics = interface_->get_graphics();
    graphics->camera_image = camera_image;
    graphics->video_image = video_image;

}

void GameLogic::load_configuration()
{
    std::string video_path = "../video/Beispiel_01.mp4";
    int device_id = 0;
    graphics_->camera_->change_device_id(device_id);
    graphics_->video_->change_video_path(video_path);

    graphics_test_->camera_->change_device_id(device_id);
    graphics_test_->video_->change_video_path(video_path);
}

}