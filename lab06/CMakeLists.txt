cmake_minimum_required(VERSION 3.14)
project(SmartHome LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(DEBUG_MODE "Włącz pełne logowanie" OFF)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(smarthome_lib STATIC
    ${SOURCE_DIR}/Licznik.cpp
    ${SOURCE_DIR}/Czujnik.cpp
    ${SOURCE_DIR}/Lampa.cpp
    ${SOURCE_DIR}/Termostat.cpp
    ${SOURCE_DIR}/Centrala.cpp
    ${SOURCE_DIR}/Logger.cpp
    ${SOURCE_DIR}/System.cpp
)

target_include_directories(smarthome_lib PUBLIC ${INCLUDE_DIR})

if(DEBUG_MODE)
    target_compile_definitions(smarthome_lib PUBLIC DEBUG_MODE)
    message(STATUS "Tryb DEBUG_MODE włączony")
endif()

add_executable(main ${SOURCE_DIR}/main.cpp)
target_link_libraries(main PRIVATE smarthome_lib)

set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Tryb budowania" FORCE)
endif()
