cmake_minimum_required(VERSION 3.16)

# Project name
project(MyQtApp VERSION 1.0)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/msvc2022_64")
# Use the `AUTOMOC` and `AUTOUIC` features to handle Qt MOC and UI files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(MSVC)
    add_compile_options(/Zc:__cplusplus /permissive-)
endif()

# Find the Qt6 package
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Add executable
add_executable(MyQtApp
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

# Link the Qt6 Widgets library
target_link_libraries(MyQtApp PRIVATE Qt6::Widgets)
