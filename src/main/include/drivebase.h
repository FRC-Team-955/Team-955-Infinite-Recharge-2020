#ifndef DRIVEBASE
#define DRIVEBASE
#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>
#include "settings.h"
using namespace frc;
class DriveBase {
   public:
   DriveBase (Joystick *joy, TalonSRX *talon_drive_right_noenc, TalonSRX *talon_drive_left_noenc) : joy(joy), talon_drive_right_noenc(talon_drive_right_noenc), talon_drive_left_noenc(talon_drive_left_noenc) {};
   void Drive(double multi);
       bool multi_check = false; //used to say if the motors should be multiplied by multi
       bool button_check = false; //prevents multis function from running more than once if the buttons pressed down
       double right; //power to the right front motor
       double left; //power to the left front motor
   private:
       Joystick *joy;
       TalonSRX *talon_drive_right_noenc;
       TalonSRX *talon_drive_left_noenc;
};
#endif