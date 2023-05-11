#include <chrono>
#include <openpose/wrapper/enumClasses.hpp>
#include "PoseDetector.hpp"

namespace PoseEstimation {

PoseDetector::PoseDetector()
{
    configureWrapper(op_wrapper_);
    if (wrapper_configured_) {
        op_wrapper_.start();
    }
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
    std::vector<Keypoint> detected_keypoints;
    if (wrapper_configured_) {
        auto datumProcessed = op_wrapper_.emplaceAndPop(OP_CV2OPCONSTMAT(image));
        if (datumProcessed != nullptr && !datumProcessed->empty()) {
            op::Array<float> keypoints = datumProcessed->at(0)->poseKeypoints;
            int coco_keypoint_size = 18;
            // Berwertung nur für Person 0 und 2D
            try {
                for (int i = 0; i < coco_keypoint_size; i++) {
                    Keypoint point = { keypoints[0, i, 0], keypoints[0, i, 1], 0 };
                    detected_keypoints.push_back(point);
                }
            } catch (...) {
                std::cout << "Keypoint Array broken!" << std::endl;
            }
        }
    }
    return detected_keypoints;
}

void PoseDetector::configureWrapper(op::Wrapper& opWrapper)
{
    try {
        // Configuring OpenPose
        // logging_level
        op::ConfigureLog::setPriorityThreshold(op::Priority::Normal);
        op::Profiler::setDefaultX(1000);

        // Pose configuration (use WrapperStructPose{} for default and recommended configuration)
        op::WrapperStructPose wrapper_struct_pose;
        wrapper_struct_pose.poseModel = op::PoseModel::COCO_18;
        wrapper_struct_pose.numberPeopleMax = 1;
        wrapper_struct_pose.modelFolder = "models/";
        wrapper_struct_pose.protoTxtPath = "pose_deploy_linevec.prototxt";
        wrapper_struct_pose.caffeModelPath = "pose_iter_440000.caffemodel";

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
        wrapper_configured_ = true;
    } catch (const std::exception& e) {
        wrapper_configured_ = false;
        std::cerr << "OpenPose failed to load Wrapper. Exception: " << e.what() << std::endl;
    }
}
}