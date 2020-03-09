#ifndef FUNCTIONTOGGLE
#define FUNCTIONTOGGLE

#include <iostream>
#include <frc/Joystick.h>
#include <limelight.h>
#include <drivebase.h>


class FunctionToggle {
    public:
       FunctionToggle (frc::Joystick *joystick, frc::Joystick *joystick1, Limelight*limelight, DriveBase*drivebase ) : joystick(joystick), joystick1(joystick1), limelight(limelight), drivebase(drivebase){};
       void ToggleFunction(double horizontal_offset);
   
    private:
        frc::Joystick *joystick;
        frc::Joystick *joystick1;
        Limelight *limelight;
        DriveBase *drivebase;
        bool is_pressed = false;
        bool toggle = false;
};
#endif
