#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "timer.h"
using namespace std;

void Timer::start()
{
    gettimeofday(&startTime, NULL);
}

double Timer::stop()
{
    long seconds, nseconds;
    double duration;

    gettimeofday(&endTime, NULL);

    seconds = endTime.tv_sec - startTime.tv_sec;
    nseconds = endTime.tv_usec - startTime.tv_usec;

    duration = seconds + nseconds/1000000.0;

    return duration;

}

void printTime(double duration)
{
    printf("%5.6f seconds\n", duration);
}
