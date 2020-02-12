#include "togglemotor.h"

using namespace frc;

void ToggleMotor::Toggle(double power, bool &motor_check, bool &button_check, int &x) {
    if (x > 10){
        if (joystick->GetRawButton(1) == false && button_check == true) {
            button_check = false;
        } else if (joystick->GetRawButton(1) == true && motor_check == false && button_check == false) {
            talon->Set(ControlMode::PercentOutput, power); //power is set in robot.cpp-teleopinit
            motor_check = true;
            button_check = true;
            x = 0;
        } else if (joystick->GetRawButton(1) == true && motor_check == true && button_check == false) {
            talon->Set(ControlMode::PercentOutput, 0);
            motor_check = false;
            button_check = true;
            x = 0;
        } 
    } else {
        x += 1;
    }
}