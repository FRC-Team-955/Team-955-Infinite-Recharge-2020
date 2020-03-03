#include <intake.h>
#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "settings.h"
#include <iostream>
using namespace frc;



void Intake::DeployIntakePNE()
{
  /*
    if (joy->GetRawButton(1)){
    std::cout<<"1 button 1"<<std::endl;
    pnu2 -> Set(1);
    pnu3 -> Set(0);
  }
  else {
    std::cout<<"0 button 1"<<std::endl;
    pnu2->Set(0);
    pnu3->Set(1);
  }
  */

 	if (is_pressed && joystick->GetRawButton(deploy_intake_button_idx)) {  
        is_pressed = false;
    	if (toggle) {  
        	toggle = false;
    	} else {
        	toggle = true;
    	}
    }else if(!joystick->GetRawButton(deploy_intake_button_idx) && !toggle) { 
        is_pressed = true; 
        solenoid_intake_right_0->Set(0);
        solenoid_intake_right_1->Set(1);	
        solenoid_intake_left_0->Set(1);
        solenoid_intake_left_1->Set(0);                       
           
    }else if(!joystick->GetRawButton(deploy_intake_button_idx) && toggle){
        is_pressed = true; 
        solenoid_intake_right_0->Set(1);
        solenoid_intake_right_1->Set(0);	
        solenoid_intake_left_0->Set(0);
        solenoid_intake_left_1->Set(1);
    }
        
}

void Intake::RunIntake(float output_percentage)
{
    intake_talon -> Set(ControlMode::PercentOutput, -(joystick -> GetRawAxis(run_intake_button_idx)));
} 


