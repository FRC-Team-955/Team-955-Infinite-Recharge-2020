#ifndef DISTANCE
#define DISTANCE

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <iostream>

class Distance {
    public:
    double GetCurrentDistance(const double height_of_field_element_minus_height_of_camera,  double vertical_angle_offset_in_radians);
    double RadiansToDegrees(double radians);
    double DegreesToRadians(double degrees);
    int DistanceToVelocity(double distance);

};
#endif
