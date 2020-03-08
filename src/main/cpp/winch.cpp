#include "winch.h"
//#include "settings.h"
using namespace frc;

void Winch::RaiseWinchAxis(){
	double axis = (double)joystick->GetRawAxis(1);
	float speed = axis; //fabs(axis)*0.75;
	std::cout<<speed<<std::endl;
	talon_winch_enc -> Set(ControlMode::PercentOutput, speed);
}

void Winch::RaiseWinchButton(int tics){
	//if(joystick -> GetRawButtonPressed(1)){
		talon_winch_enc -> Set(ControlMode::Position, tics);
	//}
}

void Winch::LowerWinch(){
	//talon_winch_enc -> Set(ControlMode::Position, 0);
}
