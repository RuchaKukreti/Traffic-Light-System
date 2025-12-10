#include "binarySemaphore.h"

void BinarySemaphore::acquire()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]
            { return value > 0; });
    --value;
}

void BinarySemaphore::release()
{
    std::lock_guard<std::mutex> lock(mtx);
    ++value;
    cv.notify_one();
}