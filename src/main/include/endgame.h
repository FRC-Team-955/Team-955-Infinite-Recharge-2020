#ifndef ENDGAME
#define ENDGAME

#include "frc/WPILib.h"
#include <iostream>
#include "ctre/Phoenix.h"
#include <cmath>
#include "winch.h"
#include "elevator.h"
#include "Lidar.h"

class EndGame {
	public:
		EndGame (Elevator *elevator, Winch *winch, Lidar *lidar, frc::Joystick *joystick) :  elevator(elevator), winch(winch), lidar(lidar), joystick(joystick) {};
		void Climb();
		int mode = 1;
	private:
		Elevator *elevator;
		Winch *winch;
		Lidar *lidar;
		frc::Joystick *joystick;
		
		bool is_pressed = false;
		bool toggle = false;
		
};
#endif
