#ifndef WINCH
#define WINCH

#include "frc/WPILib.h"
#include <iostream>
#include "ctre/Phoenix.h"

class Winch {
    public:
	    Winch (TalonSRX *talon_winch_enc, frc::Joystick *joystick) :  talon_winch_enc(talon_winch_enc), joystick(joystick) {};
	    void RaiseWinchAxis();
	    void RaiseWinchButton(int tics);
	    void LowerWinch();
    private:
	    TalonSRX *talon_winch_enc;
	    frc::Joystick *joystick;
};
#endif
