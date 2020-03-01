#define PIE 3.14159265359

#include <auto.h>

int Auto::CalculateEncoderCounts(int length_inches){
	//if (know_gear_ratio) return gear_ratio * wheel_diameter * length_inches; // Haven't tested yet
	return length_inches * (1 / (wheel_diameter * PIE)) * full_rotation_enc;
}

void Auto::MoveStraight(int distance_inches, int max_right_velocity, int max_left_velocity, int &mode){
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

void Auto::PickUpBalls(int distance_inches, int &mode){
	MoveStraight(distance_inches, max_balls_right_velocity, max_balls_left_velocity,mode);
	IntakeOn();
}

void Auto::Move(int distance_inches, int &mode){
	MoveStraight(distance_inches, no_pickup_max_right_velocity, no_pickup_max_left_velocity, mode);
	IntakeOff();
}

void Auto::Turn(int degrees, int &mode){
	IntakeOff();
	current_degrees = navx->GetYaw();
	if (current_degrees < 0) current_degrees += 360;
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
	if (percent_change >= 90) return velocity / 6;
	if (percent_change >= 80) return velocity / 5;
	if (percent_change > 75) return velocity / 3;
	if (percent_change > 50) return velocity / 2;
	if (percent_change > 10) return velocity / 4;
	return 0;
}

void Auto::InitializeNavX(int &mode){
	navx->ZeroYaw();
	if (navx->GetYaw() == 0) mode++;
	IntakeOff();
}

void Auto::ZeroEnc(int &mode){
	drive_talon_right->SetSelectedSensorPosition(0, 0, 10);
	drive_talon_left->SetSelectedSensorPosition(0, 0, 10);
	IntakeOff();
	Stop();
	if (drive_talon_right->GetSelectedSensorPosition(0) == 0 && drive_talon_left->GetSelectedSensorPosition(0) == 0) mode++;
}

void Auto::Stop(){
	drive_talon_right->Set(ControlMode::PercentOutput, 0);
	drive_talon_left->Set(ControlMode::PercentOutput, 0);
	IntakeOff();
}

void Auto::Pause(int &mode){
	Stop();
	mode++;
}

void Auto::IntakeOn(){
	intake_talon->Set(ControlMode::PercentOutput, intake_talon_speed);
}

void Auto::IntakeOff(){
	intake_talon->Set(ControlMode::PercentOutput, 0);	
}

//This picks up 5 when slow
/*void Auto::ThreeBallPickup(){
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

void Auto::Shoot(){
	shooter_talon->Set(ControlMode::PercentOutput, -0.8);
	if (abs(shooter_talon->GetSelectedSensorVelocity(0)) > 16000){
		hopper_talon->Set(ControlMode::PercentOutput, -0.4);
	}
}

void Auto::ThreeBallPickup(){
	if (mode == 1) InitializeNavX(mode);
	if (mode == 2) Turn(140, mode);
	if (mode == 3) ZeroEnc(mode);
	if (mode == 4) Move(30, mode);
	if (mode == 5) ZeroEnc(mode);
	if (mode == 6) Turn(180, mode);
	if (mode == 7) ZeroEnc(mode);
	if (mode == 8) PickUpBalls(178, mode);
	if (mode == 9) ZeroEnc(mode);
	if (mode == 10) Move(-185, mode);
	//if (mode == 11) InitializeNavX(mode);
	if (mode == 11) Turn(312, mode);
	if (mode == 12) ZeroEnc(mode);
	if (mode == 13) Shoot();
	if (mode == 14) Stop();
	std::cout<<"Mode: "<<mode<<std::endl;
}

void Auto::FiveBallPickup(){
	if (mode == 1) InitializeNavX(mode);
	if (mode == 2) Turn(14, mode);
	if (mode == 3) ZeroEnc(mode);
	if (mode == 4) Move(18, mode);
	if (mode == 5) ZeroEnc(mode);
	if (mode == 6) Turn (180, mode);
	if (mode == 7) ZeroEnc(mode);
	if (mode == 8) PickUpBalls(150, mode);
	if (mode == 9) InitializeNavX(mode);
	if (mode == 10) Turn(-15, mode);
	if (mode == 11) ZeroEnc(mode);
	if (mode == 12) PickUpBalls(10, mode);
	if (mode == 13) ZeroEnc(mode);
	if (mode == 14) Move(-10, mode);
	if (mode == 15) ZeroEnc(mode);
	if (mode == 16) Turn(15, mode);
	if (mode == 17) ZeroEnc(mode);
	if (mode == 18) PickUpBalls(10, mode);
	if (mode == 19) ZeroEnc(mode);
	if (mode == 20) Move(-10, mode);
	if (mode == 21) ZeroEnc(mode);
	if (mode == 22) Stop();
	std::cout<<"Mode: "<<mode<<std::endl;
}

void Auto::MoveOffLine(){
	if (mode == 1) ZeroEnc(mode);
	if (mode == 2) MoveStraight(-36, max_balls_right_velocity, max_balls_left_velocity, mode);
	if (mode == 3) Stop();
}