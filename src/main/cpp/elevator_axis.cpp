#include "elevator_axis.h"
#include "settings.h"
//https://www.youtube.com/watch?v=dQw4w9WgXcQ
using namespace frc;
double Elevate::elev(){
  
  int yp = joy0->Get
  talon_elevator_enc->Set(ControlMode::PercentOutput,yp/3);
  } else if (yp < 0){
    talon_elevator_enc -> Set(ControlMode::PercentOutput,yp/10);
  } else {
    talon_elevator_enc -> Set(ControlMode::PercentOutput,yp/10);
  }




}