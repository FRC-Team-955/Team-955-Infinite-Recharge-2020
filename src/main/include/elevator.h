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
        Joystick * joystick, int target_pos
        ): 
        talon_elevator_enc(talon_elevator_enc),
        joystick(joystick),target_pos(target_pos){};
    double left_drive;
    double right_drive;
    bool Align;
    void elevator();
    int position();
    void MSsketch();
    int target_pos;
    private:
    Joystick *joystick;
    TalonSRX * talon_elevator_enc;
    
};
#endif