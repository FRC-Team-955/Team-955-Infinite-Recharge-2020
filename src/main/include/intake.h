#ifndef INTAKE
#define INTAKE

#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include <frc/Solenoid.h>

class Intake {
	public:
		Intake (TalonSRX *intake_talon, frc::Solenoid *solenoid_intake_right_0, frc::Solenoid *solenoid_intake_right_1, frc::Solenoid *solenoid_intake_left_0, frc::Solenoid *solenoid_intake_left_1, frc::Joystick *joystick) 
		: intake_talon(intake_talon), solenoid_intake_right_0(solenoid_intake_right_0), solenoid_intake_right_1(solenoid_intake_right_1), solenoid_intake_left_0(solenoid_intake_left_0), solenoid_intake_left_1(solenoid_intake_left_1), joystick(joystick) {};

		bool deploy_state = 0;
		void DeployIntakePNE();
		bool is_pressed = 0;
		bool toggle = 0;
		void RunIntake(float output_percentage);
	
	
	private:
		
		TalonSRX *intake_talon;
		frc::Solenoid *solenoid_intake_right_0;
		frc::Solenoid *solenoid_intake_right_1;
		frc::Solenoid *solenoid_intake_left_0;
		frc::Solenoid *solenoid_intake_left_1;
		frc::Joystick *joystick;
	
};

#endif
