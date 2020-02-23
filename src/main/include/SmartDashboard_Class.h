#ifndef SMARTDASHBOARD
#define SMARTDASHBOARD

#include <string>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <cmath>
using namespace frc;

class SmartDashboard_Class{
    public:

    SmartDashboard_Class(){};  
    void  Get_Slider(int id_slider);
    void  Get_Button(int id_button);
   // void Get_String (int id_string);

    private:

};
#endif