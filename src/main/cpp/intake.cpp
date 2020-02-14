#include <intake.h>
#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "settings.h"
#include "togglemotor.h"
#include <iostream>
using namespace frc;


/*
void Intake::DeployIntakeSRX(int rotation_distance)
{
    if (joystick -> GetRawButton(input_button))
    {
        if (deploy_state == 0)
        {
            deployment_talon -> Set(ControlMode::Position, rotation_distance);
            deploy_state = 1;
        }
        if (deploy_state == 1)
        {
            deployment_talon -> Set(ControlMode::Position, -rotation_distance);
            deploy_state = 0;
            
        }
    }
}
*/

void Intake::DeployIntakePNE()
{
    if (x > 10){
        if (joystick->GetRawButton(deploy_intake_button_idx) == false && button_check == true) {
            button_check = false;
        } else if (joystick->GetRawButton(1) == true && motor_check == false && button_check == false) {
            solenoid_intake_right_0->Set(!solenoid_intake_right_0->Get());
            solenoid_intake_right_1->Set(!solenoid_intake_right_1->Get());	
            solenoid_intake_left_0->Set(!solenoid_intake_left_0->Get());
            solenoid_intake_left_1->Set(!solenoid_intake_left_1->Get());            motor_check = true;
            button_check = true;
            x = 0;
        } else if (joystick->GetRawButton(deploy_intake_button_idx) == true && motor_check == true && button_check == false) {
            solenoid_intake_right_0->Set(!solenoid_intake_right_0->Get());
            solenoid_intake_right_1->Set(!solenoid_intake_right_1->Get());	
            solenoid_intake_left_0->Set(!solenoid_intake_left_0->Get());
            solenoid_intake_left_1->Set(!solenoid_intake_left_1->Get());            motor_check = false;
            button_check = true;
            x = 0;
        } 
    } else {
        x += 1;
    }
}

void Intake::RunIntake(float output_percentage)
{
    if (joystick -> GetRawButton(run_intake_button_idx))            //Press button_foward to run forward
    {
    	intake_toggle -> Toggle(output_percentage, );

    } else           //Dont press to stop the motor (or, like... disable it)
    {
        intake_talon -> Set(ControlMode::PercentOutput, 0);
    }
} 
void Intake::ApplyDeploySoftLimits(int forward_limit, int backward_limit)
{
    deployment_talon -> ConfigForwardSoftLimitThreshold(forward_limit, 10);
    deployment_talon -> ConfigReverseSoftLimitThreshold(backward_limit, 10);

    deployment_talon -> ConfigForwardSoftLimitEnable(true, 10);
    deployment_talon -> ConfigReverseSoftLimitEnable(true, 10);

}
