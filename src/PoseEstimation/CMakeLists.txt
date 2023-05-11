add_library(PoseEstimation-lib STATIC
	PoseAnalyser.hpp
	PoseAnalyser.cpp
	PoseDetector.hpp
	PoseDetector.cpp
	PoseEstimationStructs.hpp
)

target_link_libraries(PoseEstimation-lib
	PRIVATE Utility-lib
)

target_include_directories(PoseEstimation-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
	${OpenCV_INCLUDE_DIRS}
	${OPENPOSE_INCLUDE_DIRS}
	${OPENPOSE_CPU_LIB}
)