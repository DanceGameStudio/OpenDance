cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME "OpenDance")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (${PROJECT_NAME}
	VERSION 0.0.1
	LANGUAGES CXX
)

add_subdirectory(src)