#ifndef SMARTDASHBOARDADAPTER
#define SMARTDASHBOARDADAPTER

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <sstream>  
#include "version.h"
#include <string>

class SmartDashboardAdapter{
    public:

    SmartDashboardAdapter(){};  
    int GetSlider(int id_slider);
    bool GetButton(int id_button);
    std::string  ChooseAuto();

    private:
        std::string id_slider_real;
        std::string id_button_real;
        std::string input;
};
#endif