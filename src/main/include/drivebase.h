#ifndef DRIVEBASE
#define DRIVEBASE

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>

using namespace frc;

class DriveBase {
   public:
   DriveBase (Joystick *joystick, TalonSRX *talon_drivebase_left_connected, TalonSRX *talon_drivebase_right_connected) : joystick(joystick), talon_drivebase_left_connected(talon_drivebase_left_connected), talon_drivebase_right_connected(talon_drivebase_right_connected) {};
   void Drive(double left, double right, double lcalc, double rcalc, double &multi, double &x);
       
   private:
       Joystick *joystick;
       TalonSRX *talon_drivebase_left_connected;
       TalonSRX *talon_drivebase_right_connected;
};
#endif
