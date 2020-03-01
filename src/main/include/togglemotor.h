#ifndef TOGGLEMOTOR
#define TOGGLEMOTOR
#include <iostream>
#include <frc/Joystick.h>
#include "ctre/Phoenix.h"

class ToggleMotor {
	public:
		ToggleMotor (frc::Joystick *joystick) : joystick(joystick) {};
		void Toggle(int toggle_motor_button, TalonSRX *talon_toggle, double power);

	private:
		frc::Joystick *joystick;

		bool is_pressed = false;
		bool toggle = false;
};
#endif