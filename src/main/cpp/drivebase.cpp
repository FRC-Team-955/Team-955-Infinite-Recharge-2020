/*
this is the variable sensitivity drive base program. 

-------------make sure to put multi = 1; in teleop init-------------

left, right, lcalc, rcalc, and x dont need to have a value set in robot.cpp, but do need to exist
*/

#include "drivebase.h"
#include "settings.h"


using namespace frc;


void DriveBase::Drive(double multi){
	right = (joy->GetRawAxis(forward_back_drivebase_axis_idx) + -joy->GetRawAxis(left_right_drivebase_axis_idx));
	left = (-joy->GetRawAxis(forward_back_drivebase_axis_idx) + -joy->GetRawAxis(left_right_drivebase_axis_idx));
	if (joy->GetRawButton(variable_speed_button_idx) == false && button_check == true){
		button_check = false;
	} else if (joy->GetRawButton(variable_speed_button_idx) == true && multi_check == true && button_check == false){
		multi_check = false;
		button_check = true;
	} else if (joy->GetRawButton(variable_speed_button_idx) == true && multi_check == false && button_check == false){
		multi_check = true; 
		button_check = true;
	} 
	right = right * right * right;
	left = left * left * left;
	left = std::min(1.0, left);
	right = std::min(1.0, right);
	left = std::max(-1.0, left);
	right = std::max(-1.0, right);
	if (multi_check == true){
		left = left * multi;
		right = right * multi;
  	}
	talon_drive_right_noenc->Set(ControlMode::PercentOutput, -1 * left);
	talon_drive_left_noenc->Set(ControlMode::PercentOutput, right * 1);
	std::cout<<multi<<"  "<<right<<"  "<<left<<"  "<<std::endl;
}