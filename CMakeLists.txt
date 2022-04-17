cmake_minimum_required(VERSION 3.21)
project(pingpong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(pingpong ${SOURCE_FILES})
include_directories(/usr/local/include)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(pingpong sfml-system sfml-window sfml-graphics sfml-audio sfml-network)