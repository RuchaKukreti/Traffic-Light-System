#include "lane.h"

void Lane::signalLane(int status)
{
    this->status = status;
}

void Lane::setId(int id)
{
    this->id = id;
}

int Lane::getId()
{
    return id;
}

void Lane::resetLane()
{
    status = 0;
}