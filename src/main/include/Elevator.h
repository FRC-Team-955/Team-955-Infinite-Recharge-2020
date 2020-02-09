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
        Elevate(TalonSRX *talon_drive_right_enc, frc::Joystick * joy0): talon_drive_right_enc(talon_drive_right_enc),joy0(joy0){};
        double left_drive;
        double right_drive;
        bool Align;
        double elev();
    
    private:
        TalonSRX *talon_drive_right_enc;
        TalonSRX *talon_drive_left_enc;
        TalonSRX *talon_drive_left_noenc;
        TalonSRX *talon_drive_right_noenc;
        Joystick *joy0;
        AHRS *ahrs; 
        double degree;
        double vertical_offset;
        double HorizontalOffset;
        double targetOffsetAngle_Horizontal;

};
#endif
