#ifndef ELEVATOR
#define ELEVATOR
#include "frc/WPILib.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h" 

using namespace frc;

class Elevate{
    public:
        Elevate(TalonSRX *talon_drive_right_enc, frc::Joystick * joystick): talon_drive_right_enc(talon_drive_right_enc),joystick(joystick){};
        void Elevate();
    
    private:
        TalonSRX *talon_drive_right_enc;
        Joystick *joystick;
        int yp;
};
#endif
