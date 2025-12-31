cmake_minimum_required(VERSION 3.10)
project(SimpleRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    add_compile_options(-Wall -Wextra -g -O0)
else()
    add_compile_options(-O3)
endif()

add_subdirectory(questlib)

file(GLOB APP_SRC_FILES
    src/*.cpp
)

add_executable(SimpleRPG ${APP_SRC_FILES})

target_include_directories(SimpleRPG PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(SimpleRPG PRIVATE QuestLib_v2)

