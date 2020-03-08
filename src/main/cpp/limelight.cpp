#include <iostream>
#include <limelight.h>
#include <settings.h>
using namespace frc;

void Limelight::RunAlign(double  horizontal_offset) {
  
  if (horizontal_offset < 3 and  horizontal_offset > -3) {
    align = true;
    
  } 
  else if (horizontal_offset > 0.15 and align == false) {
      talon_drive_left_enc ->Set(ControlMode::PercentOutput, -1* horizontal_offset/ 20);
  }
  else if (horizontal_offset < -.15 and align == false){ 
    talon_drive_right_enc ->Set(ControlMode::PercentOutput,   horizontal_offset/ 20);
  }
  
  
  if (joystick0->GetRawButton(align_button_idx)==1){
    align = false;
  }
   
  
}
