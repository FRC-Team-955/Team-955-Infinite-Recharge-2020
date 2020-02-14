#ifndef INTAKE
#define INTAKE

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"




class Intake {
    public:
        Intake (TalonSRX *intake_talon, Solenoid *solenoid_intake_right_0, Solenoid *solenoid_intake_right_1, Solenoid *solenoid_intake_left_0, Solenoid *solenoid_intake_left_1, Joystick *joystick) 
        : intake_talon(intake_talon), solenoid_intake_right_0(solenoid_intake_right_0), solenoid_intake_right_1(solenoid_intake_right_1), solenoid_intake_left_0(solenoid_intake_left_0), solenoid_intake_left_1(solenoid_intake_left_1), joystick(joystick) {};

        bool deploy_state = 0;
        void DeployIntakeSRX(int input_button, int rotation_distance);
        void DeployIntakePNE(int input_button);
        bool button_check = 0;
        bool motor_check = 0;
        void RunIntake(int input_button, float output_percentage);
        void ApplyDeploySoftLimits(int forward_limit, int backward_limit);
    
    
    private:
        TalonSRX *intake_talon;
        Solenoid *solenoid_intake_right_0;
        Solenoid *solenoid_intake_right_1;
        Solenoid *solenoid_intake_left_0;
        Solenoid *solenoid_intake_left_1;
        Joystick *joystick;
    
};

#endif
