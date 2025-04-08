cmake_minimum_required(VERSION 3.15)

project(video_edit
        LANGUAGES CXX
        DESCRIPTION "Video Edit Tool")

# for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_compile_options(-Wno-attributes)

# Set install path
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR} CACHE PATH "Project root" FORCE)
endif()

# Add subdirectory
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
