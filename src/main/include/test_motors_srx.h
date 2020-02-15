#ifndef TESTMOTORSSRX
#define TESTMOTORSSRX

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "version.h"

class TestMotorsSRX {
	public:
		TestMotorsSRX (TalonSRX *talon, frc::Joystick *joystick, Version *print, frc::Timer *timer, std::string storage, std::string storage_header)
		 : talon(talon), joystick(joystick), timer(timer), print(print), storage(storage), storage_header(storage_header) {};
		void RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder);
		void SaveVersionNum();	
		void SaveData();
		void StartTimer();	

	private:
		TalonSRX *talon;
		frc::Joystick *joystick;
		Version *print;
		frc::Timer *timer;
		std::string storage;
		std::string storage_header;

};

#endif
