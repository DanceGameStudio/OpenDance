find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

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
	GameLogic-lib
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470d.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64d.dll
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
     set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64.dll
    )
endif()

foreach(DLL ${OPENCV_DLLS})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${OPENCV_DLLS}
        ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()
