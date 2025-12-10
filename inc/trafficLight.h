#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "ITrafficLight.h"
#include "lane.h"

class TrafficLight : public ITrafficLight
{
protected:
    int signal = 0;

public:
    int id;
    void setId(int value) override;
    int getId() override;
    int getSignal() override;
    void setSignal(int signal, ILane *lane) override;
    void reset() override;
};

#endif