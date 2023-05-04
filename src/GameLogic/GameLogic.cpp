#include "GameLogic.hpp"
#include "opencv2/highgui.hpp"

namespace GameLogic {

void GameLogic::loop()
{
    // Image Processing
    //cv::Mat camera_image = graphics_->camera_->read();
    graphics_->video_->start();
    graphics_test_->video_->start();

    while (true) {
        cv::Mat video_image = graphics_->video_->get_image();
        cv::Mat camera_image = graphics_test_->video_->get_image();

        PoseEstimation::Pose camera_pose = pose_analyser_->detector_->get_pose(camera_image);
        PoseEstimation::Pose video_pose = pose_analyser_->detector_->get_pose(video_image);

        float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
        std::cout << "Similarity: " << cosine_similarity << "\n";

        // Communication with the gui
        Interface::Graphics graphics = Interface::Graphics();
        graphics.video_image = video_image;
        graphics.camera_image = camera_image;
        interface_->set_graphics(graphics);
    }

    graphics_->video_->stop();
    graphics_test_->video_->stop();
}

void GameLogic::load_configuration()
{
    std::string video_path = "C:/Users/Munir/source/repos/DanceGameStudio/OpenDanceCPP/video/Beispiel_01.mp4";
    int device_id = 0;
    graphics_->camera_->change_device_id(device_id);
    graphics_->video_->change_video_path(video_path);

    graphics_test_->camera_->change_device_id(device_id);
    graphics_test_->video_->change_video_path(video_path);
}

}