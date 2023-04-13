cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME "OpenDance")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FIND_LIB_PREFIX ${CMAKE_SOURCE_DIR}/3rdparty/)
set(OPENPOSE_INCLUDE_DIRS ${FIND_LIB_PREFIX}/openpose/include)
set(OpenCV_INCLUDE_DIRS ${FIND_LIB_PREFIX}/opencv-4.7.0/build/include)
set(OpenCV_LIB_DIR ${FIND_LIB_PREFIX}/opencv-4.7.0/build/x64/vc16/lib)

project (${PROJECT_NAME}
	VERSION 0.0.1
	LANGUAGES CXX
)

add_subdirectory(src)