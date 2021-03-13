cmake_minimum_required(VERSION 3.16)
project(chapter3)

add_executable(${PROJECT_NAME} chapter3.cpp Window.cpp Window.h Game.cpp Game.h Snake.cpp Snake.h)
target_link_libraries(${PROJECT_NAME}
                      sfml-graphics
                      sfml-window
                      sfml-system
                      sfml-network
                      sfml-audio)
