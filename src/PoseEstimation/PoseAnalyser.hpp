#pragma once

#include <memory>

#include "Math.hpp"
#include "PoseDetector.hpp"

namespace PoseEstimation {

class PoseAnalyser {
    // Compares to poses and returns cosine similarity
    float compare_poses(Pose& first_pose, Pose& second_pose);

    float compare_arms(Pose& first_pose, Pose& second_pose);
    float compare_legs(Pose& first_pose, Pose& second_pose);
    float compare_chest(Pose& first_pose, Pose& second_pose);
    float compare_head(Pose& first_pose, Pose& second_pose);

private:
    Utility::Math::Vector3 keypoints_to_vector3(Keypoint& start_keypoint, Keypoint& direction_keypoint);
    std::unique_ptr<PoseDetector> detector_ = std::make_unique<PoseDetector>();
};

}
