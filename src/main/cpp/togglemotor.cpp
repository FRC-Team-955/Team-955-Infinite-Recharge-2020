#include "togglemotor.h"
#include "settings.h"
using namespace frc;

void ToggleMotor::Toggle(int toggle_motor_button, TalonSRX *talon_toggle, double power) {
	/*if (joystick->GetRawButton(toggle_motor_button) == false && button_check == true) {
		button_check = false;
	} else if (joystick->GetRawButton(toggle_motor_button) == true && motor_check == false && button_check == false) {
		talon_toggle->Set(ControlMode::PercentOutput, power);
		motor_check = true;
		button_check = true;
	} else if (joystick->GetRawButton(toggle_motor_button) == true && motor_check == true && button_check == false) {
		talon_toggle->Set(ControlMode::PercentOutput, 0);
		motor_check = false;
		button_check = true;
	}*/

	if (is_pressed && joystick->GetRawButton(toggle_motor_button)) {  
    	is_pressed = false;
    	if (toggle) {  
      	toggle = false;
    	} else {
      	toggle = true;
    	}
  	}else if(!joystick->GetRawButton(toggle_motor_button) && !toggle) { 
    	is_pressed = true; 
    	talon_toggle->Set(ControlMode::PercentOutput, power);
  	}else if(!joystick->GetRawButton(toggle_motor_button) && toggle){
      	is_pressed = true; 
      	talon_toggle->Set(ControlMode::PercentOutput, power);
  	}
}