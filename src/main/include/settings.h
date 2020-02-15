#ifndef SETTINGS
#define SETTINGS

//Controls
    //Joytick 0

const int joy_0_idx = 0;

const int align_button_idx = 3;
const int set_target_button_idx = 2;

const int forward_back_drivebase_axis_idx = 1;
const int left_right_drivebase_axis_idx = 4;
const int sensitivity_scale_cont_button_idx = 0;
const int test = 4;

    //Joystick 1

const int joy_1_idx = 1;

const int color_wheel_oper_1_button_idx = 1;
const int color_wheel_oper_2_button_idx = 2;

const int raise_color_wheel_arm_button_idx = 3;
const int lower_color_wheel_arm_button_idx = 4;

const int toggle_rev_shooter_button_idx = 6;    
const int hopper_button_idx = 3;

const int elevator_up_axis_idx = 0;
const int elevator_down_axis_idx = 0;
const int elevator_up_button_idx = 0;
const int elevator_down_button_idx = 0;

const int pull_winch_in_button_idx = 0;
const int pull_winch_in_axis_idx = 0;

const int deploy_intake_button_idx = 0;
const int run_intake_button_idx = 0;

//itake is either one axis or two buttons

//Talons

const int num_talon_drive_left_noenc = 2;
const int num_talon_drive_right_noenc = 3;
const int num_talon_drive_left_enc = 1;
const int num_talon_drive_right_enc = 4;

const int num_talon_shooter_connected = 9;
const int num_talon_shooter_noconnected = 10;

const int num_talon_elevator = 6;
const int num_talon_winch = 8;

const int num_talon_intake = 7;

const int num_talon_hopper = 5;

//Solenoid

const int num_solenoid_intake_right_6 = 6;
const int num_solenoid_intake_right_7 = 7;
const int num_solenoid_intake_left_0 = 0;
const int num_solenoid_intake_left_1 = 1;

//

#endif
