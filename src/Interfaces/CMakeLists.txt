add_library(Interface-lib STATIC
	GuiInterface.hpp
	GUiInterface.cpp
	InterfaceStructs.hpp
)

target_include_directories(Interface-lib PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)