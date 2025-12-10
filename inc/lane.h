#ifndef LANE_H
#define LANE_H

#include "ILane.h"

class Lane : public ILane
{
protected:
    int status = 0;
    int id = 0;

public:
    void signalLane(int status) override;
    void setId(int id) override;
    int getId() override;
    void resetLane() override;
};

#endif