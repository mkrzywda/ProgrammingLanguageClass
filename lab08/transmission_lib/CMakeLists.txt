add_library(TransmissionLib STATIC
    src/Transmission.cpp
)

target_include_directories(TransmissionLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(Vehicle::Transmission ALIAS TransmissionLib)
