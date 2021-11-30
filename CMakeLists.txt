project(tp6)
cmake_minimum_required(VERSION 3.10)

include_directories(include/)

option(DEBUG "Enable debugging" OFF)

add_compile_options(-Wall -Wextra -Werror -O2 -std=c++17)

file(GLOB C_SOURCES src/*.cpp)
list(REMOVE_ITEM C_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable( ${CMAKE_PROJECT_NAME}_main 
    ${C_SOURCES}
    src/main.cpp
)

set_target_properties(${CMAKE_PROJECT_NAME}_main PROPERTIES LINKER_LANGUAGE C)
