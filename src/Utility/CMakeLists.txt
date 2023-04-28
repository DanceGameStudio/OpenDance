add_library(Utility-lib STATIC
	ConfigFile.hpp
	ConfigFile.cpp
	Math.hpp
	Math.cpp
	Utility.hpp
	Utility.cpp
)

target_include_directories(Utility-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)