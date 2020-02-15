#ifndef INTAKE
#define INTAKE

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "togglemotor.h"




class Intake {
    public:
        Intake (ToggleMotor *intake_toggle, TalonSRX *intake_talon, frc::Solenoid *solenoid_intake_right_0, frc::Solenoid *solenoid_intake_right_1, frc::Solenoid *solenoid_intake_left_0, frc::Solenoid *solenoid_intake_left_1, frc::Joystick *joystick) 
        : intake_toggle(intake_toggle), intake_talon(intake_talon), solenoid_intake_right_0(solenoid_intake_right_0), solenoid_intake_right_1(solenoid_intake_right_1), solenoid_intake_left_0(solenoid_intake_left_0), solenoid_intake_left_1(solenoid_intake_left_1), joystick(joystick) {};

        bool deploy_state = 0;
        void DeployIntakePNE();
        bool button_check = 0;
        bool motor_check = 0;
        void RunIntake(float output_percentage);
    
    
    private:
        ToggleMotor *intake_toggle;
        TalonSRX *intake_talon;
        frc::Solenoid *solenoid_intake_right_0;
        frc::Solenoid *solenoid_intake_right_1;
        frc::Solenoid *solenoid_intake_left_0;
        frc::Solenoid *solenoid_intake_left_1;
        frc::Joystick *joystick;
    
};

#endif
