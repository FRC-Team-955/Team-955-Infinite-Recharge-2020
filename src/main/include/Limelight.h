#ifndef LIMELIGHT_H
#define LIMELIGHT_H

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include "frc/WPILib.h"

class Limelight {
    public:
	Limelight(
		frc::Joystick *joy0,
		TalonSRX *talon_drive_left_enc,
		TalonSRX *talon_drive_left_noenc,
		TalonSRX *talon_drive_right_enc,
		TalonSRX *talon_drive_right_noenc
	):
		joy0(joy0),
		talon_drive_left_enc(talon_drive_left_enc),
		talon_drive_left_noenc(talon_drive_left_noenc),
		talon_drive_right_enc(talon_drive_right_enc),
		talon_drive_right_noenc(talon_drive_right_noenc){};
	
	bool align = false;
    	void RunAlign (double  horizontal_offset);
	
    private:
    	frc::Joystick *joy0;
	TalonSRX *talon_drive_left_enc;
	TalonSRX *talon_drive_left_noenc;
	TalonSRX *talon_drive_right_enc;
	TalonSRX *talon_drive_right_noenc;	
};
#endif
