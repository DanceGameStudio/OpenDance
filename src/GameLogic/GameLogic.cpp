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
    auto interface_graphics = interface_->get_graphics();
    int fps = graphics_->get_video_fps();
    ScoreBoard::Player player(std::chrono::system_clock::now());
    int score = 0;

    while (true) {
        auto start_time = std::chrono::high_resolution_clock::now();
        camera_image = graphics_->get_camera_image();
        video_image  = graphics_->get_video_image();
   
        cv::Mat image = graphics_->draw_keypoints_to_image(video_image, video_pose.keypoints);
        camera_image.copyTo(interface_graphics->camera_image);
        video_image.copyTo(interface_graphics->video_image);
 
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        int wait_time = 1000 / fps - time_diff.count();
        if (wait_time > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
        }
        //camera_pose = pose_analyser_->detector_->get_pose(camera_image);

        // Berechne die Dauer in Nanosekunden
        auto startTime = std::chrono::high_resolution_clock::now();

        video_pose = pose_analyser_->detector_->get_pose(video_image);

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();

        // Ausgabe der gemessenen Zeit in Millisekunden
        std::cout << "Verarbeitungszeit: " << duration / 1000000.0 << "ms | " << duration << "ns" << std::endl;
        float cosine_similarity = pose_analyser_->compare_poses(video_pose, video_pose);
        //float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
        std::cout << "Similarity: " << cosine_similarity << "\n";
        player.score = calc_score(cosine_similarity);         
    }
    score_board_->player_list_.push_back(player);
}

void GameLogic::load_configuration()
{
    std::filesystem::path current_path = std::filesystem::current_path() / "video" / "Beispiel_03.mp4";
    settings_->set_video_path(current_path.string());
    graphics_->apply_settings(settings_);
}

int GameLogic::calc_score(float similarity)
{
    return std::abs(similarity * 100);
}

}