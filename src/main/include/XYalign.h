#ifndef XYALIGHN
#define XYALIGHN
#include "frc/WPILib.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include <AHRS.h>
#include <ctre/Phoenix.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <iostream>
using namespace frc;
class XYalign {
public:
    XYalign(TalonSRX* talon_drive_right_enc,
        TalonSRX* talon_drive_right_noenc,
        TalonSRX* talon_drive_left_enc,
        TalonSRX* talon_drive_left_noenc,
        frc::Joystick* joy0)
        : talon_drive_right_enc(talon_drive_right_enc)
        , talon_drive_right_noenc(talon_drive_right_noenc)
        , talon_drive_left_enc(talon_drive_left_enc)
        , talon_drive_left_noenc(talon_drive_left_noenc)
        , joy0(joy0) {};
    double left_drive;
    double right_drive;
    bool Align;
    double test();

private:
    TalonSRX* talon_drive_right_enc;
    TalonSRX* talon_drive_left_enc;
    TalonSRX* talon_drive_left_noenc;
    TalonSRX* talon_drive_right_noenc;
    Joystick* joy0;
    double vertical_offset;
    double HorizontalOffset;
};
#endif