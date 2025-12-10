#include "lane.h"
#include <gtest/gtest.h>

class LaneTest : public ::testing::Test, public Lane
{
public:
    Lane lane;
    int wrapperGetSignal()
    {
        int signalValue = status;
        return signalValue;
    }
    void SetUp()
    {
        lane.signalLane(1);
    }
};

TEST_F(LaneTest, checkIfRightLaneGetsSignal)
{
    lane.setId(101);
    lane.signalLane(0);
    EXPECT_EQ(101, lane.getId());
}

TEST_F(LaneTest, checkIfLaneGetsRightSignalBySignalLane)
{
    lane.signalLane(0);
    int signal = wrapperGetSignal();
    EXPECT_EQ(0, signal);
}

TEST_F(LaneTest, checkIfLaneIdGetsSetUsingSetId)
{
    lane.setId(101);
    EXPECT_EQ(101, lane.getId());
}

TEST_F(LaneTest, checkIfLaneGetsResetusingResetLane)
{
    lane.setId(101);
    resetLane();
    EXPECT_EQ(0, wrapperGetSignal());
}