set(LIB_NAME "GUI-lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

add_library(${LIB_NAME} STATIC
	MainWindow.cpp
    main.qml
    Interface.hpp
    Interface.cpp        
    InterfaceStructs.hpp
    GameScreen/VideoStreamContent.cpp
    GameScreen/VideoStreamContent.h
    PlayMenu/DancesModel.cpp
    PlayMenu/DancesModel.h
    PlayMenu/DancePreviewView.cpp
    PlayMenu/DancePreviewView.h
    qml.qrc
)

target_include_directories(${LIB_NAME} PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)

target_compile_definitions(${LIB_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${LIB_NAME}
  Qt${QT_VERSION_MAJOR}::Core 
  Qt${QT_VERSION_MAJOR}::Quick 
  Qt${QT_VERSION_MAJOR}::Multimedia 
  Qt${QT_VERSION_MAJOR}::MultimediaWidgets
)
set_target_properties(${LIB_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER opendance.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)