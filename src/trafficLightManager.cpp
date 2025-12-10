#include "trafficLightManager.h"
#include <functional>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

void TrafficLightManager::mapLanes(int id, pair<ITrafficLight *, vector<ILane *>> pair)
{
    lightToLaneMapper[id] = pair;
}

void TrafficLightManager::printState()
{
    for (int iterator = 0; iterator < 8; iterator++)
    {
        cout << state[iterator] << "\t";
    }
    cout << "\n";
}

void TrafficLightManager::setState(vector<ILane *> lanes)
{
    state[lanes[0]->getId()] = 1;
    state[lanes[1]->getId()] = 1;
}

void TrafficLightManager ::resetState()
{
    for (int iterator = 0; iterator < 8; iterator++)
    {
        state[iterator] = 0;
    }
}

void TrafficLightManager ::signalTrafficLight(ITrafficLight *trafficLight, std::vector<ILane *> lanes)
{
    semaphore[trafficLight->getId()].acquire();
    std::thread thread1(&ITrafficLight::setSignal, trafficLight, 1, lanes[0]);
    std::thread thread2(&ITrafficLight::setSignal, trafficLight, 1, lanes[1]);
    setState(lanes);
    printState();
    cout << std::flush;
    sleep(2);
    thread1.join();
    thread2.join();
    resetState();
    semaphore[(trafficLight->getId() + 1) % 4].release();
}

void TrafficLightManager::initiate()
{
    int timeInstance = 0, light = 0;
    cout << "l0\tl1\tl2\tl3\tl4\tl5\tl6\tl7" << endl;
    vector<std::thread> threadVector;
    semaphore[light].release();
    for (int index = 0; index < 3; index++)
    {
        for (auto &iterator : lightToLaneMapper)
        {
            std::thread signalTrafficLight(&TrafficLightManager::signalTrafficLight, this, std::ref(iterator.second.first), std::ref(iterator.second.second));
            threadVector.push_back(std::move(signalTrafficLight));
            light++;
        }
    }
    for (int iterator = 0; iterator < 12; iterator++)
    {
        if (threadVector[iterator].joinable())
        {
            threadVector[iterator].join();
        }
        else
        {
            cout << "Can't join" << endl;
        }
    }
}