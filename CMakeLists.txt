cmake_minimum_required(VERSION 3.24)
project(project1)
set(APPLICATION_LIBRARY BugSquashLib)

set(CMAKE_CXX_STANDARD 17)

# Request the required wxWidgets libs
# Turn off wxWidgets own precompiled header system, since
# it doesn't seem to work. The CMake version works much better.
set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Add BugSquashLib to the libraries that can be used
add_subdirectory(${APPLICATION_LIBRARY})
include_directories(${APPLICATION_LIBRARY})

# Define a variable containing a list of source files for the project
set(SOURCE_FILES main.cpp pch.h BugSquashApp.cpp BugSquashApp.h)

# Create the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCE_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ${APPLICATION_LIBRARY})

# pch will be a precompiled library so it won't be compiled more than once
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/images/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

add_subdirectory(Tests)