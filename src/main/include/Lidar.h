#ifndef LIDAR
#define LIDAR

#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace frc;
class Lidar {
public:
    Lidar(Counter* lidar)
        : lidar(lidar)
    {
        lidar->SetMaxPeriod(1.0);
        lidar->SetSemiPeriodMode(true);
        lidar->Reset();
    };
    int GetDistance(std::string units);
    bool IsInRange(int low_range, int high_range);

private:
    Counter* lidar;
    int dist;
    int low_range;
    int high_range;
};
#endif
