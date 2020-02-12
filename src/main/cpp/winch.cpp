#include "winch.h"
#include "settings.h"
using namespace frc;

void Winch::RaiseWinch(int tics){
	//talon_winch_enc -> Set(ControlMode::Position, tics);
	talon_winch_enc -> Set(ControlMode::PercentOutput, joystick -> GetRawAxis(pull_winch_in_axis_idx));
}
void Winch::LowerWinch(){
	//talon_winch_enc -> Set(ControlMode::Position, 0);
}
