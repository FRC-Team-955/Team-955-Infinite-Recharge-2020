#ifndef FUNCTIONTOGGLE
#define FUNCTIONTOGGLE

#include <iostream>
#include "frc/WPILib.h"

class FunctionToggle {
    public:
       FunctionToggle (frc::Joystick *joystick) : joystick(joystick) {};
       bool ToggleFunction();
   
    private:
        frc::Joystick *joystick;
        bool is_pressed = false;
        bool toggle = false;
};
#endif
