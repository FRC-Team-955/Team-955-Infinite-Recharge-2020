#include "Shooter.h"

using namespace frc;
/*void Shooter::Spin_Motor_Velocity(){
    talon_shooter_right -> Set(ControlMode::Velocity,500);
    //talon_shooter_left -> Set(ControlMode::Follower, talon_shooter_noconnected_num);
}*/
void Shooter::Spin_Motor_PercentOutput(){
    if (joy -> GetRawButton(toggle_rev_shooter_button_idx) == 1 and Toogle_Position_Shooter == false){
    talon_shooter_right -> Set(ControlMode::PercentOutput , 1);
    //talon_shooter_left -> Set(ControlMode::Follower, talon_shooter_noconnected_num);
    Toogle_Position_Shooter = true;
    }
}
void Shooter::Off_Motor(){
    if (joy -> GetRawButton(toggle_rev_shooter_button_idx) == 1 and Toogle_Position_Shooter == true){
    talon_shooter_right -> Set(ControlMode::PercentOutput,0);
     //talon_shooter_left -> Set(ControlMode::Follower, talon_shooter_noconnected_num);
     Toogle_Position_Shooter = false;
    }
   
}