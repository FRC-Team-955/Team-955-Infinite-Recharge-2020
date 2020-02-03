#include <distance.h>
#include <iostream>

double Distance::GetCurrentDistance(const double height_of_field_element_minus_height_of_camera, const double mounting_angle_of_camera_in_radians, double vertical_angle_offset_in_radians)
{

    double distance = height_of_field_element_minus_height_of_camera / tan(mounting_angle_of_camera_in_radians + vertical_angle_offset_in_radians);

    return distance;
}