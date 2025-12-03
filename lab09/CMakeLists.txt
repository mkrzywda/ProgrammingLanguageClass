cmake_minimum_required(VERSION 3.10)
project(SimpleRPG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -O0")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

include_directories(include)

file(GLOB SRC_FILES
    src/*.cpp
)

add_executable(SimpleRPG ${SRC_FILES})


message(STATUS "Dodano pliki źródłowe:")
foreach(FILE ${SRC_FILES})
    message(STATUS "  ${FILE}")
endforeach()
