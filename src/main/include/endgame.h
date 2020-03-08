#ifndef ENDGAME
#define ENDGAME

#include "frc/WPILib.h"
#include <iostream>
#include "ctre/Phoenix.h"
#include <cmath>
#include "winch.h"
#include "elevator.h"
#include "lidar.h"
//#include "auto.h"

class EndGame {
	public:
		EndGame (Elevator *elevator, Winch *winch, Lidar *lidar, frc::Joystick *joystick, TalonSRX *talon_drive_left, TalonSRX *talon_drive_right) :  elevator(elevator), winch(winch), lidar(lidar), joystick(joystick), talon_drive_left(talon_drive_left), talon_drive_right(talon_drive_right) {};
		void MoveSlow();
		void Climb();
		int CalculateEncoderCounts(int length_inches);
		int mode = 1;
	private:
		Elevator *elevator;
		Winch *winch;
		Lidar *lidar;
		frc::Joystick *joystick;
		TalonSRX *talon_drive_left;
		TalonSRX *talon_drive_right;
		
		bool is_pressed = false;
		bool toggle = false;
		
};
#endif
