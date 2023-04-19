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

find_package( OpenCV CONFIG REQUIRED PATHS ${OpenCV_BUILD_DIR})

target_link_directories(Input-lib PUBLIC
    ${OpenCV_LIB_DIRS}
)
target_link_libraries(Input-lib
    ${OpenCV_LIBS}
)
target_include_directories(Input-lib PUBLIC
    ${OpenCV_INCLUDE_DIRS}
)