#include <pid.h>
#include <iostream>

void PID::PIDTune(TalonSRX * talon_enc,  double p_value, double i_value, double d_value, double f_value){
   talon_enc->Config_kP(0, p_value, 0);
   talon_enc->Config_kI(0, i_value, 0);
   talon_enc->Config_kD(0, d_value, 0);
   talon_enc->Config_kF(0, f_value, 0);
}