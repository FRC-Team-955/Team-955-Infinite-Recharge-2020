#include "elevator.h"
#include "settings.h"
using namespace frc;
void Elevator::Elevate(){
  double y_axis = joystick->GetRawAxis(0);
  if(y_axis > 0.2 && talon_elevator_enc -> GetSelectedSensorPosition() < limit){
  talon_elevator_enc->Set(ControlMode::PercentOutput,1);
  } else if (y_axis < -0.2){
    talon_elevator_enc -> Set(ControlMode::PercentOutput,-0.6);
  } else {
    talon_elevator_enc -> Set(ControlMode::PercentOutput,0);
  }
  

}

int Elevator::Position(){

  return talon_elevator_enc -> GetSelectedSensorPosition();

}

void Elevator::ToPosition(int target_pos){
    
    talon_elevator_enc -> Set(ControlMode::Position, target_pos);
} 
