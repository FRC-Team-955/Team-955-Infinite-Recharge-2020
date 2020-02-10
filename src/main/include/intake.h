#ifndef INTAKE
#define INTAKE

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
using namespace frc;
using namespace std;


class Intake {
	public:
		Intake (TalonSRX *deployment_talon, Solenoid *pneu, TalonSRX *intake_talon, Joystick *joystick) 
    : deployment_talon(deployment_talon), pneu(pneu), intake_talon(intake_talon), joystick(joystick) {};

    bool deploy_state = 0;
    void DeployIntakeSRX(int input_button, int rotation_distance);
    void DeployIntakePNE(int input_button);
    bool toggle_state = 0;
    bool pneustate = 0;
    bool state_from_button = 0;
    void RunIntake(int input_button, float output_percentage);
    void ApplyDeploySoftLimits(int forward_limit, int backward_limit);
    
    
	private:
		TalonSRX *deployment_talon;
    Solenoid *pneu;
    TalonSRX *intake_talon;
		Joystick *joystick;
    
};


#endif
