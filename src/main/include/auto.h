#ifndef AUTO
#define AUTO

#include "ctre/Phoenix.h"
#include "frc/WPILib.h"
#include <frc/Joystick.h>
#include <iostream>

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Auto {
public:
    Auto(TalonSRX* drive_talon_right, TalonSRX* drive_talon_left)
        : drive_talon_right(drive_talon_right)
        , drive_talon_left(drive_talon_left) {};

    int CalculateEncoderCounts(int length_inches);

private:
    TalonSRX* drive_talon_right;
    TalonSRX* drive_talon_left;

    int gear_ratio;
    const int enc_per_rev_talon = 4096;
    int wheel_size;
};

#endif