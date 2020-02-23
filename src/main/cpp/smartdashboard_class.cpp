#include "smartdashboard_class.h"

using namespace frc;

void  SmartDashboard_Class::Get_Slider(int id_slider){
    std::stringstream ss;
    ss<<id_slider;
    id_slider_real = ss.str();

    std::cout<<"Slider: "<<SmartDashboard::GetNumber("DB/Slider "+id_slider_real, 0)<<std::endl;


}

void SmartDashboard_Class::Get_Button(int  id_button){
    std::stringstream sb;
    sb << id_button;
    id_button_real = sb.str();

    std::cout<<"Button: "<< SmartDashboard::GetNumber("DB/Button "+id_button_real, 0)<<std::endl;


}

/*void SmartDashboard_Class::Get_String(int  id_string){
    std::stringstream sss;
    sss << id_string;
    std::string id_string_real = sss.str();

    //std::cout<<"String: "<< SmartDashboard::GetString("DB/String  "+id_string_real, )<<std::endl;


}*/

std::string SmartDashboard_Class::ChooseAuto(){
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