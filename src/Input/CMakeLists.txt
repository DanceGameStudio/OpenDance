add_library(Input-lib STATIC
	Camera.hpp
	Camera.cpp
	Video.hpp
	Video.cpp 
	Input.cpp
	Input.hpp
)

target_include_directories(Input-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
	${OpenCV_INCLUDE_DIRS}
)