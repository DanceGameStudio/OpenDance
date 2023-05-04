add_library(Graphics-lib STATIC
	Graphics.hpp
	Graphics.cpp
	VisualFX.hpp
	VisualFX.cpp
)

target_link_libraries(Graphics-lib
	PUBLIC Input-lib
	PUBLIC Settings-lib
)

target_include_directories(Graphics-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)