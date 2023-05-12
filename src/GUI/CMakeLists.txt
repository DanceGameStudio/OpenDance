set(LIB_NAME "GUI-lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


qt5_add_resources(RCC_RESOURCES qml.qrc)

add_library(${LIB_NAME} STATIC
	MainWindow.cpp
    InterfaceWrapper.h
    GameScreen/VideoStreamContent.cpp
    GameScreen/VideoStreamContent.h
    PlayMenu/DancesModel.cpp
    PlayMenu/DancesModel.h
    ${RCC_RESOURCES}
)

target_include_directories(${LIB_NAME} PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(${LIB_NAME}
  Interface-lib
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