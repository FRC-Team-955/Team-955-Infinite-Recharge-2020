#ifndef TESTMOTORSFX
#define TESTMOTORSFX

#include <ctre/Phoenix.h>
#include <frc/Joystick.h>
#include "version.h"



class TestMotorsFX {
	public:
		TestMotorsFX (TalonFX *talon, frc::Joystick *joystick, Version *print, frc::Timer *timer, std::string storage, std::string storage_header)
		 : talon(talon), joystick(joystick), timer(timer), print(print), storage(storage), storage_header(storage_header) {};
		void RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder);
		void SaveVersionNum();		
		void SaveData();
		void StartTimer();

	private:
		TalonFX *talon;
		frc::Joystick *joystick;
		Version *print;
		frc::Timer *timer;
		std::string storage;
		std::string storage_header;
};

#endif
