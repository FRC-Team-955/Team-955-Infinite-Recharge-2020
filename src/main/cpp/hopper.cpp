#include "hopper.h"
#include "settings.h"
using namespace frc;

void Hopper::Toggle() {
    toggle_motor->Toggle(hopper_button_idx, talon_hopper_enc, 0.25);
}
