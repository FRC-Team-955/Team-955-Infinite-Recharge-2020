#ifndef DISTANCE
#define DISTANCE

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include "frc/WPILib.h"

class Distance {
    public:
    double GetCurrentDistance(const double height_of_field_element_minus_height_of_camera, const double mounting_angle_of_camera_in_radians, double vertical_angle_offset_in_radians);
};
#endif
