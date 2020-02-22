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
    Shooter(TalonFX * talon_shooter_connected, TalonFX * talon_shooter_noconnected,TalonSRX *talon_hopper, frc::Joystick * joystick1):  talon_shooter_connected(talon_shooter_connected),talon_shooter_noconnected(talon_shooter_noconnected),talon_hopper(talon_hopper), joystick1(joystick1){};
    void SpinMotorVelocity(  double target_velocity);
    void SpinMotorPercentOutput();
    void SpinMotorAxis();

    double target_velocity;
    private:

    bool toggle_position_shooter = false;
    TalonFX * talon_shooter_connected;
    TalonFX * talon_shooter_noconnected;
    TalonSRX * talon_hopper;
    Joystick * joystick1;
};

#endif