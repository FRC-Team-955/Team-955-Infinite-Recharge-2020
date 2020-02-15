#ifndef TOGGLEMOTOR
#define TOGGLEMOTOR
#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"

class ToggleMotor {
   public:
     ToggleMotor (frc::Joystick *joystick, TalonSRX *talon) : joystick(joystick), talon(talon) {};
     void Toggle(int toggle_motor_button);

   private:
     bool motor_check = false;
     bool button_check = false;
     double power = 0.25;
     frc::Joystick *joystick;
     TalonSRX *talon;
     
};
#endif