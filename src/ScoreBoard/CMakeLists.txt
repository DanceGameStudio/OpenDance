add_library(ScoreBoard-lib STATIC
	ScoreBoard.hpp
	ScoreBoard.cpp
	ScoreBoardStructs.hpp
)

target_include_directories(ScoreBoard-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)