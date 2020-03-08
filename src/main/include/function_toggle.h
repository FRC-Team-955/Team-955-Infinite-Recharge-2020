#ifndef FUNCTIONTOGGLE
#define FUNCTIONTOGGLE

#include <iostream>
#include <frc/Joystick.h>
#include <limelight.h>
#include <drivebase.h>


class FunctionToggle {
    public:
       FunctionToggle (frc::Joystick *joystick, Limelight*limelight, DriveBase*drivebase ) : joystick(joystick), limelight(limelight), drivebase(drivebase){};
       void ToggleFunction(double horizontal_offset);
   
    private:
        frc::Joystick *joystick;
        Limelight *limelight;
        DriveBase *drivebase;
        bool is_pressed = false;
        bool toggle = false;
};
#endif
