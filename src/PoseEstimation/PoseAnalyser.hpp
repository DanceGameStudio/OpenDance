#pragma once

#include <memory>

#include "PoseDetector.hpp"

namespace PoseEstimation {

class PoseAnalyser 
{
    // Compares to poses and returns cosine similarity
    double compare_poses(Pose& first_pose, Pose& second_pose);

private:
    std::unique_ptr<PoseDetector> detector_ = std::make_unique<PoseDetector>();
};

}