cmake_minimum_required(VERSION 3.10)
project(LibraryWithFriend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -O0)
    add_definitions(-DDEBUG)
else()
    add_compile_options(-O3)
endif()

include_directories(include)

add_executable(LibraryWithFriend
    src/main.cpp
    src/Book.cpp
    src/Librarian.cpp
)
