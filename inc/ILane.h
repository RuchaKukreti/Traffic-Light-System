#ifndef I_LANE_H
#define I_LANE_H

class ILane
{
public:
    virtual void signalLane(int status) = 0;
    virtual void setId(int id) = 0;
    virtual int getId() = 0;
    virtual void resetLane() = 0;
};

#endif