#ifndef TESTMOTORSSRX
#define TESTMOTORSSRX

#include "frc/WPILib.h"
#include "version.h"
#include <ctre/Phoenix.h>

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace frc;
using namespace std;

class TestMotorsSRX {
public:
    TestMotorsSRX(TalonSRX* talon, Joystick* joystick, Version* print, Timer* timer, string storage, string storage_header)
        : talon(talon)
        , joystick(joystick)
        , timer(timer)
        , print(print)
        , storage(storage)
        , storage_header(storage_header) {};

    void RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder);
    void SaveVersionNum();
    void SaveData();
    void StartTimer();

private:
    TalonSRX* talon;
    Joystick* joystick;
    Version* print;
    Timer* timer;
    string storage;
    string storage_header;
};

#endif