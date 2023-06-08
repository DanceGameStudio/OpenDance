#include "PoseAnalyser.hpp"

namespace PoseEstimation {

float PoseAnalyser::compare_poses(Pose& first_pose, Pose& second_pose)
{
    //const float head_scale = 0.2;
    const float arm_scale = 1.5;
    const float chest_scale = 0.8;
    const float leg_scale = 1.5;

    // Fill the map with all obtainable poses
    initialise_valid_poses(first_pose, second_pose);

    // If we do not have any poses just return 0
    if (cosine_similarities_.size() == 0)
        return 0.f;

    // Compare all obtainable poses
    float result = 0;
    if (cosine_similarities_.count(Poses::POSE_ARMS)) {
        compare_arms(first_pose, second_pose);
        result += cosine_similarities_[Poses::POSE_ARMS] * arm_scale;
    }
    if (cosine_similarities_.count(Poses::POSE_LEGS)) {
        compare_legs(first_pose, second_pose);
        result += cosine_similarities_[Poses::POSE_LEGS] * leg_scale;
    }
    if (cosine_similarities_.count(Poses::POSE_CHEST)) {
        compare_chest(first_pose, second_pose);
        result += cosine_similarities_[Poses::POSE_CHEST] * chest_scale;
    }
    //if (cosine_similarities_.count(Poses::POSE_HEAD)) {
    //    compare_head(first_pose, second_pose);
    //    result += cosine_similarities_[Poses::POSE_HEAD] * head_scale;
    //}

    // Divide the result by the number of obtained poses
    result /= cosine_similarities_.size();

    // Clear the map for the next run
    cosine_similarities_.clear();

    return result;
}

void PoseAnalyser::initialise_valid_poses(Pose& first_pose, Pose& second_pose)
{
    // Check which compares we can actually do and initialise the map accordingly

    // Arm needs 2, 3, 4, 5, 6 and 7
    if (pose_has(first_pose, second_pose, 2) && pose_has(first_pose, second_pose, 3) && pose_has(first_pose, second_pose, 4)
        && pose_has(first_pose, second_pose, 5) && pose_has(first_pose, second_pose, 6) && pose_has(first_pose, second_pose, 7))
        cosine_similarities_.insert(std::make_pair(Poses::POSE_ARMS, 0.f));

    // Leg needs 8, 9, 10, 11, 12 and 13
    if (pose_has(first_pose, second_pose, 8) && pose_has(first_pose, second_pose, 9) && pose_has(first_pose, second_pose, 10)
        && pose_has(first_pose, second_pose, 11) && pose_has(first_pose, second_pose, 12) && pose_has(first_pose, second_pose, 13))
        cosine_similarities_.insert(std::make_pair(Poses::POSE_LEGS, 0.f));

    // Chest needs 1, 2, 5, 8, 11
    if (pose_has(first_pose, second_pose, 1) && pose_has(first_pose, second_pose, 2) && pose_has(first_pose, second_pose, 5)
        && pose_has(first_pose, second_pose, 8) && pose_has(first_pose, second_pose, 11))
        cosine_similarities_.insert(std::make_pair(Poses::POSE_CHEST, 0.f));

    // Head 0, 1, 14, 15, 16 and 17
    if (pose_has(first_pose, second_pose, 0) && pose_has(first_pose, second_pose, 1) && pose_has(first_pose, second_pose, 14)
        && pose_has(first_pose, second_pose, 15) && pose_has(first_pose, second_pose, 16) && pose_has(first_pose, second_pose, 17))
        cosine_similarities_.insert(std::make_pair(Poses::POSE_HEAD, 0.f));
}

void PoseAnalyser::compare_arms(Pose& first_pose, Pose& second_pose)
{
    // Arm Keypoint Vectors are as follows:
    // Left - Upper Arm is 5 to 6 and Lower Arm is 6 to 7
    // Right - Upper Arm is 2 to 3 and Lower Arm is 3 to 4

    float result = 0;

    // Upper Left Arm
    Utility::Math::Vector3 first_upper_left_arm = keypoints_to_vector3(first_pose.keypoints.at(5), first_pose.keypoints.at(6));
    Utility::Math::Vector3 second_upper_left_arm = keypoints_to_vector3(second_pose.keypoints.at(5), second_pose.keypoints.at(6));
    result += Utility::Math::cosine_similarity(first_upper_left_arm, second_upper_left_arm);

    // Lower Left Arm
    Utility::Math::Vector3 first_lower_left_arm = keypoints_to_vector3(first_pose.keypoints.at(6), first_pose.keypoints.at(7));
    Utility::Math::Vector3 second_lower_left_arm = keypoints_to_vector3(second_pose.keypoints.at(6), second_pose.keypoints.at(7));
    result += Utility::Math::cosine_similarity(first_lower_left_arm, second_lower_left_arm);

    // Upper Right Arm
    Utility::Math::Vector3 first_upper_right_arm = keypoints_to_vector3(first_pose.keypoints.at(2), first_pose.keypoints.at(3));
    Utility::Math::Vector3 second_upper_right_arm = keypoints_to_vector3(second_pose.keypoints.at(2), second_pose.keypoints.at(3));
    result += Utility::Math::cosine_similarity(first_upper_right_arm, second_upper_right_arm);

    // Lower Right Arm
    Utility::Math::Vector3 first_lower_right_arm = keypoints_to_vector3(first_pose.keypoints.at(3), first_pose.keypoints.at(4));
    Utility::Math::Vector3 second_lower_right_arm = keypoints_to_vector3(second_pose.keypoints.at(3), second_pose.keypoints.at(4));
    result += Utility::Math::cosine_similarity(first_lower_right_arm, second_lower_right_arm);

    // Divide result by the number of comparisons
    result /= 4;

    cosine_similarities_.at(Poses::POSE_ARMS) = result;
}

void PoseAnalyser::compare_legs(Pose& first_pose, Pose& second_pose)
{
    // Leg Keypoint Vectors are as follows:
    // Left - Upper Leg is 11 to 12 and Lower Leg is 12 to 13
    // Right - Upper Leg is 8 to 9 and Lower Leg is 9 to 10

    float result = 0;

    // Upper Left leg
    Utility::Math::Vector3 first_upper_left_leg = keypoints_to_vector3(first_pose.keypoints.at(11), first_pose.keypoints.at(12));
    Utility::Math::Vector3 second_upper_left_leg = keypoints_to_vector3(second_pose.keypoints.at(11), second_pose.keypoints.at(12));
    result += Utility::Math::cosine_similarity(first_upper_left_leg, second_upper_left_leg);

    // Lower Left leg
    Utility::Math::Vector3 first_lower_left_leg = keypoints_to_vector3(first_pose.keypoints.at(12), first_pose.keypoints.at(13));
    Utility::Math::Vector3 second_lower_left_leg = keypoints_to_vector3(second_pose.keypoints.at(12), second_pose.keypoints.at(13));
    result += Utility::Math::cosine_similarity(first_lower_left_leg, second_lower_left_leg);

    // Upper Right leg
    Utility::Math::Vector3 first_upper_right_leg = keypoints_to_vector3(first_pose.keypoints.at(8), first_pose.keypoints.at(9));
    Utility::Math::Vector3 second_upper_right_leg = keypoints_to_vector3(second_pose.keypoints.at(8), second_pose.keypoints.at(9));
    result += Utility::Math::cosine_similarity(first_upper_right_leg, second_upper_right_leg);

    // Lower Right leg
    Utility::Math::Vector3 first_lower_right_leg = keypoints_to_vector3(first_pose.keypoints.at(9), first_pose.keypoints.at(10));
    Utility::Math::Vector3 second_lower_right_leg = keypoints_to_vector3(second_pose.keypoints.at(9), second_pose.keypoints.at(10));
    result += Utility::Math::cosine_similarity(first_lower_right_leg, second_lower_right_leg);

    // Divide result by the number of comparisons
    result /= 4;

    cosine_similarities_.at(Poses::POSE_LEGS) = result;
}

void PoseAnalyser::compare_chest(Pose& first_pose, Pose& second_pose)
{
    // Chest Keypoint Vectors are as follows:
    // Middle - 1 to 11 and 1 to 8
    // Shoulders - 1 to 5 and 1 to 2

    float result = 0;

    // Middle Left
    Utility::Math::Vector3 first_middle_left = keypoints_to_vector3(first_pose.keypoints.at(1), first_pose.keypoints.at(11));
    Utility::Math::Vector3 second_middle_left = keypoints_to_vector3(second_pose.keypoints.at(1), second_pose.keypoints.at(11));
    result += Utility::Math::cosine_similarity(first_middle_left, second_middle_left);

    // Middle Right
    Utility::Math::Vector3 first_middle_right = keypoints_to_vector3(first_pose.keypoints.at(1), first_pose.keypoints.at(8));
    Utility::Math::Vector3 second_middle_right = keypoints_to_vector3(second_pose.keypoints.at(1), second_pose.keypoints.at(8));
    result += Utility::Math::cosine_similarity(first_middle_right, second_middle_right);

    // Shoulder Left
    Utility::Math::Vector3 first_shoulder_left = keypoints_to_vector3(first_pose.keypoints.at(1), first_pose.keypoints.at(5));
    Utility::Math::Vector3 second_shoulder_left = keypoints_to_vector3(second_pose.keypoints.at(1), second_pose.keypoints.at(5));
    result += Utility::Math::cosine_similarity(first_shoulder_left, second_shoulder_left);

    // Shoulder Right
    Utility::Math::Vector3 first_shoulder_right = keypoints_to_vector3(first_pose.keypoints.at(1), first_pose.keypoints.at(2));
    Utility::Math::Vector3 second_shoulder_right = keypoints_to_vector3(second_pose.keypoints.at(1), second_pose.keypoints.at(2));
    result += Utility::Math::cosine_similarity(first_shoulder_right, second_shoulder_right);

    // Divide result by the number of comparisons
    result /= 4;

    cosine_similarities_.at(Poses::POSE_CHEST) = result;
}

void PoseAnalyser::compare_head(Pose& first_pose, Pose& second_pose)
{
    // Head Keypoint Vectors are as follows:
    // Neck - 1 to 0
    // Eyeline Left - 0 to 15 and 15 to 17
    // Eyeline Right - 0 to 14 and 14 to 16

    float result = 0;

    // Neck
    Utility::Math::Vector3 first_neck = keypoints_to_vector3(first_pose.keypoints.at(1), first_pose.keypoints.at(0));
    Utility::Math::Vector3 second_neck = keypoints_to_vector3(second_pose.keypoints.at(1), second_pose.keypoints.at(0));
    result += Utility::Math::cosine_similarity(first_neck, second_neck);

    // Eyeline Left One
    Utility::Math::Vector3 first_eyeline_left_one = keypoints_to_vector3(first_pose.keypoints.at(0), first_pose.keypoints.at(15));
    Utility::Math::Vector3 second_eyeline_left_one = keypoints_to_vector3(second_pose.keypoints.at(0), second_pose.keypoints.at(15));
    result += Utility::Math::cosine_similarity(first_eyeline_left_one, second_eyeline_left_one);

    // Eyeline Left Two
    Utility::Math::Vector3 first_eyeline_left_two = keypoints_to_vector3(first_pose.keypoints.at(15), first_pose.keypoints.at(17));
    Utility::Math::Vector3 second_eyeline_left_two = keypoints_to_vector3(second_pose.keypoints.at(15), second_pose.keypoints.at(17));
    result += Utility::Math::cosine_similarity(first_eyeline_left_two, second_eyeline_left_two);

    // Eyeline Right One
    Utility::Math::Vector3 first_eyeline_right_one = keypoints_to_vector3(first_pose.keypoints.at(0), first_pose.keypoints.at(14));
    Utility::Math::Vector3 second_eyeline_right_one = keypoints_to_vector3(second_pose.keypoints.at(0), second_pose.keypoints.at(14));
    result += Utility::Math::cosine_similarity(first_eyeline_right_one, second_eyeline_right_one);

    // Eyeline Right Two
    Utility::Math::Vector3 first_eyeline_right_two = keypoints_to_vector3(first_pose.keypoints.at(14), first_pose.keypoints.at(16));
    Utility::Math::Vector3 second_eyeline_right_two = keypoints_to_vector3(second_pose.keypoints.at(14), second_pose.keypoints.at(16));
    result += Utility::Math::cosine_similarity(first_eyeline_right_two, second_eyeline_right_two);

    // Divide result by the number of comparisons
    result /= 5;

    cosine_similarities_.at(Poses::POSE_HEAD) = result;
}

Utility::Math::Vector3 PoseAnalyser::keypoints_to_vector3(Keypoint& start_keypoint, Keypoint& direction_keypoint)
{
    // Compute the vector from start_keypoint to direction_keypoint
    float x = direction_keypoint.x - start_keypoint.x;
    float y = direction_keypoint.y - start_keypoint.y;
    float z = direction_keypoint.z - start_keypoint.z;

    // Return a Vector3 object with the computed x, y, and z values
    return Utility::Math::Vector3(x, y, z);
}

bool PoseAnalyser::pose_has(Pose& first_pose, Pose& second_pose, int index)
{
    bool first_has = index < first_pose.keypoints.size();
    bool second_has = index < second_pose.keypoints.size();
    return first_has && second_has;
}

}