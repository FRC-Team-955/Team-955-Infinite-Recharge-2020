#include "XYalign.h"
//https://www.youtube.com/watch?v=dQw4w9WgXcQ
using namespace frc;
double XYalign::test(){
std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
degree = ahrs->GetAngle();
double vertical_offset = table->GetNumber("ty", 0.0);
  double drive_adjustment =  vertical_offset ;
  int xp = joy0->GetRawAxis(4);
  int yp = joy0->GetRawAxis(1);
  bool targetSet = false;
  HorizontalOffset = table->GetNumber("tx", 0.0);
  std::cout << "Math1: " << HorizontalOffset - degree << std::endl;
  talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp+xp));
  talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp-yp));
  if (table -> GetNumber("tv", 0.0)){
    if(targetSet == false){
       targetOffsetAngle_Horizontal = table->GetNumber("tx",0.0);
       targetSet = true;
       ahrs->ZeroYaw();
    }
   if (HorizontalOffset - degree < 0.1 and HorizontalOffset - degree > -0.1) {
    Align = true;
    std::cout << "Aligned" << std::endl;
    //talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp+xp));
    //talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp-yp));
  }
  else if (HorizontalOffset -degree > 0.20 /*and Align == false*/) {
      //left_drive=  HorizontalOffset/ 45;
    std::cout << "Going left" << std::endl;

            left_drive = (HorizontalOffset -degree) * -0.05 ;
            right_drive = 0;
  }

  else if (HorizontalOffset - degree < -.20 /*and Align == false*/){
    //right_drive = HorizontalOffset/ 45;
    std::cout << "Going right" << std::endl;
    
    right_drive = (HorizontalOffset -degree) * -0.05;
    left_drive = 0;
  } else {
      right_drive = 0;
      left_drive = 0;
  }
  }
  if (joy0->GetRawButton(2)==1){
    Align = false;
  }
  if (joy0->GetRawButton(1)==1){
    targetSet = false;
  }
  std::cout<<HorizontalOffset<<std::endl; 
  std::cout<< "Right: "<<right_drive<<std::endl;
  std::cout<< "Left: "<<left_drive<<std::endl;


  if(joy0->GetRawButton(3)==1){
  talon_drive_right_enc->Set(ControlMode::PercentOutput, (.15 * drive_adjustment - right_drive));
  talon_drive_left_enc->Set(ControlMode::PercentOutput, (-.15 * drive_adjustment - left_drive));
  }
  std::cout<<drive_adjustment<<std::endl;
  std::cout<<"Target: "<<targetSet<<std::endl;





}