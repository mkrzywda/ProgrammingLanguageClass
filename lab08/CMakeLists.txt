cmake_minimum_required(VERSION 3.20)
project(VehicleSimulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor)

# Kolejność ważna – app zależy od engine i transmission
add_subdirectory(engine_lib)
add_subdirectory(transmission_lib)
add_subdirectory(app)
