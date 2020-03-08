#include "shooter.h"

using namespace frc;

bool Shooter::SpinMotorVelocity(double target_velocity){
    if (joystick1 -> GetRawAxis(3) > 0.1){
        talon_shooter_connected -> Set(ControlMode::Velocity, target_velocity);
        double upperBound = target_velocity + target_velocity *0.08; 
        double lowerBound = target_velocity - target_velocity *0.08; 
        int currentVelocity = talon_shooter_connected -> GetSelectedSensorVelocity(0);
        if (abs(currentVelocity) < abs(upperBound) && abs(currentVelocity) > abs(lowerBound)){
            talon_hopper -> Set(ControlMode::PercentOutput, -0.4);
            std::cout<<"Testing"<<std::endl;
        }
        return true;
    } else {
        talon_shooter_connected -> Set(ControlMode::PercentOutput, 0);
         talon_hopper -> Set(ControlMode::PercentOutput, 0);
         return false;
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