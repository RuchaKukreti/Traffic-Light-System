enable_testing()

add_executable(tests
    binarySemaphoreTest.cpp
    laneTest.cpp
    mockTrafficLightManagerTest.cpp
    mockTrafficLightTest.cpp
    trafficLightManagerTest.cpp
)

target_link_libraries(tests
    gtest
    gtest_main
    TrafficLightSystem
)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/inc)

include(GoogleTest)
gtest_discover_tests(tests)
