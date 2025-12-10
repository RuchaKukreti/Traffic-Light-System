#include <iostream>
#include "lane.h"
#include "trafficLight.h"
#include "trafficLightManager.h"

using std::cin;
using std::cout;
using std::endl;

int main()
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
    trafficLightManager.mapLanes(0, {&trafficLight[0], {&lane[3], &lane[5]}});
    trafficLightManager.mapLanes(1, {&trafficLight[1], {&lane[5], &lane[7]}});
    trafficLightManager.mapLanes(2, {&trafficLight[2], {&lane[1], &lane[7]}});
    trafficLightManager.mapLanes(3, {&trafficLight[3], {&lane[1], &lane[3]}});
    trafficLightManager.initiate();
    return 0;
}