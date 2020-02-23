#ifndef AUTO
#define AUTO

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <AHRS.h>

class Auto {
	public:
		Auto (TalonSRX *drive_talon_right, 
			TalonSRX *drive_talon_left, 
			AHRS *navx) : 
			drive_talon_right(drive_talon_right), 
			drive_talon_left(drive_talon_left), 
			navx(navx) {};

		int CalculateEncoderCounts(int length_inches);
		void MoveStraight(int distance_inches, int &mode);
		void Turn(int degrees, int &mode);
		void InitializeNavX(int &mode);
		int RampSpeed(int velocity, int difference);
		int StraightRamp(int velocity, int percent_change);
		void Stop();
		void ZeroEnc(int &mode);
		void Pause(int &mode);
		void Path();
		void MoveOffLine();

		int target_distance_change = 0;
		int percent_change = 0;
		float abs_target_distance_change = 0;
		float average_abs_positions = 0;
		int right_velocity = 0;
		int left_velocity = 0;
		int mode = 1;

	private:
		TalonSRX *drive_talon_right;
		TalonSRX *drive_talon_left;
		AHRS *navx;

		bool know_gear_ratio = true;
		int gear_ratio = 6;
		int full_rotation_enc = 1040;
		const int wheel_diameter = 7.5;
		const int max_turning_velocity = 150;
		const int max_velocity = 230;
		const int right_forward_direction = -1; // 1 or -1
		const int left_forward_direction = -1; // 1 or -1
		int max_right_turning_velocity = right_forward_direction * max_turning_velocity;
		int max_left_turning_velocity = left_forward_direction * max_turning_velocity;
		int max_right_velocity = right_forward_direction * max_velocity;
		int max_left_velocity = left_forward_direction * max_velocity;

		int loop = 1;
};

#endif