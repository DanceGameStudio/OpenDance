add_library(PoseEstimation-lib STATIC
	PoseAnalyser.hpp
	PoseAnalyser.cpp
	PoseDetector.hpp
	PoseDetector.cpp
	PoseEstimationStructs.hpp
)

target_link_libraries(PoseEstimation-lib
	PRIVATE Utility-lib
	pybind11::module
	pybind11::embed
	pybind11::pybind11
	pybind11::headers
)

target_include_directories(PoseEstimation-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
	${OpenCV_INCLUDE_DIRS}
)