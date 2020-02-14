#include <intake.h>
#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "settings.h"
#include <iostream>
using namespace frc;
using namespace std;

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
    bool button_state = joystick->GetRawButton(deploy_intake_button_idx);

    if (button_state == 1 and pneustate == 0 and toggle_state == 0){
        /*
    	solenoid_intake_right_0->Set(!solenoid_intake_right_0->Get());
        solenoid_intake_right_1->Set(1 - solenoid_intake_right_1->Get());	
        solenoid_intake_left_0->Set(1 - solenoid_intake_left_0->Get());
        solenoid_intake_left_1->Set(1 - solenoid_intake_left_1->Get());
        */
    	pneustate = 1;
    }
    if (button_state == 0 and pneustate == 1) {
    	toggle_state = toggle_state + 1;
    }
    if (button_state == 1 and pneustate == 1 and toggle_state == 1) {
        /*
    	solenoid_intake_right_0->Set(1 - solenoid_intake_right_0->Get());
        solenoid_intake_right_1->Set(1 - solenoid_intake_right_1->Get());	
        solenoid_intake_left_0->Set(1 - solenoid_intake_left_0->Get());
        solenoid_intake_left_1->Set(1 - solenoid_intake_left_1->Get());
        */
    	pneustate = 0 ;
    	toggle_state = 0;
	}
}

void Intake::RunIntake(float output_percentage)
{
    if (joystick -> GetRawButton(run_intake_button_idx))            //Press button_foward to run forward
    {
    	intake_talon -> Set(ControlMode::PercentOutput, output_percentage);

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
