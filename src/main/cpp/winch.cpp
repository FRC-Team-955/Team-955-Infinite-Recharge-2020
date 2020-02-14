#include "winch.h"
#include "settings.h"
using namespace frc;

void Winch::RaiseWinchAxis(){
	talon_winch_enc -> Set(ControlMode::PercentOutput, joystick -> GetRawAxis(pull_winch_in_axis_idx));
}

void Winch::RaiseWinchButton(int tics){
	if(joystick -> GetRawButtonPressed(pull_winch_in_button_idx)){
	    talon_winch_enc -> Set(ControlMode::Position, tics);
	}
}

void Winch::LowerWinch(){
	//talon_winch_enc -> Set(ControlMode::Position, 0);
}
