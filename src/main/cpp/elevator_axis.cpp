#include "elevator_axis.h"
#include "settings.h"
using namespace frc;
void Elevate::elevator(){
  int y_axis = joystick->GetRawAxis(0);
  if(y_axis > 0){
  talon_elevator_enc->Set(ControlMode::PercentOutput,y_axis/3);
  } else if (y_axis < 0){
    talon_elevator_enc -> Set(ControlMode::PercentOutput,y_axis/10);
  } else {
    talon_elevator_enc -> Set(ControlMode::PercentOutput,y_axis/10);
  }

}

int Elevate::position(){

  return talon_elevator_enc -> GetSelectedSensorPosition();

}

void Elevate::MSsketch(){
  
    talon_elevator_enc -> Set(ControlMode::Position, target_pos);
} 
