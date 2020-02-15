#include "togglemotor.h"

using namespace frc;

void ToggleMotor::Toggle(double power, bool &motor_check, bool &button_check, int button_idx) {
        if (joystick->GetRawButton(button_idx) == false && button_check == true) {
            button_check = false;
        } else if (joystick->GetRawButton(button_idx) == true && motor_check == false && button_check == false) {
            talon->Set(ControlMode::PercentOutput, power); //power is set in robot.cpp-teleopinit
            motor_check = true;
            button_check = true;
            x = 0;
        } else if (joystick->GetRawButton(button_idx) == true && motor_check == true && button_check == false) {
            talon->Set(ControlMode::PercentOutput, 0);
            motor_check = false;
            button_check = true;
            x = 0;
        } 
    }
    } 
