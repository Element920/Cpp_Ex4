// israelmor555@gmail.com
// 206508954
cmake_minimum_required(VERSION 3.10)
project(TreeVisualization)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(TreeVisualization main.cpp)

target_link_libraries(TreeVisualization sfml-graphics sfml-window sfml-system)
