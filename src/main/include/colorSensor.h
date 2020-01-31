#ifndef COLORSENSOR
#define COLORSENSOR

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

using namespace frc;
using namespace rev;
class ColorSensor {
   public:
       ColorSensor (ColorSensorV3 *color_sensor, ColorMatch *color_matcher) : color_sensor(color_sensor), color_matcher(color_matcher) {};
       
       void SetRed(double red,  double green, double blue);
       void SetGreen(double red,  double green, double blue);
       void SetBlue(double red,  double green, double blue);
       void SetYellow(double red,  double green, double blue);

       std::string FindClosestColor(double confidance);
       frc::Color GetColor();
       std::string GetFMSColor();
       int CountColors();
       
       bool IsMatch(std::string fms_color, std::string closest_color);
   private:
        ColorSensorV3 *color_sensor;
        ColorMatch *color_matcher;

        double red;
        double green;
        double blue;

        std::string closest_color;
        std::string fms_color;

        double confidance;

        int count = 0;
        std::string last_color = "";

        frc::Color yellow_target; 
        frc::Color green_target; 
        frc::Color blue_target; 
        frc::Color red_target; 

        frc::Color color_guess;
        frc::Color detected_color;
};
#endif
