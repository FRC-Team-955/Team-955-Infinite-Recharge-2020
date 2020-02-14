#ifndef ELEVATOR_AXIS
#define ELEVATOR_AXIS
#include "frc/WPILib.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h" 

class Elevate{
    public:
    Elevate(TalonSRX * talon_elevator_enc,
        Joystick * joystick
        ): 
        talon_elevator_enc(talon_elevator_enc),
        joystick(joystick){};
    double left_drive;
    double right_drive;
    bool Align;
    void elev();
    private:
    Joystick *joystick;
    TalonSRX * talon_elevator_enc;
    
};
#endif