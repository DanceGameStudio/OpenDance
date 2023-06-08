#include "GameLogic.hpp"
#include "opencv2/highgui.hpp"
#include <filesystem>

namespace GameLogic {

void GameLogic::loop()
{
    auto interface_graphics = interface_->get_graphics();
    ScoreBoard::Player player(std::chrono::system_clock::now());

    cv::Mat video_image;
    cv::Mat camera_image;

    PoseEstimation::Pose camera_pose;
    PoseEstimation::Pose video_pose;

    int fps = graphics_->get_video_fps();
    if (fps == 0) {
        fps = 60;
    }

    int score = 0;
    int image_count = 0;
    int image_processing_interval = 1;

    bool run_image_proccesing = false;
    bool run_game = true;

    while (run_game) {
        if (interface_->get_settings_changed()) {
            std::string video_path = interface_->get_videoPath();
            settings_->set_video_path(video_path);
            graphics_->apply_settings(settings_);
            interface_->set_score(0);
            score = 0;
            interface_->set_settings_changed(false);
            std::cout << "Neuer Videopfad: " << video_path << std::endl;
        } else if (interface_->get_game_status() == Interface::Running) {
            run_image_proccesing = true;
            image_count = 0;
            interface_->set_score(score);
            std::cout << "Auswertung startet..." << std::endl;
        }
        while (run_image_proccesing) {
            auto start_time = std::chrono::high_resolution_clock::now();

            if (interface_->get_game_status() != Interface::Running) {
                run_image_proccesing = false;
                break;
            }

            int fps = graphics_->get_video_fps();
            if (fps == 0) {
                fps = 60;
            }

            camera_image = graphics_->get_video_image();
            video_image = graphics_->get_video_image();

            // Image processing
            if (image_count != 0 && image_processing_interval != 0) {
                if (image_count % image_processing_interval == 0) {
                    auto pose_start = std::chrono::high_resolution_clock::now();
                    video_pose = pose_analyser_->detector_->get_pose(video_image);
                    camera_pose = pose_analyser_->detector_->get_pose(camera_image);
                    auto pose_end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(pose_end - pose_start).count();
                    cv::Mat image_with_landmarks = graphics_->draw_keypoints_to_image(camera_image, camera_pose.keypoints);
                    image_with_landmarks.copyTo(interface_graphics->camera_image);
                    std::cout << "Verarbeitungszeit: " << duration / 1000000.0 << "ms | " << duration << "ns" << std::endl;

                    // Calc score from similarity
                    float cosine_similarity = pose_analyser_->compare_poses(camera_pose, video_pose);
                    score += calc_score(cosine_similarity);
                    std::cout << "Similarity: " << cosine_similarity << " Score: " << score << "\n";
                    interface_->set_score(score);
                }
            } else {
                camera_image.copyTo(interface_graphics->camera_image);
            }
            video_image.copyTo(interface_graphics->video_image);
            image_count++;

            // Limit loop to max fps
            auto end_time = std::chrono::high_resolution_clock::now();
            auto time_diff = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            int wait_time = 1000 / fps - time_diff.count();
            double real_fps = 1000.0 / time_diff.count();
            std::cout << "FPS: " << real_fps << std::endl;
            if (wait_time > 0) {
                std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
            }
        }
    }
}

GameLogic::~GameLogic()
{
    // On destruction of game logic write the last used values to the config cache
    config_->set_value(Utility::ConfigFile::ConfigIndex("video", "path"), interface_->get_videoPath());
}

void GameLogic::load_configuration()
{
    std::filesystem::path config_path = std::filesystem::current_path() / "config.ini";
    config_->set_path(config_path.string());
    config_->read_config();

    std::string video_path = config_->get_value(Utility::ConfigFile::ConfigIndex("video", "path"), std::string("Beispiel_01.mp4"));
    settings_->set_video_path(std::filesystem::current_path().string() + video_path);
    settings_->set_camera_id(config_->get_value(Utility::ConfigFile::ConfigIndex("input", "camera"), 0.0));
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

    // const float scale = 5;
    // float scaled_score = std::pow(similarity * scale, 2);

    // return std::abs(scaled_score);
    return score;
}

}
