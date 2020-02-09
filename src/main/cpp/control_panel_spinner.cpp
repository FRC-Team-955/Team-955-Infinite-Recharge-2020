#include "control_panel_spinner.h"

using namespace frc;

bool ControlPanelSpinner::PositionControl(bool is_match){
  if(is_match){
    talon_wheelspinner_enc -> Set(ControlMode::PercentOutput, 0);
    return 1;
  }
 else{
    talon_wheelspinner_enc -> Set(ControlMode::PercentOutput, .5);
    return 0;
     }
 }
bool ControlPanelSpinner::RotationControl(int color_count, int max_count){
    if(color_count <= max_count){
      talon_wheelspinner_enc -> Set(ControlMode::PercentOutput, .5);
      return 1;
    }
 else{
      talon_wheelspinner_enc -> Set(ControlMode::PercentOutput, 0);
      return 0;
      }
  }
void ControlPanelSpinner::MoveDown(){
    arm_solenoid_up ->Set(1);
    arm_solenoid_down ->Set(0);
  }
void ControlPanelSpinner::MoveUp(){
    arm_solenoid_down ->Set(1);
    arm_solenoid_up ->Set(0);
  }
