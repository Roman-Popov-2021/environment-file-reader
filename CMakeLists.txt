# Specify the minimum version.
cmake_minimum_required(VERSION 3.0)

# Specify the project info.
project(environment-file-reader VERSION 1.0.0 DESCRIPTION "Environment file reader")

# For creating Dll from Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Hide Windows warning
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# Declare the library target.
add_library(${PROJECT_NAME} SHARED
    src/main.h
    src/main.cpp
)

# Configure the directories to search for header files.
target_include_directories(${PROJECT_NAME} PRIVATE src)

# Set the version property.
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set the shared object version property to the project's major version.
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# Set the public header property to the one with the actual API.
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER src/main.h)
