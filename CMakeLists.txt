cmake_minimum_required(VERSION 3.16)
project(sfml-game-development)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# SFML Settings
include_directories(vendor/SFML/include)

set(SFML_USE_STATIC_STD_LIBS TRUE)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(vendor/SFML)

add_subdirectory(src/chapter1)
add_subdirectory(src/chapter2)
add_subdirectory(src/chapter3)

file(GLOB_RECURSE PROJECT_ASSETS assets/*.*)
file(GLOB PROJECT_COMMON_FILES README.md
    .gitignore
    .gitattributes
    .gitmodules
    LICENSE
    .editorconfig
    .clang-format)

source_group("Assets" FILES ${PROJECT_ASSETS})

add_custom_target(Common SOURCES ${PROJECT_ASSETS} ${PROJECT_COMMON_FILES})
