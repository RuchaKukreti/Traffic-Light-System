#ifndef MOCK_TRAFFIC_LIGHT_H
#define MOCK_TRAFFIC_LIGHT_H

#include "ITrafficLight.h"
#include "ILane.h"
#include "mockLane.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockTrafficLight : public ITrafficLight
{
public:
    MOCK_METHOD(void, setId, (int value), (override));
    MOCK_METHOD(int, getId, (), (override));
    MOCK_METHOD(int, getSignal, (), (override));
    MOCK_METHOD(void, setSignal, (int signal, ILane *lane), (override));
    MOCK_METHOD(void, reset, (), (override));
};

#endif