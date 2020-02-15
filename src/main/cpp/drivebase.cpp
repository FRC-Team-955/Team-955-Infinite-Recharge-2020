/*
this is the variable sensitivity drive base program. 

-------------make sure to put multi = 1; in teleop init-------------

left, right, lcalc, rcalc, and x dont need to have a value set in robot.cpp, but do need to exist
*/

#include "drivebase.h"
#include "settings.h"
using namespace frc;

void DriveBase::Drive(double &multi, double &x){
	right = (joystick->GetRawAxis(forward_back_drivebase_axis_idx) + joystick->GetRawAxis(left_right_drivebase_axis_idx));
	left = (-1*joystick->GetRawAxis(forward_back_drivebase_axis_idx) - -1*joystick->GetRawAxis(left_right_drivebase_axis_idx));
	if (multi > 0 && joystick->GetRawButton(sensitivity_scale_cont_button_idx) == true && x > 10){
		multi = multi / 3;        //the input is a decimal so it strts on slower mode and goes up to faster mode when divided by 3.... because of maths
		x = 0;
	} 
	else {
		x += 1;
	} 
	if (multi < 0.125){
		multi = 1;
	}
	right = right / multi;
	left = left / multi;
	left = std::min(1.0, left);
	right = std::min(1.0, right);
	left = std::max(-1.0, left);
	right = std::max(-1.0, right);
	rcalc = right;
	lcalc = left;
	lcalc = lcalc * 0.75;
	rcalc = rcalc * 0.75;
	talon_drivebase_left_connected->Set(ControlMode::PercentOutput, lcalc);
	talon_drivebase_right_connected->Set(ControlMode::PercentOutput, rcalc);
	std::cout<<multi<<"  "<<right<<"  "<<left<<"  "<<std::endl;
}