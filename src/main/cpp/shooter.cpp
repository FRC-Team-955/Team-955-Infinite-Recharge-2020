#include "shooter.h"

using namespace frc;
void Shooter::SpinMotorVelocity(){
talon_shooter_right -> Set(ControlMode::Velocity,500);
}
void Shooter::SpinMotorAxis(){
    talon_shooter_right -> Set(ControlMode::PercentOutput , joy -> GetRawAxis(toggle_rev_shooter_button_idx));
}
void Shooter::SpinMotorPercentOutput(){
    if (joy -> GetRawButtonPressed(1) == 1){
        if (toggle_position_shooter == false){
            talon_shooter_right -> Set(ControlMode::PercentOutput , 1);
        }
        if (toggle_position_shooter == true){
            talon_shooter_right -> Set(ControlMode::PercentOutput,0);
        }
   toggle_position_shooter =!toggle_position_shooter;
    }
}

