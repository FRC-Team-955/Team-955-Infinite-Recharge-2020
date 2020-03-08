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
			if(lidar -> GetDistance("in") > 20 && lidar -> GetDistance("in") < 80) mode = 2;
		} 
		if(mode == 2){
            int pos = lidar -> GetDistance("in")*100;
			elevator -> ToPosition(pos); //test position
			if(elevator -> Position() > pos - 100)mode = 3;
		} 
        if(mode == 3){
            elevator -> Elevate();
            if(joystick->GetRawButtonPressed(1)) mode = 4;
		} 
		if(mode == 4){
			elevator -> ToPosition(0);
            if(elevator -> Position()<10) mode = 5;
		} 
        if (mode == 5){
            winch -> RaiseWinchButton(2000);
        }
    }else if(!joystick->GetRawButton(2) && toggle){
        is_pressed = true; 
        winch -> RaiseWinchAxis();
		elevator -> Elevator();
    }
	
}

