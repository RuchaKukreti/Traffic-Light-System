#include "mockTrafficLight.h"
#include "ITrafficLight.h"
#include "trafficLight.h"
#include <gtest/gtest.h>

class TrafficLightTest : public ::testing::Test, public TrafficLight
{
public:
    TrafficLight trafficLight;
    int signalValue;
    void SetUp()
    {
        signalValue = trafficLight.getSignal();
    }
};

TEST_F(TrafficLightTest, getSignalWhenSignalIsDefault)
{
    EXPECT_EQ(0, trafficLight.getSignal());
}

TEST_F(TrafficLightTest, getSignalWhenSignalIsGreen)
{
    MockLane *mockLane = new MockLane;
    EXPECT_CALL(*mockLane, signalLane(1));
    trafficLight.setSignal(1, mockLane);
    EXPECT_EQ(1, trafficLight.getSignal());
    delete mockLane;
}

TEST_F(TrafficLightTest, getSignalWhenSignalIsRed)
{
    MockLane *mockLane = new MockLane;
    EXPECT_CALL(*mockLane, signalLane(0));
    trafficLight.setSignal(0, mockLane);
    EXPECT_EQ(0, trafficLight.getSignal());
    delete mockLane;
}

TEST_F(TrafficLightTest, checkIfTrafficLightResetsSignalToInitialState)
{
    MockLane *mockLane = new MockLane;
    EXPECT_CALL(*mockLane, signalLane(1));
    trafficLight.setSignal(1, mockLane);
    EXPECT_EQ(trafficLight.getSignal(), 1);
    trafficLight.reset();
    EXPECT_EQ(trafficLight.getSignal(), 0);
    delete mockLane;
}

TEST_F(TrafficLightTest, checkIfTrafficLightSetsItsIdCorrectly)
{
    trafficLight.setId(101);
    EXPECT_EQ(101, trafficLight.id);
}

TEST_F(TrafficLightTest, checkIfTrafficLightGetsItsIdCorrectlyUsingGetId)
{
    trafficLight.setId(101);
    EXPECT_EQ(101, trafficLight.getId());
}

