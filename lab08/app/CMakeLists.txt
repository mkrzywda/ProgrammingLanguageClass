add_executable(car_sim
    src/main.cpp
    src/Car.cpp
    src/Logger.cpp
)

target_include_directories(car_sim PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(car_sim PRIVATE
    Vehicle::Engine
    Vehicle::Transmission
)

set_target_properties(car_sim PROPERTIES
    OUTPUT_NAME "car_sim"
)
