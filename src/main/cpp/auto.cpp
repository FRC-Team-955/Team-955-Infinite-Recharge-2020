#include <auto.h>

int Auto::CalculateEncoderCounts(int length_inches){
	return gear_ratio * wheel_diameter * length_inches; // Haven't tested yet
}

void Auto::MoveStraight(int distance_inches){
	int target_distance_change = CalculateEncoderCounts(distance_inches);
}

void Auto::Turn(int degrees, int &mode){
	int current_degrees = navx->GetYaw();
	bool turn_left = degrees < current_degrees;
	right_velocity = RampSpeed(max_right_velocity, abs(current_degrees - degrees));
	left_velocity = RampSpeed(max_left_velocity, abs(current_degrees - degrees)) * -1;

	if (right_velocity == 0 && left_velocity == 0) mode++;

	if (!turn_left){
		right_velocity = right_velocity * -1;
		left_velocity = left_velocity * -1;
	}
	
	drive_talon_right->Set(ControlMode::Velocity, right_velocity);
	drive_talon_left->Set(ControlMode::Velocity, left_velocity);
}

int Auto::RampSpeed(int velocity, int difference){
	if (difference > 20) return velocity;
	if (difference > 10) return velocity / 2;
	if (difference > 5) return velocity / 4;
	return 0;
}

void Auto::InitializeNavX(){
	navx->ZeroYaw();
}

void Auto::ComplexAuto(){
	AddCommands(
		InitializeNavX()
	);
}
