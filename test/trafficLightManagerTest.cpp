#include "trafficLightManager.h"
#include <gtest/gtest.h>

class TrafficLightManagerTest : public ::testing::Test, public TrafficLightManager
{
public:
    TrafficLightManager trafficLightManager;
    void SetUp()
    {
        vector<TrafficLight> trafficLight(4);
        vector<Lane> lane(8);
        for (int iterator = 0; iterator < 8; iterator++)
        {
            lane[iterator].setId(iterator);
        }
        for (int iterator = 0; iterator < 4; iterator++)
        {
            trafficLight[iterator].setId(iterator);
        }
        TrafficLightManager trafficLightManager;
        trafficLightManager.mapLanes(0, {trafficLight[0], {lane[3], lane[5]}});
        trafficLightManager.mapLanes(1, {trafficLight[1], {lane[5], lane[7]}});
        trafficLightManager.mapLanes(2, {trafficLight[2], {lane[1], lane[7]}});
        trafficLightManager.mapLanes(3, {trafficLight[3], {lane[1], lane[3]}});
    }
    int *wrapperGetState()
    {
        return state;
    }
};

TEST_F(TrafficLightManagerTest, checkIfCorrectLightIsMapped)
{
    int light = 0;
    for (auto iterator : lightToLaneMapper)
    {
        EXPECT_EQ(iterator.second.first.id, light);
        light++;
    }
}
