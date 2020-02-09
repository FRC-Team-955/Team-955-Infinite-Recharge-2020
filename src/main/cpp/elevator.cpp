#include "elevator.h"
//https://www.youtube.com/watch?v=dQw4w9WgXcQ
using namespace frc;
void Elevate::Elevate(){
  yp = joystick->GetRawAxis(1);
  talon_drive_right_enc->Set(ControlMode::PercentOutput,yp);
}
