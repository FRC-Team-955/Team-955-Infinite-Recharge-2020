#ifndef AUTO
#define AUTO

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include "distance.h"

#include <AHRS.h>

class Auto {
	public:
		Auto (TalonSRX *drive_talon_right, 
			TalonSRX *drive_talon_left, 
			TalonSRX *intake_talon,
			AHRS *navx,
			TalonFX *shooter_talon,
			TalonSRX *hopper_talon,
			Distance *distance,
			std::shared_ptr<nt::NetworkTable> table) : 
			drive_talon_right(drive_talon_right), 
			drive_talon_left(drive_talon_left), 
			intake_talon(intake_talon),
			navx(navx),
			shooter_talon(shooter_talon),
			hopper_talon(hopper_talon),
			distance(distance),
			table(table) {};

		int CalculateEncoderCounts(int length_inches);
		void MoveStraight(int distance_inches, int max_right_velocity, int max_left_velocity, int &mode, bool ramp);
		void Turn(int degrees, int &mode);
		void InitializeNavX(int &mode);
		int RampSpeed(int velocity, int difference);
		int StraightRamp(int velocity, int percent_change);
		int StraightRampless(int velocity, int percent_change);
		int RampTurn(int velocity, int difference, int percent_change);
		void Stop();
		void ZeroEnc(int &mode);
		void Pause(int &mode);
		void ThreeBallPickup();
		void FiveBallPickup();
		void MoveOffLine();
		void IntakeOn();
		void IntakeOff();
		void Shoot(int &mode);
		void PickUpBalls(int distance_inches, int &mode);
		void Move(int distance_inches, int &mode, bool ramp);
		void LimelightGetDistance(int &mode);
		void MovementCalculations();
		void TestAuto();

		int target_distance_change = 0;
		int percent_change = 0;
		float abs_target_distance_change = 0;
		float average_abs_positions = 0;
		int right_velocity = 0;
		int left_velocity = 0;
		int mode = 1;
		float current_degrees;
		float intake_talon_speed = -0.9;

		float first_turn;
		float second_turn;
		float first_move;
		int distance_to_goal = 127;
		float offset;


	private:
		TalonSRX *drive_talon_right;
		TalonSRX *drive_talon_left;
		TalonSRX *intake_talon;
		AHRS *navx;
		TalonFX *shooter_talon;
		TalonSRX *hopper_talon;
		Distance *distance;
		std::shared_ptr<nt::NetworkTable> table;

		bool know_gear_ratio = true;
		int gear_ratio = 6;
		int full_rotation_enc = 707;
		const int wheel_diameter = 7.5;
		const int max_first_turn_velocity = 135;
		const int max_turning_velocity = 120;
		const int max_balls_velocity = 380;
		const int no_pickup_max_velocity = 385;
		const int right_forward_direction = -1; // 1 or -1
		const int left_forward_direction = -1; // 1 or -1
		int max_right_turning_velocity = right_forward_direction * max_turning_velocity;
		int max_left_turning_velocity = left_forward_direction * max_turning_velocity;
		
		int max_right_first_turn_velocity = right_forward_direction * max_first_turn_velocity;
		int max_left_first_turn_velocity = left_forward_direction * max_first_turn_velocity;

		int max_balls_right_velocity = right_forward_direction * max_balls_velocity;
		int max_balls_left_velocity = left_forward_direction * max_balls_velocity;
		int no_pickup_max_left_velocity = left_forward_direction * no_pickup_max_velocity;
		int no_pickup_max_right_velocity = right_forward_direction * no_pickup_max_velocity;

		int rloop = 0;


		int loop = 1;
};

#endif