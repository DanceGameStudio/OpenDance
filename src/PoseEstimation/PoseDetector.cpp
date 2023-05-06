#include <chrono>
#include "PoseDetector.hpp"

namespace PoseEstimation {

PoseDetector::PoseDetector()
{
    configureWrapper(op_wrapper_);
    op_wrapper_.start();
}

Pose PoseDetector::get_pose(const cv::Mat& image)
{
    Pose pose;
    pose.timestamp = std::chrono::steady_clock::now();
    pose.keypoints = detect_keypoints(image);
    poses_.push_back(pose);
    return pose;
}

std::vector<Keypoint> PoseDetector::detect_keypoints(const cv::Mat& image)
{
    auto datumProcessed = op_wrapper_.emplaceAndPop(OP_CV2OPCONSTMAT(image));

    std::vector<Keypoint> de_keypoints;

    if (datumProcessed != nullptr) {
    }
    // for (auto pose_keypoint : datumProcessed->at(0)->poseKeypoints) {
    //     //de_keypoints.push_back(pose_keypoint);
    //     //Keypoint keypoint(pose_keypoint)
    // }
    return de_keypoints;
}

void PoseDetector::configureWrapper(op::Wrapper& opWrapper)
{
    try {
        // Configuring OpenPose
        // logging_level
        op::ConfigureLog::setPriorityThreshold(op::Priority::Normal);
        op::Profiler::setDefaultX(1000);

        // Applying user defined configuration - GFlags to program variables
        // outputSize
        const auto outputSize = op::flagsToPoint("-1x-1");
        // netInputSize
        const auto netInputSize = op::flagsToPoint("-1x368");
        // faceNetInputSize
        const auto faceNetInputSize = op::flagsToPoint("368x368 (multiples of 16)");
        // handNetInputSize
        const auto handNetInputSize = op::flagsToPoint("368x368 (multiples of 16)");
        // poseMode
        const auto poseMode = op::flagsToPoseMode(1);
        // poseModel
        const auto poseModel = op::flagsToPoseModel(op::String("COCO"));

        // keypointScaleMode
        const auto keypointScaleMode = op::flagsToScaleMode(0);
        // heatmaps to add
        const auto heatMapTypes = op::flagsToHeatMaps(false, false,
            false);
        const auto heatMapScaleMode = op::flagsToHeatMapScaleMode(2);
        // >1 camera view?
        const auto multipleView = false;
        // Face and hand detectors
        const auto faceDetector = op::flagsToDetector(0);
        const auto handDetector = op::flagsToDetector(0);
        // Enabling Google Logging
        const bool enableGoogleLogging = true;

        // Pose configuration (use WrapperStructPose{} for default and recommended configuration)
        const op::WrapperStructPose wrapper_struct_pose {};

        // TODO IMPLEMENT PROPER MODEL PATHS!!!

        opWrapper.configure(wrapper_struct_pose);
        // Face configuration (use op::WrapperStructFace{} to disable it)
        const op::WrapperStructFace wrapperStructFace {};
        opWrapper.configure(wrapperStructFace);
        // Hand configuration (use op::WrapperStructHand{} to disable it)
        const op::WrapperStructHand wrapperStructHand {};
        opWrapper.configure(wrapperStructHand);
        // Extra functionality configuration (use op::WrapperStructExtra{} to disable it)
        const op::WrapperStructExtra wrapperStructExtra {};
        opWrapper.configure(wrapperStructExtra);
        // Output (comment or use default argument to disable any output)
        const op::WrapperStructOutput wrapperStructOutput {};
        opWrapper.configure(wrapperStructOutput);
    } catch (const std::exception& e) {
        std::cerr << "OpenPose failed to load Wrapper." << std::endl;
    }
}
}