#ifndef TOGGLEMOTOR
#define TOGGLEMOTOR
#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>
using namespace frc;
class ToggleMotor {
   public:
   ToggleMotor (Joystick *joystick, TalonSRX *talon) : joystick(joystick), talon(talon) {};
   void Toggle(double power, bool &motor_check, bool &button_check, int button_idx);
       //Public variables and functions
   private:
       Joystick *joystick;
       TalonSRX *talon;
};
#endif