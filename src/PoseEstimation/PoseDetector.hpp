#pragma once 

//#include <opencv>

#include "PoseEstimationStructs.hpp"

namespace PoseEstimation {

class PoseDetector 
{
    //Pose get_pose(cv::Mat& image);
public:
    void start();
    int camera_start();


private:
    //std::vector<Keypoint> detect_keypoints(cv::Mat& image);


    std::vector<Pose> poses_;
};
}