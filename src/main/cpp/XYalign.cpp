#include "XYalign.h"
using namespace frc;
double XYalign::test()
{
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    double vertical_offset = table->GetNumber("ty", 0.0);
    double drive_adjustment = vertical_offset - 15;
    int xp = joy0->GetRawAxis(4);
    int yp = joy0->GetRawAxis(1);
    HorizontalOffset = table->GetNumber("tx", 0.0);
    talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp + xp));
    talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp - yp));
    if (HorizontalOffset < 0.1 and HorizontalOffset > -0.1) {
        Align = true;
        talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp + xp));
        talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp - yp));
    } else if (HorizontalOffset > 0.75 /*and Align == false*/) {
        //left_drive=  HorizontalOffset/ 45;
        left_drive = -0.1;
        right_drive = 0;
    }

    else if (HorizontalOffset < -.75 /*and Align == false*/) {
        //right_drive = HorizontalOffset/ 45;
        right_drive = 0.1;
        left_drive = 0;
    } else {
        right_drive = 0;
        left_drive = 0;
    }
    if (joy0->GetRawButton(2) == 1) {
        Align = false;
    }
    if (joy0->GetRawButton(1) == 1) {
        Align = true;
    }
    std::cout << HorizontalOffset << std::endl;
    std::cout << "Right: " << right_drive << std::endl;
    std::cout << "Left: " << left_drive << std::endl;

    if (joy0->GetRawButton(3) == 1) {
        talon_drive_right_enc->Set(ControlMode::PercentOutput, (.1 * drive_adjustment - right_drive));
        talon_drive_left_enc->Set(ControlMode::PercentOutput, (-.1 * drive_adjustment - left_drive));
    }
    std::cout << drive_adjustment << std::endl;
}