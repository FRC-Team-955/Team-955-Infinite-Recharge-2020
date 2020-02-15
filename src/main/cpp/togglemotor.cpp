#include "togglemotor.h"
#include "settings.h"
using namespace frc;

void ToggleMotor::Toggle(int toggle_motor_button) {
    if (joystick->GetRawButton(hopper_button_idx) == false && button_check == true) {
        button_check = false;
    } else if (joystick->GetRawButton(hopper_button_idx) == true && motor_check == false && button_check == false) {
        talon->Set(ControlMode::PercentOutput, power); //power is set in robot.cpp-teleopinit
        motor_check = true;
        button_check = true;
    } else if (joystick->GetRawButton(hopper_button_idx) == true && motor_check == true && button_check == false) {
        talon->Set(ControlMode::PercentOutput, 0);
        motor_check = false;
        button_check = true;
    }
}