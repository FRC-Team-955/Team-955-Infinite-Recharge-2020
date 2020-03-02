#ifndef ELEVATOR
#define ELEVATOR
#include "frc/WPILib.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h" 

class Elevator{
    public:
    Elevator(TalonSRX * talon_elevator_enc,
        Joystick * joystick, int limit
        ): 
        talon_elevator_enc(talon_elevator_enc),
        joystick(joystick),limit(limit){};
    double left_drive;
    double right_drive;
    bool Align;
    void Elevate();
    int Position();
    void ToPosition(int target_pos);
    int limit;
    private:
    Joystick *joystick;
    TalonSRX * talon_elevator_enc;
    
};
#endif