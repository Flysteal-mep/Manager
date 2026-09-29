cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)
project(Manager VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(Software ${SRC_FILES})
target_include_directories(Software PRIVATE "${CMAKE_SOURCE_DIR}/include")
