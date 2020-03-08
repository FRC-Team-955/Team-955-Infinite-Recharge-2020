#ifndef LIMELIGHT_H
#define LIMELIGHT_H

#include "Robot.h"
#include "ctre/Phoenix.h"
#include <iostream>
#include "frc/Joystick.h"

class Limelight {
    public:
	Limelight(
		frc::Joystick *joystick0,
		frc::Joystick *joystick1,
		TalonSRX *talon_drive_left_enc,
		TalonSRX *talon_drive_left_noenc,
		TalonSRX *talon_drive_right_enc,
		TalonSRX *talon_drive_right_noenc
	):
		joystick0(joystick0),
		joystick1(joystick1),
		talon_drive_left_enc(talon_drive_left_enc),
		talon_drive_left_noenc(talon_drive_left_noenc),
		talon_drive_right_enc(talon_drive_right_enc),
		talon_drive_right_noenc(talon_drive_right_noenc){};
	
	bool align = true;
    void RunAlign(double  horizontal_offset);
	
    private:
    frc::Joystick *joystick0;
    frc::Joystick *joystick1;
	TalonSRX *talon_drive_left_enc;
	TalonSRX *talon_drive_left_noenc;
	TalonSRX *talon_drive_right_enc;
	TalonSRX *talon_drive_right_noenc;

	int rumble_set = 0;
};
#endif
