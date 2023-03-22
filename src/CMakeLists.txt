add_subdirectory(Utility)

add_subdirectory(GameLogic)
add_subdirectory(Graphics)
add_subdirectory(Input)
add_subdirectory(MessageBus)
add_subdirectory(PoseEstimation)
add_subdirectory(ScoreBoard)
add_subdirectory(Settings)

add_executable(${PROJECT_NAME}
	main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	GameLogic-lib
)