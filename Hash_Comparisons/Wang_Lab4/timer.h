#ifndef TIMER_H
#define TIMER_H

class Timer{
private:
    timeval startTime;
    timeval endTime;

public:
    void start();
    double stop();
    void printTime(double duration);
};


#include "timer.hpp"
#endif // TIMER_H
