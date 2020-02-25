#include "smartdashboard_adapter.h"

using namespace frc;

int SmartDashboardAdapter::GetSlider(int id_slider){
    std::stringstream ss;
    ss<<id_slider;
    id_slider_real = ss.str();

    return SmartDashboard::GetNumber("DB/Slider "+id_slider_real, 0);


}

bool SmartDashboardAdapter::GetButton(int  id_button){
    std::stringstream sb;
    sb << id_button;
    id_button_real = sb.str();

    return SmartDashboard::GetNumber("DB/Button "+id_button_real, 0);


}

std::string SmartDashboardAdapter::ChooseAuto(){
    input = SmartDashboard::GetString("DB/String 0", "no_data");

    if(input == "F" || input =="f"){ //Five Ball Pickup = F/f ; Three Ball Pickup = T/t ; Complete Auto from Anywhere = C/c ; Simple Backup = S/s
        return "FiveBallPickup";
    }else if(input == "T" || input =="t"){
        return "ThreeBallPickup";
    }else if(input == "C" || input =="c"){
        return "CompleteAuto";
    }else if(input == "S" || input =="s"){
        return "SimpleAuto";
    }

    return "";
}