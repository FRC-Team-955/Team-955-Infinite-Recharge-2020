#include "elevator_axis.h"
#include "settings.h"
using namespace frc;
void Elevate::elevator(){
  double y_axis = joystick->GetRawAxis(0);
  if(y_axis > 0.2){
  talon_elevator_enc->Set(ControlMode::PercentOutput,0.7);
  } else if (y_axis < -0.2){
    talon_elevator_enc -> Set(ControlMode::PercentOutput,-0.6);
  } else {
    talon_elevator_enc -> Set(ControlMode::PercentOutput,0);
  }

}

int Elevate::position(){

  return talon_elevator_enc -> GetSelectedSensorPosition();

}

void Elevate::MSsketch(){
  
    talon_elevator_enc -> Set(ControlMode::Position, target_pos);
} 

