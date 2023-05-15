cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME "OpenDance")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FIND_LIB_PREFIX ${CMAKE_SOURCE_DIR}/3rdparty/)
set(OpenCV_DIR ${FIND_LIB_PREFIX}/opencv-4.7.0/build)
set(OPENCV_DLL_DIR ${FIND_LIB_PREFIX}/opencv-4.7.0/build/x64/vc16/bin)

project (${PROJECT_NAME}
	VERSION 0.0.1
	LANGUAGES CXX
)

add_subdirectory(3rdparty/pybind11)
add_subdirectory(src)