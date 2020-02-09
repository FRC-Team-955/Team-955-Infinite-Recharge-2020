#ifndef FUNCTIONTOGGLE
#define FUNCTIONTOGGLE

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <string>
#include <cmath>

using namespace frc;
class FunctionToggle {
   public:
       FunctionToggle (Joystick *joystick) : joystick(joystick) {};
       bool ToggleFunction();
   
   private:
        Joystick *joystick;
        bool is_pressed = false;
        bool toggle = false;
};
#endif
