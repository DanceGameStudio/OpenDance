find_package(OpenCV REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(Interfaces)
add_subdirectory(Utility)
add_subdirectory(GameLogic)
add_subdirectory(Graphics)
add_subdirectory(GUI)
add_subdirectory(Input)
add_subdirectory(PoseEstimation)
add_subdirectory(ScoreBoard)
add_subdirectory(Settings)

add_executable(${PROJECT_NAME}
	main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	${OpenCV_LIBS}
	GameLogic-lib
    PUBLIC Interface-lib
    PUBLIC GUI-lib
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470d.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64d.dll
    )
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
     set(OPENCV_DLLS 
        ${OPENCV_DLL_DIR}/opencv_world470.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_ffmpeg470_64.dll
        ${OPENCV_DLL_DIR}/opencv_videoio_msmf470_64.dll
    )

    if(Qt5_FOUND AND WIN32 AND TARGET Qt5::qmake AND NOT TARGET Qt5::windeployqt)
        get_target_property(_qt5_qmake_location Qt5::qmake IMPORTED_LOCATION)

        execute_process(
            COMMAND "${_qt5_qmake_location}" -query QT_INSTALL_PREFIX
            RESULT_VARIABLE return_code
            OUTPUT_VARIABLE qt5_install_prefix
            OUTPUT_STRIP_TRAILING_WHITESPACE
        )

        set(imported_location "${qt5_install_prefix}/bin/windeployqt.exe")

        if(EXISTS ${imported_location})
            add_executable(Qt5::windeployqt IMPORTED)

            set_target_properties(Qt5::windeployqt PROPERTIES
                IMPORTED_LOCATION ${imported_location}
            )
        endif()
    endif()
    if(TARGET Qt5::windeployqt)
    add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_CURRENT_BINARY_DIR}/windeployqt"
        COMMAND set PATH=%PATH%$<SEMICOLON>${qt5_install_prefix}/bin
        COMMAND Qt5::windeployqt --dir "${CMAKE_CURRENT_BINARY_DIR}/" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
    )
    install(
        DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/windeployqt/"
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
    )

    #Deploy Qt
    set(WINDEPLOYQT_EXECUTABLE "${Qt5_DIR}/bin/windeployqt.exe")
    set(TARGET_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin")

    add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E env PATH="${Qt5_DIR}/bin;$ENV{PATH}" ${WINDEPLOYQT_EXECUTABLE} 
        --no-compiler-runtime --no-opengl-sw --no-angle --no-system-d3d-compiler --no-translations --verbose 2
        --dir ${CMAKE_CURRENT_BINARY_DIR} $<TARGET_FILE:${PROJECT_NAME}>
        COMMENT "Deploying Qt..."
    )
    endif()
endif()

foreach(DLL ${OPENCV_DLLS})
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${OPENCV_DLLS}
        ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()