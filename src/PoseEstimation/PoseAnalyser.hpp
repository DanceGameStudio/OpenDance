#pragma once

#include <memory>

#include "Math.hpp"
#include "PoseDetector.hpp"

namespace PoseEstimation {

class PoseAnalyser {
public:
    // Compares to poses and returns cosine similarity
    float compare_poses(Pose& first_pose, Pose& second_pose);

    // Enter 0 values to existing poses to mark them as readable
    void initialise_valid_poses(Pose& first_pose, Pose& second_pose);

    float compare_arms(Pose& first_pose, Pose& second_pose);
    float compare_legs(Pose& first_pose, Pose& second_pose);
    float compare_chest(Pose& first_pose, Pose& second_pose);
    float compare_head(Pose& first_pose, Pose& second_pose);

    std::unique_ptr<PoseDetector> detector_ = std::make_unique<PoseDetector>();

private:
    enum Poses {
        POSE_ARMS,
        POSE_LEGS,
        POSE_CHEST,
        POSE_HEAD
    };

    std::map<Poses, float> cosine_similarities_;

    Utility::Math::Vector3 keypoints_to_vector3(Keypoint& start_keypoint, Keypoint& direction_keypoint);
    // This returns true if both poses keypoints contain the given index
    bool pose_has(Pose& first_pose, Pose& second_pose, int index);
};

}