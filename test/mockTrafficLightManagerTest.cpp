#include "mockTrafficLight.h"
#include "ILane.h"
#include "mockLane.h"
#include <gtest/gtest.h>
#include "ITrafficLight.h"
#include "trafficLightManager.h"

#include <iostream>
using namespace std;

using std::pair;
using testing::Return;

class TrafficLightManagerTest : public ::testing::Test, public TrafficLightManager
{
public:
    TrafficLightManager trafficLightManager;
    MockTrafficLight *mockTrafficLight = new MockTrafficLight;
    MockLane mockLane1;
    MockLane mockLane2;
    pair<ITrafficLight *, vector<ILane *>> pairs;
    vector<ILane *> lanes;
    void SetUp()
    {
        lanes.push_back(&mockLane1);
        lanes.push_back(&mockLane2);
    }
    void TearDown()
    {
        delete mockTrafficLight;
    }
    int *wrapperGetState()
    {
        return state;
    }
    map<int, pair<ITrafficLight *, vector<ILane *>>> &wrapperGetMap()
    {
        cout << "Enterd" << endl;
        cout << lightToLaneMapper[0].first->getId() << "+++++++" << endl;
        return lightToLaneMapper;
    }
    BinarySemaphore *wrapperGetSemaphores()
    {
        return semaphore;
    }
};

TEST_F(TrafficLightManagerTest, checkIfLanesAreMappedToCorrectTrafficLight)
{
    pairs.first = mockTrafficLight;
    pairs.second = lanes;
    ON_CALL(*mockTrafficLight, getId()).WillByDefault(Return(1));
    trafficLightManager.mapLanes(0, pairs);
    map<int, pair<ITrafficLight *, vector<ILane *>>> &mpp = wrapperGetMap();
    EXPECT_EQ(0, mpp.begin()->first);
    ON_CALL(mockLane1, getId()).WillByDefault(Return(1));
    EXPECT_EQ(mpp.begin()->second.first->getId(), 0);
    EXPECT_EQ(mpp.begin()->second.second[0]->getId(), 101);
    EXPECT_EQ(mpp.begin()->second.second[1]->getId(), 102);
}

TEST_F(TrafficLightManagerTest, checkStateIfLight0TurnsGreen)
{
    ILane *lanePtr = &mockLane1;
    EXPECT_CALL(*mockTrafficLight, setSignal(1, lanePtr));
    EXPECT_CALL(*mockTrafficLight, setSignal(1, lanePtr));
    EXPECT_CALL(mockLane1, signalLane(1));
    EXPECT_CALL(mockLane2, signalLane(1));
    EXPECT_CALL(*mockTrafficLight, getId()).WillOnce(Return(0));
    vector<ILane *> mockVectorLanes;
    mockVectorLanes.push_back(lanePtr);
    lanePtr = &mockLane2;
    mockVectorLanes.push_back(lanePtr);
    EXPECT_CALL(*mockTrafficLight, setSignal(1, lanePtr));
    trafficLightManager.signalTrafficLight(mockTrafficLight, mockVectorLanes);
    int *state = wrapperGetState();
    for (int i = 0; i < 8; i++)
    {
        cout << state[i] << " ";
    }
}
