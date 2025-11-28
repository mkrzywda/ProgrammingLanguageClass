add_library(EngineLib STATIC
    src/Engine.cpp
)

target_include_directories(EngineLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(Vehicle::Engine ALIAS EngineLib)