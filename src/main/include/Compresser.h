#ifndef COMPRESSERCLASS
#define COMPRESSERCLASS

#include "frc/WPILib.h"
#include <iostream>
#include <cmath>
#include <string>
#include "ctre/Phoenix.h"
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;

class CompresserClass {
	public:
		CompresserClass (Compressor *compresser) :  compresser(compresser) {};
		void CompresserOff();
		void CompresserOn();
		void CompresserBatteryVoltage(int volts);
	private:
		Compressor *compresser;
		int volts;
};

#endif