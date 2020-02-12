#ifndef ELEVATOR_AXIS
#define ELEVATOR_AXIS
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
    Elevate(TalonSRX * talon_elevator_enc,
        frc::Joystick * joy0
        ): 
        talon_elevator_enc(talon_elevator_enc),
        joy0(joy0){};
    double left_drive;
    double right_drive;
    bool Align;
    double elev();
    private:
    Joystick *joy0;
    
};
#endif