#include "hopper.h"
#include "settings.h"
using namespace frc;

void Hopper::Toggle() {
    toggle_motor->Toggle(1);
}