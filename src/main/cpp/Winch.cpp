#include "Winch.h"
using namespace frc;

void Winch::RaiseWinch(int tics){
	talon_winch_enc -> Set(ControlMode::Position, tics);
}
void Winch::LowerWinch(){
	talon_winch_enc -> Set(ControlMode::Position, 0);
}
