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
    bool run_image_proccesing = false;
    bool run_game = true;

    while (run_game) {
        if (interface_->get_settings_changed()) {
            settings_->set_video_path(interface_->get_videoPath());
            graphics_->apply_settings(settings_);
            interface_->set_score(0);
        } else if (interface_->get_game_status() == Interface::Running) {
            run_image_proccesing = true;
            interface_->set_score(score);
        }
        while (run_image_proccesing) {
            if (interface_->get_game_status() != Interface::Running) {
                run_image_proccesing = false;
                break;
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            camera_image = graphics_->get_camera_image();
            video_image = graphics_->get_video_image();

            auto pose_start = std::chrono::high_resolution_clock::now();
            video_pose = pose_analyser_->detector_->get_pose(video_image);
            camera_pose = pose_analyser_->detector_->get_pose(camera_image);
            auto pose_end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(pose_end - pose_start).count();
            
            cv::Mat image_with_landmarks = graphics_->draw_keypoints_to_image(camera_image, camera_pose.keypoints);
            image_with_landmarks.copyTo(interface_graphics->camera_image);
            video_image.copyTo(interface_graphics->video_image);

            auto end_time = std::chrono::high_resolution_clock::now();
            auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            int wait_time = 1000 / fps - time_diff.count();
            if (wait_time > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
            }

            // Ausgabe der gemessenen Zeit in Millisekunden
            std::cout << "Verarbeitungszeit: " << duration / 1000000.0 << "ms | " << duration << "ns" << std::endl;
            float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
            score += calc_score(cosine_similarity);
            std::cout << "Similarity: " << cosine_similarity << " Score: " << score << "\n";
            interface_->set_score(score);
        }
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
    int score = 0;
    if (similarity < 0.7f) {
        return score;
    } else if (similarity <= 0.8f) {
        score = 1;
    } else if (similarity <= 0.9f) {
        score = 2;
    } else if (similarity > 0.9f) {
        score = 5;
    }

    //const float scale = 5;
    //float scaled_score = std::pow(similarity * scale, 2); 

    //return std::abs(scaled_score);
    return score;
}

}