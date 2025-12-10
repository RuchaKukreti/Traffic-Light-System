#include "trafficLight.h"

void TrafficLight::setId(int value)
{
    id = value;
}

int TrafficLight::getId()
{
    return id;
}

int TrafficLight::getSignal()
{
    return this->signal;
}

void TrafficLight::setSignal(int signal, ILane *lane)
{
    lane->signalLane(signal);
    this->signal = signal;
}

void TrafficLight::reset()
{
    this->signal = 0;
}