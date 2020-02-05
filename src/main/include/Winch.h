#ifndef WINCH
#define WINCH

#include "frc/WPILib.h"
#include <iostream>
#include <cmath>
#include <string>
#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>

class Winch {
	public:
		Winch (TalonSRX *talon_winch_enc) :  talon_winch_enc(talon_winch_enc) {};
		void RaiseWinch(int tics);
		void LowerWinch();

	private:
		TalonSRX *talon_winch_enc;

};

#endif