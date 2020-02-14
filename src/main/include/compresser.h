#ifndef COMPRESSERCLASS
#define COMPRESSERCLASS

#include "frc/WPILib.h"
#include <iostream>


class CompresserClass {
	public:
		CompresserClass (frc::Compressor *compresser) :  compresser(compresser) {};
		void CompresserOff();
		void CompresserOn();
		void CompresserBatteryVoltage(int volts);
	private:
		frc::Compressor *compresser;
		int volts;
};

#endif
