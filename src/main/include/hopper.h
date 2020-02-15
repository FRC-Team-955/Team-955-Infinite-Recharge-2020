#ifndef HOPPER
#define HOPPER
#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>
#include "togglemotor.h"
class Hopper {
   public:
   Hopper (ToggleMotor *toggle_motor, TalonSRX *talon_hopper_enc) : toggle_motor(toggle_motor), talon_hopper_enc(talon_hopper_enc) {};
   void Toggle();
   
   private:
       ToggleMotor *toggle_motor;
       TalonSRX *talon_hopper_enc;
};
#endif