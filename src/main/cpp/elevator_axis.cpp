#include "elevator.h"
#include "settings.h"
//https://www.youtube.com/watch?v=dQw4w9WgXcQ
using namespace frc;
double Elevate::elev(){
  
  int yp = joy0->GetRawAxis(raise_lower_hook_axis);
  talon_elevator_enc->Set(ControlMode::PercentOutput,yp);





}