cmake_minimum_required(VERSION 3.14)
project(SimpleConfig LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === OPCJE ===
option(DEBUG_MODE "Włącz pełne logowanie" OFF)
option(PROFILE_MODE "Włącz profilowanie czasu" OFF)

# === BIBLIOTEKA STATYCZNA ===
add_library(configlib STATIC
    src/Config.cpp
    src/Logger.cpp
)

target_include_directories(configlib PUBLIC include)

# === WARUNKOWE DEFINICJE ===
if(DEBUG_MODE)
    target_compile_definitions(configlib PUBLIC DEBUG_MODE)
endif()

if(PROFILE_MODE)
    target_compile_definitions(configlib PUBLIC PROFILE_MODE)
endif()

# === PROGRAM GŁÓWNY ===
add_executable(main src/Main.cpp)
target_link_libraries(main configlib)

# === FLAGI ===
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
