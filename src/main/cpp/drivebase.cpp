/*
this is the variable sensitivity drive base program. 

-------------make sure to put multi = 1; in teleop init-------------

left, right, lcalc, rcalc, and x dont need to have a value set in robot.cpp, but do need to exist
*/

#include "drivebase.h"

using namespace frc;

void DriveBase::Drive(double left, double right, double lcalc, double rcalc, double &multi, double &x){
  right = (joystick->GetRawAxis(1) + joystick->GetRawAxis(4));
  left = (-1*joystick->GetRawAxis(1) - -1*joystick->GetRawAxis(4));
  if (multi > 0 && joystick->GetRawButton(1) == true && x > 10){
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

