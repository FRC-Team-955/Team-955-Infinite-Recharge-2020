#include <Limelight.h>
#include <iostream>
using namespace frc;

void Limelight::RunAlign(double horizontal_offset)
{
    int xp = joy0->GetRawAxis(4);
    int yp = joy0->GetRawAxis(1);

    talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp + xp));
    talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp - yp));

    if (horizontal_offset < 0.1 and horizontal_offset > -0.1) {
        align = true;
        talon_drive_right_enc->Set(ControlMode::PercentOutput, .3 * (yp + xp));
        talon_drive_left_enc->Set(ControlMode::PercentOutput, .3 * (xp - yp));
    } else if (horizontal_offset > 0.15 and align == false) {

        talon_drive_left_enc->Set(ControlMode::PercentOutput, horizontal_offset / 45);

    } else if (horizontal_offset < -.15 and align == false) {
        talon_drive_right_enc->Set(ControlMode::PercentOutput, horizontal_offset / 45);
    }

    if (joy0->GetRawButton(2) == 1) {
        align = false;
    }
    if (joy0->GetRawButton(1) == 1) {
        align = true;
    }
    std::cout << horizontal_offset << std::endl;
}
