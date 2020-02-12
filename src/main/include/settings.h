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

const in joy_1_idx = 1;

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

const int deploy_intake_button_idx = 0;
const int run_intake_button_idx = 0;

//itake is either one axis or two buttons

//Talons

const int talon_drivebase_left_noenc_num = 1;
const int talon_drivebase_left_enc_num = 2;
const int talon_drivebase_right_noenc_num = 3;
const int talon_drivebase_right_enc_num = 4;

const int talon_shooter_connected_num = 9;
const int talon_shooter_noconnected_num = 10;

const int talon_elevator_num = 6;
const int talon_winch_num = 8;

const int talon_intake_num = 7;

const int talon_hopper_num = 5;

//Solenoid

const int solenoid_intake_right_0 = 0;
const int solenoid_intake_right_1 = 0;
const int solenoid_intake_left_0 = 0;
const int solenoid_intake_left_1 = 0;

//

#endif
