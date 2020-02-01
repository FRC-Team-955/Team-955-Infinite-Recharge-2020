#ifndef CONTROLPANNELSPINNER
#define CONTROLPANNELSPINNER

#include <iostream>
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include "colorSensor.h"
#include <string>
#include <cmath>

using namespace frc;
//using namespace rev;
class ControlPanelSpinner {
   public:
       ControlPanelSpinner (TalonSRX *talon_weelspinner_enc, Solenoid *arm_solenoid_up, Solenoid *arm_solenoid_down) : talon_weelspinner_enc(talon_weelspinner_enc), arm_solenoid_up(arm_solenoid_up), arm_solenoid_down(arm_solenoid_down) {};
        void MoveUp();
        void MoveDown();
        bool PositionControl(bool is_match);
        bool RotationControl(int color_count);
   private:
        TalonSRX *talon_weelspinner_enc;  
        Solenoid *arm_solenoid_up;
        Solenoid *arm_solenoid_down;
        bool is_match;
        int color_count;

};
#endif
