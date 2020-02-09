#include "UsbCamera.h"
using namespace frc;

void UsbCamera::VideoCapture(){
  CameraServer::GetInstance()->StartAutomaticCapture();
}
