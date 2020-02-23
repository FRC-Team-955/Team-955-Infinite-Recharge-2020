#define PIE 3.14159265359

#include <auto.h>

int Auto::CalculateEncoderCounts(int length_inches){
	//if (know_gear_ratio) return gear_ratio * wheel_diameter * length_inches; // Haven't tested yet
	return length_inches * (1 / (wheel_diameter * PIE)) * full_rotation_enc;
}

void Auto::MoveStraight(int distance_inches, int &mode){
	target_distance_change = CalculateEncoderCounts(distance_inches);
	int right_pos = drive_talon_right->GetSelectedSensorPosition(0);
	int left_pos = drive_talon_left->GetSelectedSensorPosition(0);

	abs_target_distance_change = abs(target_distance_change);
	average_abs_positions = (abs(right_pos) + abs(left_pos))/ 2;

	percent_change = 100 * ((abs_target_distance_change - average_abs_positions) / abs_target_distance_change) ;

	right_velocity = StraightRamp(max_right_velocity, percent_change);
	left_velocity = StraightRamp(max_left_velocity, percent_change);

	if (right_velocity == 0 && left_velocity == 0) mode++;

	if (target_distance_change < 0){
		right_velocity = right_velocity * -1;
		left_velocity = left_velocity * -1;
	}
	
	drive_talon_right->Set(ControlMode::Velocity, right_velocity);
	drive_talon_left->Set(ControlMode::Velocity, left_velocity);
}

void Auto::Turn(int degrees, int &mode){
	int current_degrees = navx->GetYaw();
	bool turn_left = degrees < current_degrees;
	right_velocity = RampSpeed(max_right_turning_velocity, abs(current_degrees - degrees));
	left_velocity = RampSpeed(max_left_turning_velocity, abs(current_degrees - degrees)) * -1;

	if (right_velocity == 0 && left_velocity == 0) mode++;

	if (!turn_left){
		right_velocity = right_velocity * -1;
		left_velocity = left_velocity * -1;
	}
	
	drive_talon_right->Set(ControlMode::Velocity, right_velocity);
	drive_talon_left->Set(ControlMode::Velocity, left_velocity);
}

int Auto::RampSpeed(int velocity, int difference){
	if (difference > 30) return velocity;
	if (difference > 20) return velocity / 6;
	if (difference > 6) return velocity / 8;
	return 0;
}

int Auto::StraightRamp(int velocity, int percent_change){
	if (percent_change >= 90) return velocity / 5;
	if (percent_change >= 80) return velocity / 4;
	if (percent_change > 75) return velocity / 3;
	if (percent_change > 50) return velocity / 2;
	if (percent_change > 10) return velocity / 4;
	return 0;
}

void Auto::InitializeNavX(int &mode){
	navx->ZeroYaw();
	mode++;
}

void Auto::ZeroEnc(int &mode){
	drive_talon_right->SetSelectedSensorPosition(0, 0, 10);
	drive_talon_left->SetSelectedSensorPosition(0, 0, 10);
	Stop();
	if (drive_talon_right->GetSelectedSensorPosition(0) == 0 && drive_talon_left->GetSelectedSensorPosition(0) == 0) mode++;
}

void Auto::Stop(){
	drive_talon_right->Set(ControlMode::PercentOutput, 0);
	drive_talon_left->Set(ControlMode::PercentOutput, 0);
}

void Auto::Pause(int &mode){
	Stop();
	mode++;
}

/*void Auto::Path(){
	if (mode == 1) InitializeNavX(mode);
	if (mode == 2) Turn(135, mode);
	if (mode == 3) ZeroEnc(mode);
	if (mode == 4) MoveStraight(18, mode);
	if (mode == 5) ZeroEnc(mode);
	if (mode == 6) Turn (180, mode);
	if (mode == 7) ZeroEnc(mode);
	if (mode == 8) MoveStraight(168, mode);
	if (mode == 9) Stop();
	std::cout<<"Mode: "<<mode<<std::endl;
}*/

void Auto::Path(){
	if (mode == 1) InitializeNavX(mode);
	if (mode == 2) Turn(135, mode);
	if (mode == 3) ZeroEnc(mode);
	if (mode == 4) MoveStraight(18, mode);
	if (mode == 5) ZeroEnc(mode);
	if (mode == 6) Turn (180, mode);
	if (mode == 7) ZeroEnc(mode);
	if (mode == 8) MoveStraight(160, mode);
	if (mode == 9) InitializeNavX(mode);
	if (mode == 10) Turn(-5, mode);
	if (mode == 11) ZeroEnc(mode);
	if (mode == 12) MoveStraight(10, mode);
	if (mode == 13) ZeroEnc(mode);
	if (mode == 14) MoveStraight(-10, mode);
	if (mode == 15) ZeroEnc(mode);
	if (mode == 16) Turn(5, mode);
	if (mode == 17) ZeroEnc(mode);
	if (mode == 18) MoveStraight(10, mode);
	if (mode == 19) ZeroEnc(mode);
	if (mode == 20) MoveStraight(-10, mode);
	if (mode == 21) ZeroEnc(mode);
	if (mode == 22) Stop();
	std::cout<<"Mode: "<<mode<<std::endl;
}

void Auto::MoveOffLine(){
	if (mode == 1) ZeroEnc(mode);
	if (mode == 2) MoveStraight(-36, mode);
	if (mode == 3) Stop();
}