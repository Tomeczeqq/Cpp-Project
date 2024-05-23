cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 23)

add_executable(project main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(D:/IT apps/SFML-2.6.1/include/SFML)
target_link_libraries(project sfml-system sfml-window sfml-graphics sfml-audio)