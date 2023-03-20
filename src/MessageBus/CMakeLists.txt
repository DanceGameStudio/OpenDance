add_library(MessageBus-lib STATIC
	MessageBus.hpp
	MessageBus.cpp
	MessageBusStructs.hpp
)

target_link_libraries(MessageBus-lib
	PRIVATE Utility-lib
)

target_include_directories(MessageBus-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)