#include "binarySemaphore.h"
#include <gtest/gtest.h>

class BinarySemaphoreTest : public ::testing::Test, public BinarySemaphore
{
public:
    BinarySemaphore binarySemaphore;
    int wrapperGetValue()
    {
        int semaphoreValue = value;
        return semaphoreValue;
    }
};

TEST_F(BinarySemaphoreTest, checkIfBinarySemaphoreGetsReleased)
{

    binarySemaphore.release();
    int value = wrapperGetValue();
    EXPECT_EQ(value, 1);
}

TEST_F(BinarySemaphoreTest, checkIfBinarySemaphoreGetsAcquired)
{
    binarySemaphore.acquire();
    int value = wrapperGetValue();
    EXPECT_EQ(value, 0);
}
