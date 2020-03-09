#include "function_toggle.h"
#include "settings.h"
using namespace frc;

void FunctionToggle::ToggleFunction(double horizontal_offset){
    if (is_pressed && joystick->GetRawButton(align_button_idx)) {  
        is_pressed = false;
    if (toggle) {  
        toggle = false;
    } else {
        toggle = true;
    }
    }else if(!joystick->GetRawButton(align_button_idx) && !toggle) { 
        is_pressed = true; 
        drivebase->Drive(1);
        joystick1->SetRumble(GenericHID::kLeftRumble, 0);
        joystick1->SetRumble(GenericHID::kRightRumble, 0);
    }else if(!joystick->GetRawButton(align_button_idx) && toggle){
        is_pressed = true; 
        limelight->RunAlign(horizontal_offset);
    }
}
