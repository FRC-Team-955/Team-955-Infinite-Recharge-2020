#ifndef SHOOTER
#define SHOOTER
#include <string>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <cmath>
#include "settings.h"
using namespace frc;

class Shooter{
    public:
    Shooter(TalonSRX * talon_shooter_left,TalonSRX * talon_shooter_right, frc::Joystick * joy): talon_shooter_left(talon_shooter_left), talon_shooter_right(talon_shooter_right), joy(joy){};
    void SpinMotorVelocity();
    void SpinMotorPercentOutput();
    void SpinMotorAxis();
    private:
    bool toggle_position_shooter = false;
 
    TalonSRX * talon_shooter_left;
    TalonSRX * talon_shooter_right;
   Joystick * joy;
};

#endif