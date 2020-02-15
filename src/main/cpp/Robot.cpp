/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
#include <frc/Joystick.h>
#include "version.h"
#include "drivebase.h"
#include "settings.h"
#include "intake.h"

using namespace frc;

TalonSRX *talon_drive_left_noenc, *talon_drive_left_enc, *talon_drive_right_enc, *talon_drive_right_noenc, *intake_talon;
Solenoid *solenoid_intake_left_0, *solenoid_intake_left_1, *solenoid_intake_right_6, *solenoid_intake_right_7;
ToggleMotor *toggle;
Intake *intake;
DriveBase *drivebase;
Joystick *joystick;
Version *print;
Timer *timer;

double multi = 1;
double x = 0;

std::string storage = "";
std::string storage_header = "";
std::string filename = "Drivebase";

int num_talon_drive_left_noenc = 2;
int num_talon_drive_right_noenc = 3;
int num_talon_drive_left_enc = 1;
int num_talon_drive_right_enc = 4;

void Robot::RobotInit() {
	talon_drive_left_noenc = new TalonSRX(num_talon_drive_left_noenc);
	talon_drive_left_enc = new TalonSRX(num_talon_drive_left_enc);
	talon_drive_right_enc = new TalonSRX(num_talon_drive_right_enc);
	talon_drive_right_noenc = new TalonSRX(num_talon_drive_right_noenc);

	intake_talon = new TalonSRX(7);

	solenoid_intake_left_0 = new Solenoid(0);
	solenoid_intake_left_1 = new Solenoid(1);
	solenoid_intake_right_6 = new Solenoid(6);
	solenoid_intake_right_7 = new Solenoid(7);

	


	talon_drive_left_noenc->SetInverted(1);
	talon_drive_left_noenc->Set(ControlMode::Follower, num_talon_drive_left_enc);

	talon_drive_right_noenc->Set(ControlMode::Follower, num_talon_drive_right_enc);

	joystick = new Joystick(0);

	print = new Version(filename);
	timer = new Timer();

	drivebase = new DriveBase(joystick, talon_drive_left_enc, talon_drive_right_enc);

	toggle = new ToggleMotor(joystick);

	intake = new Intake(toggle, intake_talon, solenoid_intake_right_6, solenoid_intake_right_7, solenoid_intake_left_0, solenoid_intake_left_1, joystick);

	std::cout<<filename<<" V"<<print->SaveVersionNumber()<<std::endl;
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
	timer->Start();
}

void Robot::TeleopPeriodic() {
	drivebase->Drive(multi, x);
	intake->DeployIntakePNE();
	intake->RunIntake(0.5);
	print->AddToPipeDelimitedFile("Time", print->ToString(timer->Get()), storage_header, storage, false);
	print->AddToPipeDelimitedFile("Battery Voltage", print->ToString(DriverStation::GetInstance().GetBatteryVoltage()), storage_header, storage, false);
	
	TalonEncPrintOuts(talon_drive_left_enc, "Talon Left Drive Encoder");
	TalonEncPrintOuts(talon_drive_right_enc, "Talon Right Drive Encoder");
	TalonNoEncPrintOuts(talon_drive_left_noenc, "Talon Left Drive No Encoder");
	TalonNoEncPrintOuts(talon_drive_right_noenc, "Talon Right Drive No Encoder");
	
	print->EndLoop(storage);

}

void Robot::TalonEncPrintOuts(TalonSRX *talon_enc, std::string talon_name){
	print->AddToPipeDelimitedFile(std::string(talon_name + " Position"), print->ToString(talon_enc->GetSelectedSensorPosition(0)), storage_header, storage, false);
	print->AddToPipeDelimitedFile(std::string(talon_name + " Velocity"), print->ToString(talon_enc->GetSelectedSensorVelocity(0)), storage_header, storage, false);
	print->AddToPipeDelimitedFile(std::string(talon_name + " Amperage"), print->ToString(talon_enc->GetOutputCurrent()), storage_header, storage, false);
}

void Robot::TalonNoEncPrintOuts(TalonSRX *talon_enc, std::string talon_name){
	print->AddToPipeDelimitedFile(std::string(talon_name + " Amperage"), print->ToString(talon_enc->GetOutputCurrent()), storage_header, storage, false);
}

void Robot::TestPeriodic() {}

void Robot::DisabledInit(){
	if (storage.find(std::string("|")) != std::string::npos) print->CreateSaveFile(storage_header + "\n" + storage);
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif