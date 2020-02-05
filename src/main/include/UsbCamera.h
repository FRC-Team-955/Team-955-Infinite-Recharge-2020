#ifndef USBCAMERA
#define USBCAMERA

#include <cmath>
#include <ctre/Phoenix.h>
#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <iostream>
#include <string>
using namespace frc;

class UsbCamera {
public:
    UsbCamera() {};
    void VideoCapture();

private:
};
#endif