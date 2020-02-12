#ifndef PID
#define PID

#include <iostream>
#include <WPILibVersion.h>
#include <ctre/Phoenix.h>

class Pid {
public:
void PIDTune (TalonSRX * talon_enc, double p_value, double i_value, double d_value, double f_value);
};

#endif
