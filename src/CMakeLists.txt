find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(Interfaces)
add_subdirectory(Utility)
add_subdirectory(GameLogic)
add_subdirectory(Graphics)
add_subdirectory(GUI)
add_subdirectory(Input)
add_subdirectory(PoseEstimation)
add_subdirectory(ScoreBoard)
add_subdirectory(Settings)

add_executable(${PROJECT_NAME}
	main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${OpenCV_LIBS}
    ${OPENPOSE_LIB_DIR}/openpose.lib
    ${OPENPOSE_LIB_DIR}/openposed.lib
	GameLogic-lib
    PUBLIC Interface-lib
    PUBLIC GUI-lib
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470d.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64d.dll
    )
    set(OPENPOSE_DLLS
        ${OPENPOSE_DLL_DIR}
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64.dll
    )
    set(OPENPOSE_DLLS
        ${OPENPOSE_DLL_DIR}
    )
    set(OPENPOSE_CPU_LIB
        ${FIND_LIB_PREFIX}/openpose/cpu_only/openpose.lib
    )
endif()

# Copy OpenCV DLLs
foreach(DLL ${OPENCV_DLLS})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${OPENCV_DLLS}
        ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()

# Copy OpenPose DLLs
foreach(DLL ${OPENPOSE_DLLS})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${OPENPOSE_DLLS}
        ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()

# Copy Videos
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/video
        ${CMAKE_CURRENT_BINARY_DIR}/video
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${FIND_LIB_PREFIX}/openpose/models/pose/coco
        ${CMAKE_CURRENT_BINARY_DIR}/models
)