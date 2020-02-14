#ifndef INTAKE
#define INTAKE

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"

using namespace frc;



class Intake {
	public:
		Intake (TalonSRX *deployment_talon, TalonSRX *intake_talon, Joystick *joystick) 
    : deployment_talon(deployment_talon), intake_talon(intake_talon), joystick(joystick) {};

    bool deploy_state = 0;
    void DeployIntakeSRX(int input_button, int rotation_distance);
    void DeployIntakePNE(int input_button);
    bool button_check = 0;
    bool motor_check = 0;
    void RunIntake(int input_button, float output_percentage);
    void ApplyDeploySoftLimits(int forward_limit, int backward_limit);
    
    
	private:
		TalonSRX *deployment_talon;
    TalonSRX *intake_talon;
		Joystick *joystick;
    
};


#endif
