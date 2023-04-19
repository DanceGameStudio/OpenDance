#include <chrono>
#include "PoseDetector.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

namespace PoseEstimation {

void PoseDetector::start()
{
    std::cout << "TEST PostDetector";
    camera_start();
}

int PoseDetector::camera_start()
{
    cv::VideoCapture cap;
    cap.open(0);

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    while (true) {

        cv::Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Display the resulting frame
        cv::imshow("Frame", frame);

        // Press  ESC on keyboard to exit
        char c = (char)cv::waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    cv::destroyAllWindows();

    return 0;
}




//Pose PoseDetector::get_pose(cv::Mat& image)
//{
//    Pose pose.timestamp = std::chrono::steady_clock::now();
//    pose.keypoints = detect_keypoints(&image);
//    poses_.add(pose);
//    return Pose();
//}

//std::vector<Keypoint> PoseDetector::detect_keypoints(cv::Mat& image)
//{
//    //TODO    
//}

}
