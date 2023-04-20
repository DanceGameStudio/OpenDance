add_library(GameLogic-lib STATIC
	GameLogic.hpp
	GameLogic.cpp
)

target_link_libraries(GameLogic-lib
	PUBLIC Interface-lib
	PUBLIC Utility-lib
	PUBLIC Graphics-lib
	PUBLIC Input-lib
	PUBLIC PoseEstimation-lib
	PUBLIC ScoreBoard-lib
	PUBLIC Settings-lib
)

target_include_directories(GameLogic-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)