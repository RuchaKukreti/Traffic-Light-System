#ifndef I_TRAFFIC_LIGHT_H
#define I_TRAFFIC_LIGHT_H

#include "ILane.h"

class ITrafficLight
{
public:
    virtual void setId(int value) = 0;
    virtual int getId() = 0;
    virtual int getSignal() = 0;
    virtual void setSignal(int signal, ILane *lane) = 0;
    virtual void reset() = 0;
};

#endif