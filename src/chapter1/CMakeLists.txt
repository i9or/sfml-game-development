cmake_minimum_required(VERSION 3.17)
project(chapter1)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} chapter1.cpp)
target_link_libraries(${PROJECT_NAME}
                      sfml-graphics
                      sfml-window
                      sfml-system
                      sfml-network
                      sfml-audio)

