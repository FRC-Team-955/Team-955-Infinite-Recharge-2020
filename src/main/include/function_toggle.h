#ifndef FUNCTIONTOGGLE
#define FUNCTIONTOGGLE

#include <iostream>
#include <frc/Joystick.h>


class FunctionToggle {
    public:
       FunctionToggle (frc::Joystick *joystick) : joystick(joystick) {};
       void ToggleFunction();
   
    private:
        frc::Joystick *joystick;
        bool is_pressed = false;
        bool toggle = false;
};
#endif
