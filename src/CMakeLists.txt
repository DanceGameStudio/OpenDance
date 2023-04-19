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