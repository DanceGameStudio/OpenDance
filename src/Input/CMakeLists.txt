add_library(Input-lib STATIC
	Camera.hpp
	Camera.cpp
)

target_include_directories(Input-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)