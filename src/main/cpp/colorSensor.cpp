#include "colorSensor.h"
using namespace frc;

void ColorSensor::SetBlue(double red, double green, double blue)
{
    blue_target = Color(red, green, blue);
    color_matcher->AddColorMatch(blue_target);
}
void ColorSensor::SetGreen(double red, double green, double blue)
{
    green_target = Color(red, green, blue);
    color_matcher->AddColorMatch(green_target);
}
void ColorSensor::SetRed(double red, double green, double blue)
{
    red_target = Color(red, green, blue);
    color_matcher->AddColorMatch(red_target);
}
void ColorSensor::SetYellow(double red, double green, double blue)
{
    yellow_target = Color(red, green, blue);
    color_matcher->AddColorMatch(yellow_target);
}
std::string ColorSensor::FindClosestColor(double confidance)
{
    color_guess = color_matcher->MatchClosestColor(color_sensor->GetColor(), confidance);
    if (color_guess == blue_target) {
        return "Blue";
    } else if (color_guess == red_target) {
        return "Red";
    } else if (color_guess == green_target) {
        return "Green";
    } else if (color_guess == yellow_target) {
        return "Yellow";
    } else {
        return "Unknown";
    }
}
frc::Color ColorSensor::GetColor()
{
    return color_sensor->GetColor();
}
std::string ColorSensor::GetFMSColor()
{
    std::string game_data;
    game_data = DriverStation::GetInstance().GetGameSpecificMessage();
    if (game_data.length() > 0) {
        switch (game_data[0]) {
        case 'B':
            return "B";
            break;
        case 'G':
            return "G";
            break;
        case 'R':
            return "R";
            break;
        case 'Y':
            return "Y";
            break;
        default:
            return "n/a";
            break;
        }
    } else {
        return "n/a";
    }
}
bool ColorSensor::IsMatch(std::string fms_color, std::string closest_color)
{
    if (closest_color == "Green" && fms_color == "G") {
        return 1;
    } else if (closest_color == "Blue" && fms_color == "B") {
        return 1;
    } else if (closest_color == "Red" && fms_color == "R") {
        return 1;
    } else if (closest_color == "Yellow" && fms_color == "Y") {
        return 1;
    } else {
        return 0;
    }
}
int ColorSensor::CountColors()
{
    if (FindClosestColor(1) != last_color) {
        count++;
    }
    last_color = FindClosestColor(1);
    return count;
}