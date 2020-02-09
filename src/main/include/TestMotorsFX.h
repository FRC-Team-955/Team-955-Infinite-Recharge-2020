#ifndef TESTMOTORSFX
#define TESTMOTORSFX

#include <ctre/Phoenix.h>
#include "frc/WPILib.h"
#include "Version.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
using namespace frc;
using namespace std;

class TestMotorsFX {
	public:
		TestMotorsFX (TalonFX *talon, Joystick *joystick, Version *print, Timer *timer, string storage, string storage_header) : talon(talon), joystick(joystick), timer(timer), print(print), storage(storage), storage_header(storage_header) {};
		void RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder);
		void SaveVersionNum();		
		void SaveData();
		void StartTimer();

	private:
		TalonFX *talon;
		Joystick *joystick;
		Version *print;
		Timer *timer;
		string storage;
		string storage_header;
};

#endif
