#ifndef WINCH
#define WINCH

#include "frc/WPILib.h"
#include <iostream>
#include "ctre/Phoenix.h"

using namespace frc;

class Winch {
	public:
		Winch (TalonSRX *talon_winch_enc, Joystick *joystick) :  talon_winch_enc(talon_winch_enc), joystick(joystick) {};
		void RaiseWinch(int tics);
		void LowerWinch();
	private:
		TalonSRX *talon_winch_enc;
		Joystick *joystick;
};
#endif
