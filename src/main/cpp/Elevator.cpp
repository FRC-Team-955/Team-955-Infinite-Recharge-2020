#include "Elevator.h"
//https://www.youtube.com/watch?v=dQw4w9WgXcQ
using namespace frc;
double Elevate::elev(){
  int yp = joy0->GetRawAxis(1);
  talon_drive_right_enc->Set(ControlMode::PercentOutput,yp);
}
