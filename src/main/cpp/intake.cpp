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
    
        if (joystick->GetRawButton(deploy_intake_button_idx) == false && button_check == true) {
            button_check = false;
        } else if (joystick->GetRawButton(deploy_intake_button_idx) == true && motor_check == false && button_check == false) {
            solenoid_intake_right_0->Set(!solenoid_intake_right_0->Get());
            solenoid_intake_right_1->Set(!solenoid_intake_right_1->Get());	
            solenoid_intake_left_0->Set(!solenoid_intake_left_0->Get());
            solenoid_intake_left_1->Set(!solenoid_intake_left_1->Get());            motor_check = true;
            button_check = true;
           
        } else if (joystick->GetRawButton(deploy_intake_button_idx) == true && motor_check == true && button_check == false) {
            solenoid_intake_right_0->Set(!solenoid_intake_right_0->Get());
            solenoid_intake_right_1->Set(!solenoid_intake_right_1->Get());	
            solenoid_intake_left_0->Set(!solenoid_intake_left_0->Get());
            solenoid_intake_left_1->Set(!solenoid_intake_left_1->Get());            motor_check = false;
            button_check = true;
           
        }
        
}

void Intake::RunIntake(float output_percentage)
{
    intake_talon -> Set(ControlMode::PercentOutput, joystick -> GetRawButton(run_intake_button_idx));
} 


