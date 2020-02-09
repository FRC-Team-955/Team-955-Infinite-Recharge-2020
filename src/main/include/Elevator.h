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
        double left_drive;
        double right_drive;
        bool align;
        double elev();
    
    private:
        TalonSRX *talon_drive_right_enc;
        TalonSRX *talon_drive_left_enc;
        TalonSRX *talon_drive_left_noenc;
        TalonSRX *talon_drive_right_noenc;
        Joystick *joystick;
        AHRS *ahrs; 
        double degree;
        double vertical_offset;
        double horizontal_offset;
        double targetOffsetAngle_Horizontal;

};
#endif
