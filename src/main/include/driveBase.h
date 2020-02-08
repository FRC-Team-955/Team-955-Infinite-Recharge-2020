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
   DriveBase (Joystick *joy, TalonSRX *tal1, TalonSRX *tal3) : joy(joy), tal1(tal1), tal3(tal3) {};
   void Drive(double left, double right, double lcalc, double rcalc, double &multi, double &x);
       //Public variables and functions
   private:
       Joystick *joy;
       TalonSRX *tal1;
       TalonSRX *tal3;
};
#endif