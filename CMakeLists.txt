cmake_minimum_required(VERSION 3.16)
project(sfml-game-development)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# SFML Settings
include_directories(vendor/SFML/include)

set(SFML_USE_STATIC_STD_LIBS TRUE)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(vendor/SFML)

add_subdirectory(src/chapter1)
add_subdirectory(src/chapter2)

