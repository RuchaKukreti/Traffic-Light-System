#ifndef TRAFFIC_LIGHT_MANAGER_H
#define TRAFFIC_LIGHT_MANAGER_H

#include <map>
#include <thread>
#include <vector>
#include "ILane.h"
#include "trafficLight.h"
#include "ITrafficLight.h"
#include "binarySemaphore.h"
#include <iostream>

using std::map;
using std::pair;
using std::vector;

class TrafficLightManager
{
protected:
    int state[8] = {0};
    map<int, pair<ITrafficLight *, vector<ILane *>>> lightToLaneMapper;
    BinarySemaphore semaphore[4];

public:
    void mapLanes(int id, pair<ITrafficLight *, vector<ILane *>> lanes);
    void printState();
    void setState(vector<ILane *> lanes);
    void resetState();
    void signalTrafficLight(ITrafficLight *trafficLight, std::vector<ILane *> lanes);
    void initiate();
};
#endif