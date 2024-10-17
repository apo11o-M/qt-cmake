cmake_minimum_required(VERSION 3.16)

project(qtcmake VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# REQUIRED: Set the path to the Qt installation in your system
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/msvc2022_64")

# Use the `AUTOMOC` and `AUTOUIC` features to handle Qt MOC and UI files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(MSVC)
    add_compile_options(/Zc:__cplusplus /permissive-)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(qtcmake
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(qtcmake PRIVATE Qt6::Widgets)
