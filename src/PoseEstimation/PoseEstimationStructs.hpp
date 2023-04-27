#include <chrono>
#include <vector>

namespace PoseEstimation {

struct Keypoint {
    float x;
    float y;
    float z;
};

struct Pose {
    std::vector<Keypoint> keypoints;
    std::chrono::steady_clock::time_point timestamp;
};

}
