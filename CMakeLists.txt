cmake_minimum_required (VERSION 3.8)

# Integrate Vcpgk
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project ("OpenDance")

add_subdirectory ("GUI")
add_subdirectory ("GameLogic")
add_subdirectory ("Graphics")
add_subdirectory ("MessageBus")
add_subdirectory ("PoseEstimation")
add_subdirectory ("ScoreBoard")
add_subdirectory ("Settings")


