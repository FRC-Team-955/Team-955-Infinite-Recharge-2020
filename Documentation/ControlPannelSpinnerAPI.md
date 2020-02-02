<!----- Conversion time: 0.618 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β17
* Sun Feb 02 2020 14:50:06 GMT-0800 (PST)
* Source doc: https://docs.google.com/a/student.csd509j.net/open?id=1bl4N3uzBjg6SnT832_isoycYeR3pWwmU9EDqIrxAhFg
----->


<p style="text-align: right">
OM-2/1/2020</p>


ControlPanelSpinner API Documentation


<table>
  <tr>
   <td><strong>ControlPanelSpinner(TalonsSRX *wheelspinner_enc, Solenoid *)</strong>
<p>
Constructs an instance of ControlPanelSpinner
<p>
Parameters:
<p>
TalonSRX *wheelspinner_enc = the TalonSRX that spins the control panel
<p>
Solenoid *arm_solenoid_up =  the solenoid that raises the control panel spinner
<p>
Solenoid *arm_solenoid_down = the solenoid that lowers the control panel spinner
   </td>
  </tr>
  <tr>
   <td><strong>bool RotationControl(int color_count, int max_count)</strong>
<p>
Spinns the control panel a set number of times
<p>
Parameters:
<p>
int color_count = the number of colors the sensor has detected (can be return value of ColorSensor::ColorCount())
<p>
Int max_count = the number of colors that must pass to stop the wheel
<p>
Returns:
<p>
True: if RotationControl is completed
<p>
False: all other times
<p>
Usage:
<p>
Use after raising the arm to complete rotation control on the control panel
   </td>
  </tr>
  <tr>
   <td><strong>bool PositionControl(bool is_match)</strong>
<p>
Sets the green color on the control panel for use in FindClosestColor()
<p>
Parameters:
<p>
bool is_match = a bool that, when true, tells the motor to stop turning (use return value of ColorSensor::IsMatch)
<p>
Returns: \
True: if PositionControl is completed
<p>
False: all other times
<p>
Usage:
<p>
To be run after raising the arm to complete Position Control
   </td>
  </tr>
  <tr>
   <td><strong>void MoveUp()</strong>
<p>
Extends the control panel spinner
<p>
Usage:
<p>
Use to extend the control panel spinner before performing any other actions
   </td>
  </tr>
  <tr>
   <td><strong>void MoveDown()</strong>
<p>
Retracts the control panel spinner
<p>
Usage:
<p>
Use to lower the control panel spinner after Rotation or Position control has been completed.
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->

