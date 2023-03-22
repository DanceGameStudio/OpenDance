add_library(Graphics-lib STATIC
	Graphics.hpp
	Graphics.cpp
	VisualFX.hpp
	VisualFX.cpp
)

target_include_directories(Graphics-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)