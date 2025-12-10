#ifndef MOCK_LANE_H
#define MOCK_LANE_H

#include "ILane.h"
#include <gmock/gmock.h>

class MockLane : public ILane
{
public:
    MOCK_METHOD(void, signalLane, (int), (override));
    MOCK_METHOD(void, setId, (int), (override));
    MOCK_METHOD(int, getId, (), (override));
    MOCK_METHOD(void, resetLane, (), (override));
};

#endif