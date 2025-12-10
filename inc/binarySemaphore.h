#ifndef BINARY_SEMAPHORE_H
#define BINARY_SEMAPHORE_H

#include <mutex>
#include <condition_variable>

class BinarySemaphore
{
    std::mutex mtx;
    std::condition_variable cv;

protected:
    int value = 0;

public:
    BinarySemaphore() {}
    BinarySemaphore(int val)
    {
        value = val;
    }
    void release();
    void acquire();
};

#endif
