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
#include "hopper.h"
#include "elevator.h"
#include "winch.h"
#include "shooter.h"

using namespace frc;

TalonSRX *talon_drive_left_noenc, *talon_drive_left_enc, *talon_drive_right_enc, *talon_drive_right_noenc, *talon_intake, *talon_elevator, *talon_winch, *talon_hopper;
TalonFX *talon_shooter_connected, *talon_shooter_noconnected;
Solenoid *solenoid_intake_left_0, *solenoid_intake_left_1, *solenoid_intake_right_6, *solenoid_intake_right_7;
Joystick *joystick0, *joystick1;

ToggleMotor *toggle0, *toggle1;
Version *print;
Timer *timer;

Intake *intake;
DriveBase *drivebase;
Hopper *hopper;
Elevator *elevator;
Winch *winch;
Shooter *shooter;

double multi = 1;
double x = 0;

std::string storage = "";
std::string storage_header = "";
std::string filename = "ScrimmageCode";


void Robot::RobotInit() {
	talon_drive_left_noenc = new TalonSRX(num_talon_drive_left_noenc);
	talon_drive_left_enc = new TalonSRX(num_talon_drive_left_enc);
	talon_drive_right_enc = new TalonSRX(num_talon_drive_right_enc);
	talon_drive_right_noenc = new TalonSRX(num_talon_drive_right_noenc);
	talon_intake = new TalonSRX(num_talon_intake);
	talon_winch = new TalonSRX(num_talon_winch);
	talon_elevator = new TalonSRX(num_talon_elevator);
	talon_hopper = new TalonSRX(num_talon_hopper);

	talon_drive_left_noenc->SetInverted(1);
	talon_drive_left_noenc->Set(ControlMode::Follower, num_talon_drive_left_enc);
	talon_drive_right_noenc->Set(ControlMode::Follower, num_talon_drive_right_enc);


	talon_shooter_connected = new TalonFX(num_talon_shooter_connected);
	talon_shooter_noconnected = new TalonFX(num_talon_shooter_noconnected);

	solenoid_intake_left_0 = new Solenoid(num_solenoid_intake_left_0);
	solenoid_intake_left_1 = new Solenoid(num_solenoid_intake_left_1);
	solenoid_intake_right_6 = new Solenoid(num_solenoid_intake_right_6);
	solenoid_intake_right_7 = new Solenoid(num_solenoid_intake_right_7);

	joystick0 = new Joystick(0);
	joystick1 = new Joystick(1);

	print = new Version(filename);
	timer = new Timer();
	toggle0 = new ToggleMotor(joystick0);
	toggle1 = new ToggleMotor(joystick1);


	drivebase = new DriveBase(joystick0, talon_drive_left_enc, talon_drive_right_enc);
	intake = new Intake(toggle1, talon_intake, solenoid_intake_right_6, solenoid_intake_right_7, solenoid_intake_left_0, solenoid_intake_left_1, joystick1);
	hopper = new Hopper(toggle1, talon_hopper);
	elevator = new Elevator(talon_elevator, joystick1);
	winch = new Winch(talon_winch, joystick1);
	shooter = new Shooter(talon_shooter_connected, talon_shooter_noconnected,talon_hopper, joystick1);

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
	intake->RunIntake(-0.5);
	hopper->Toggle();
	elevator->Elevate();
	winch->RaiseWinchAxis();
	shooter->SpinMotorAxis();

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