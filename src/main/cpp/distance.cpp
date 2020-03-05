#include <iostream>
#include <distance.h>

double Distance::GetCurrentDistance(const double height_of_field_element_minus_height_of_camera, double vertical_angle_offset_in_radians) {
    
   double angle = DegreesToRadians(RadiansToDegrees(atan(71.25 / 226)) - (4.55));
   //double angle = 1.1854;
    double distance = height_of_field_element_minus_height_of_camera / tan (angle + DegreesToRadians(vertical_angle_offset_in_radians));
    return distance;
}

double Distance::RadiansToDegrees(double radians){
    return radians * (180 / 3.1415);
}

double Distance::DegreesToRadians(double degrees){
    return degrees * (3.1415 / 180);
}
int Distance::DistanceToVelocity(double distance){
   return -0.056 * distance * distance + 7.33568 * distance - 15759.202;
}

//Insert into robot.cpp
//shooter->SpinMotorVelocity(distance->DistanceToVelocity(distance->GetCurrentDistance(71.25, distance_offset)));