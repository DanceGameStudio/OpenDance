add_library(GameLogic-lib STATIC
	GameLogic.hpp
	GameLogic.cpp
)

target_link_libraries(GameLogic-lib
	PUBLIC Utility-lib
	PRIVATE MessageBus-lib
)

target_include_directories(GameLogic-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)