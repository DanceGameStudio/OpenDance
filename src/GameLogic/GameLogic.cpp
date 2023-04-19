#include "GameLogic.hpp"

namespace GameLogic {

GameLogic::GameLogic() 
{
    load_configuration();
}

void GameLogic::loop()
{
    //cv::Mat camera_image = graphics_->camera_->read();
    //cv::Mat video_image = graphics_->video_->read();
    // 
    //PoseEstimation::Pose camera_pose = pose_analyser_->detector_->get_pose(&camera_image);
    //PoseEstimation::Pose video_pose = pose_analyser_->detector_->get_pose(&video_image);
    // 
    //pose_analyser_->compare_poses(camera_pose, video_pose);
}

void GameLogic::load_configuration()
{
	//TODO
}

}