#include "usb_camera.h"
using namespace frc;

void UsbCamera::VideoCapture(){
  CameraServer::GetInstance()->StartAutomaticCapture();
}
