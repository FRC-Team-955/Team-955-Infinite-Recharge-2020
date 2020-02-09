#include "compresser.h"
using namespace frc;

void CompresserClass::CompresserOn(){
	compresser -> Start();
}

void CompresserClass::CompresserOff(){
	compresser -> Stop();
}
void CompresserClass::CompresserBatteryVoltage(int volts){
	if(DriverStation::GetInstance().GetBatteryVoltage() < volts){
		compresser -> Stop();
	}
}
