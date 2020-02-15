<!----- Conversion time: 0.78 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β18
* Fri Feb 14 2020 21:49:06 GMT-0800 (PST)
* Source doc: https://docs.google.com/open?id=1RSIkWmymM0kWGzy5MnmqJhochKXnuVmc3v99IzsBGeA
----->


<p style="text-align: right">
BC and JF 2/13/2020</p>


Settings.h API


<table>
  <tr>
   <td><strong>const int joy_0_idx</strong>
<p>
The index for the first joystick
   </td>
  </tr>
  <tr>
   <td><strong>const int align_button_idx</strong>
<p>
The index for the button for activating alignment
   </td>
  </tr>
  <tr>
   <td><strong>const int set_target_button_idx</strong>
<p>
The index for the button for setting the target for alignment
   </td>
  </tr>
  <tr>
   <td><strong>const int forward_back_drivebase_axis_idx</strong>
<p>
The index for the axis for driving forward and backward
   </td>
  </tr>
  <tr>
   <td><strong>const int left_right_drivebase_axis_idx</strong>
<p>
The index for the axis for turning left and right
   </td>
  </tr>
  <tr>
   <td><strong>const int sensitivity_scale_cont_button_idx</strong>
<p>
The index for the button that changes the scale 
   </td>
  </tr>
  <tr>
   <td><strong>const int test</strong>
<p>
The index for something but is not needed.
   </td>
  </tr>
  <tr>
   <td><strong>const int joy_1_idx</strong>
<p>
The index for the second joystick
   </td>
  </tr>
  <tr>
   <td><strong>const int color_wheel_oper_1_button_idx</strong>
<p>
The index for the button for the first operation of the color wheel
   </td>
  </tr>
  <tr>
   <td><strong>const int color_wheel_oper_2_button_idx</strong>
<p>
The index for the button for the second operation of the color wheel
   </td>
  </tr>
  <tr>
   <td><strong>const int raise_color_wheel_arm_button_idx</strong>
<p>
The index for the button to make the color wheel arm go up
   </td>
  </tr>
  <tr>
   <td><strong>const int lower_color_wheel_arm_button_idx</strong>
<p>
The index for the button to make the color wheel arm go down
   </td>
  </tr>
  <tr>
   <td><strong>const int toggle_rev_shooter_button_idx</strong>
<p>
The index for the button/axis to make the shooter spin
   </td>
  </tr>
  <tr>
   <td><strong>const int hopper_button_idx</strong>
<p>
The index for the button to make the hopper spin
   </td>
  </tr>
  <tr>
   <td><strong>const int elevator_up_axis_idx</strong>
<p>
The index for the axis to make the elevator go up
   </td>
  </tr>
  <tr>
   <td><strong>const int elevator_down_axis_idx</strong>
<p>
The index for the axis to make the elevator go down
   </td>
  </tr>
  <tr>
   <td><strong>const int elevator_up_button_idx</strong>
<p>
The index for the button to make the elevator go up
   </td>
  </tr>
  <tr>
   <td><strong>const int elevator_down_button_idx</strong>
<p>
The index for the button to make the elevator go down
   </td>
  </tr>
  <tr>
   <td><strong>const int pull_winch_in_button_idx</strong>
<p>
The index for the button for the winch
   </td>
  </tr>
  <tr>
   <td><strong>const int pull_winch_in_axis_idx</strong>
<p>
The index for the axis for the winch
   </td>
  </tr>
  <tr>
   <td><strong>const int deploy_intake_button_idx</strong>
<p>
The index for the button to deploy the intake
   </td>
  </tr>
  <tr>
   <td><strong>const int run_intake_button_idx</strong>
<p>
The index for the button to intake with the intake
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_drivebase_left_noenc_num</strong>
<p>
The index for the talon on the left side of the drivebase without a encoder
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_drivebase_left_enc_num</strong>
<p>
The index for the talon on the left side of the drivebase with a encoder
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_drivebase_right_noenc_num</strong>
<p>
The index for the talon on the right side of the drivebase without a encoder
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_drivebase_right_enc_num</strong>
<p>
The index for the talon on the right side of the drivebase with a encoder
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_shooter_connected_num</strong>
<p>
The index for the talon for the motor DIRECTLY connected to the shooter
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_shooter_noconnected_num</strong>
<p>
The index for the talon for motor NOT directly connected to the shooter
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_elevator_num</strong>
<p>
The index for the talon for the elevator
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_winch_num </strong>
<p>
The index for the talon for the winch
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_intake_num;</strong>
<p>
The index for the talon for the wheels on the intake
   </td>
  </tr>
  <tr>
   <td><strong>const int talon_hopper_num</strong>
<p>
The index for the talon for the wheel in the hopper
   </td>
  </tr>
  <tr>
   <td><strong>const int solenoid_intake_right_0</strong>
<p>
The index for the solenoid intake on the right for going out
   </td>
  </tr>
  <tr>
   <td><strong>const int solenoid_intake_right_1</strong>
<p>
The index for the solenoid intake on the right for going in
   </td>
  </tr>
  <tr>
   <td><strong>const int solenoid_intake_left_0</strong>
<p>
The index for the solenoid intake on the left for going out
   </td>
  </tr>
  <tr>
   <td><strong>const int solenoid_intake_left_1</strong>
<p>
The index for the solenoid intake on the left for going in
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β18 -->
