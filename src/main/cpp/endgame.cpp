#include "endgame.h"
//#include "settings.h"
using namespace frc;

void EndGame::Climb(){  
	if (is_pressed && joystick->GetRawButton(2)) {  
        is_pressed = false;
    if (toggle) {  
        toggle = false;
    } else {
        toggle = true;
    }
    }else if(!joystick->GetRawButton(2) && !toggle) { 
        is_pressed = true; 
        if(mode == 1){
			if(lidar -> GetDistance("in") > 20 && lidar -> GetDistance("in") < 80){
                //talon_drive_left -> Set(ControlMode::Position, CalculateEncoderCounts(2));
                //talon_drive_right -> Set(ControlMode::Position, CalculateEncoderCounts(2));
                talon_drive_left -> Set(ControlMode::Velocity, 0);
                talon_drive_right -> Set(ControlMode::Velocity, 0);
                mode = 2;
            }else{
                MoveSlow();
            }
		} 
		if(mode == 2){
            int pos = 69000; //lidar -> GetDistance("in")*10000; //high: 69000 tics 66 in
			elevator -> ToPosition(pos); //test position
			if(elevator -> Position() > pos - 1000){
                talon_drive_left -> SetSelectedSensorPosition(0,0,10);
                talon_drive_right -> SetSelectedSensorPosition(0,0,10);
                mode = 3;
            }    
		} 
        if(mode == 3){
            elevator -> Elevate();
            talon_drive_left -> Set(ControlMode::Position, CalculateEncoderCounts(4));
            talon_drive_right -> Set(ControlMode::Position, CalculateEncoderCounts(4));
            if(talon_drive_left -> GetSelectedSensorPosition() < CalculateEncoderCounts(4)){
                talon_drive_left -> Set(ControlMode::Velocity, 0);
                talon_drive_right -> Set(ControlMode::Velocity, 0);
            }

            if(joystick->GetRawButtonPressed(1)) mode = 4;
		} 
		if(mode == 4){
			elevator -> ToPosition(0);
            if(elevator -> Position()<75) mode = 5;
		}
        if (mode == 5){
            winch -> RaiseWinchButton(4000);
        }
    }else if(!joystick->GetRawButton(2) && toggle){
        is_pressed = true; 
        winch -> RaiseWinchAxis();
		elevator -> Elevate();
    }
	
}

void EndGame::MoveSlow(){
    talon_drive_left -> Set(ControlMode::Velocity, -25);
    talon_drive_right -> Set(ControlMode::Velocity, -25);
}
int EndGame::CalculateEncoderCounts(int length_inches){
	return -1*length_inches * (1 / (7.5 * 3.14159)) * 707;
}


