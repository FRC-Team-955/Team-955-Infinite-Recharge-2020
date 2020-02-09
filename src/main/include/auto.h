#ifndef AUTO
#define AUTO

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>
#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <AHRS.h>

class Auto : public frc2::CommandHelper<frc2::SequentialCommandGroup, Auto> {
	public:
		Auto (TalonSRX *drive_talon_right, TalonSRX *drive_talon_left, AHRS *navx) : 
		drive_talon_right(drive_talon_right), drive_talon_left(drive_talon_left), navx(navx) {};

		int CalculateEncoderCounts(int length_inches);
		void MoveStraight(int distance_inches);
		void Turn(int degrees, int &mode);
		void InitializeNavX();
		int RampSpeed(int velocity, int difference);

		void ComplexAuto();
	private:
		TalonSRX *drive_talon_right;
		TalonSRX *drive_talon_left;
		AHRS *navx;

		int gear_ratio = 6;
		const int wheel_diameter = 0;
		const int max_velocity = 0;
		const int right_forward_direction = 1; // 1 or -1
		const int left_forward_direction = 1; // 1 or -1
		int max_right_velocity = right_forward_direction * max_velocity;
		int max_left_velocity = left_forward_direction * max_velocity;
		int right_velocity;
		int left_velocity;
		int loop = 1;
};

#endif
