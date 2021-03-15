#include <iostream>
#include <limelight.h>
#include <settings.h>
using namespace frc;

void Limelight::RunAlign(double  horizontal_offset) {
  
  if (horizontal_offset < 3 and  horizontal_offset > -1.5) {
    align = true;
    talon_drive_left_enc ->Set(ControlMode::PercentOutput, 0);
    talon_drive_right_enc ->Set(ControlMode::PercentOutput, 0);
    if (rumble_set < 50) {
      joystick1->SetRumble(GenericHID::kLeftRumble, 1);
      joystick1->SetRumble(GenericHID::kRightRumble, 1);
    }
    else{
      joystick1->SetRumble(GenericHID::kLeftRumble, 0);
      joystick1->SetRumble(GenericHID::kRightRumble, 0);
    }
    rumble_set++;
  } 
  else if ((horizontal_offset > 3 or horizontal_offset < -1.5) and align == true ){
    align = false;
  }
  else if (horizontal_offset > 0.15 and align == false) {
    rumble_set = 0;
      talon_drive_left_enc ->Set(ControlMode::PercentOutput, -1* horizontal_offset/ 20);
  }
  else if (horizontal_offset < -.15 and align == false){ 
    talon_drive_right_enc ->Set(ControlMode::PercentOutput,   horizontal_offset/ 20);
  }
  
   
  
}
