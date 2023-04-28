#include "GameLogic.hpp"

namespace GameLogic {

void GameLogic::loop()
{
    cv::Mat camera_image = graphics_->camera_->read();
    //cv::Mat video_image = graphics_->video_->read();
    //
    //PoseEstimation::Pose camera_pose = pose_analyser_->detector_->get_pose(&camera_pose);
    //PoseEstimation::Pose video_pose = pose_analyser_->detector_->get_pose(&video_image);
    // 
    //pose_analyser_->compare_poses(camera_pose, video_pose);
    Interface::Graphics graphics = Interface::Graphics();
    graphics.camera_image = camera_image;
    interface_->set_graphics(graphics);
}

void GameLogic::load_configuration()
{
    std::string video_path = "";
    int device_id = 0;
    graphics_->camera_->change_device_id(device_id);
    graphics_->video_->change_video_path(video_path);
}

}