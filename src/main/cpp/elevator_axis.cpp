#include "elevator_axis.h"
#include "settings.h"
using namespace frc;
void Elevate::elev(){
  
  int y_axis = joystick->GetRawAxis(1);
  if(y_axis > 0){
  talon_elevator_enc->Set(ControlMode::PercentOutput,y_axis/3);
  } else if (y_axis < 0){
    talon_elevator_enc -> Set(ControlMode::PercentOutput,y_axis/10);
  } else {
    talon_elevator_enc -> Set(ControlMode::PercentOutput,y_axis/10);
  }




}