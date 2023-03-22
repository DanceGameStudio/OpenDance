add_library(Settings-lib STATIC
	Settings.hpp
	Settings.cpp
	Audio.hpp
	Audio.cpp
)

target_include_directories(Settings-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)