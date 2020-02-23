#include "SmartDashboard_Class.h"
#include "Robot.h"
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include<sstream>  
#include "version.h"
#include <string>
using namespace frc;
using namespace std;

void  SmartDashboard_Class::Get_Slider(int id_slider){
    stringstream ss;
    ss<<id_slider;
    string id_slider_real = ss.str();

    std::cout<<"Slider: "<<SmartDashboard::GetNumber("DB/Slider "+id_slider_real, 0)<<std::endl;


}

void SmartDashboard_Class::Get_Button(int  id_button){
    stringstream sb;
    sb << id_button;
    string id_button_real = sb.str();

    std::cout<<"Button: "<< SmartDashboard::GetNumber("DB/Button "+id_button_real, 0)<<std::endl;


}

/*void SmartDashboard_Class::Get_String(int  id_string){
    stringstream sss;
    sss << id_string;
    string id_string_real = sss.str();

    std::cout<<"String: "<< SmartDashboard::GetString("DB/String  "+id_string_real, )<<std::endl;


}*/