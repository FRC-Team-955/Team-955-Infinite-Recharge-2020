#include "FunctionToggle.h"
using namespace frc;

bool FunctionToggle::ToggleFunction(){
  if (is_pressed && joystick->GetRawButton(3)) {  
    is_pressed = false;
    if (toggle) {  
      toggle= false;
    } else {
      toggle= true;
    }
  } else if(!joystick->GetRawButton(3)&& !toggle) { 
      is_pressed = true; 
      // default function code
  }else if(!joystick->GetRawButton(3)&& toggle){
    is_pressed = true; 
    // toggle function code
  }
}