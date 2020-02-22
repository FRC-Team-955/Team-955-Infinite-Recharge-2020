#include "shooter.h"

using namespace frc;

void Shooter::SpinMotorVelocity(double target_velocity){
    if (joystick1 -> GetRawAxis(3) > 0.1){

        talon_shooter_connected -> Set(ControlMode::PercentOutput, target_velocity);
        if (talon_shooter_connected -> GetSelectedSensorVelocity(0)  >  target_velocity  - 8 and talon_shooter_connected -> GetSelectedSensorVelocity(0)  <  target_velocity  +8 ){
            talon_hopper -> Set(ControlMode::PercentOutput, 1);
        }
    } else {
        talon_shooter_connected -> Set(ControlMode::PercentOutput, 0);
         talon_hopper -> Set(ControlMode::PercentOutput, 0);
    }

}

void Shooter::SpinMotorAxis(){
    talon_shooter_connected -> Set(ControlMode::PercentOutput , joystick1 -> GetRawAxis(toggle_rev_shooter_button_idx));
}
void Shooter::SpinMotorPercentOutput(){
    if (joystick1 -> GetRawButtonPressed(1) == 1){
        if (toggle_position_shooter == false){
            talon_shooter_connected -> Set(ControlMode::PercentOutput , 1);
        }
        if (toggle_position_shooter == true){
            talon_shooter_connected -> Set(ControlMode::PercentOutput,0);
        }
        toggle_position_shooter =!toggle_position_shooter;
    }
}