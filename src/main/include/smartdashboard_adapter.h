#ifndef SMARTDASHBOARDADAPTER
#define SMARTDASHBOARDADAPTER

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <sstream>  
#include "version.h"
#include <string>

class SmartDashboard_Adapter{
    public:

    SmartDashboard_Adapter(){};  
    void  Get_Slider(int id_slider);
    void  Get_Button(int id_button);
    //void  Get_String (int id_string);
    std::string  ChooseAuto();

    private:
        std::string id_slider_real;
        std::string id_button_real;
        std::string input;
};
#endif