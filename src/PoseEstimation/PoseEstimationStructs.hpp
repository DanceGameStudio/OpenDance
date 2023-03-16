#include <vector>
#include <chrono>

namespace PoseEstimation {

struct Keypoint 
{
    double x;
    double y;
};

struct Pose 
{
    std::vector<Keypoint> keypoints;
    const std::chrono::steady_clock::time_point timestamp;
};

}