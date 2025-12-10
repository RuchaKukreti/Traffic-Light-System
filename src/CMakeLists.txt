add_library(TrafficLightSystem
    lane.cpp
    trafficLight.cpp
    trafficLightManager.cpp
    binarySemaphore.cpp
)

target_include_directories(TrafficLightSystem PUBLIC ${CMAKE_SOURCE_DIR}/inc)
