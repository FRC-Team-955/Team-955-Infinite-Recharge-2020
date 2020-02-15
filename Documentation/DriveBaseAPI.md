<!----- Conversion time: 0.449 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β18
* Fri Feb 14 2020 20:43:45 GMT-0800 (PST)
* Source doc: https://docs.google.com/open?id=1euqcJiPGEeBC1fLILR9IEkykzsrhW-POO6_MoWjrGSs
----->


<p style="text-align: right">
BC 2/13/2020</p>


Shooter API Documentation


<table>
  <tr>
   <td><strong>DriveBase (Joystick *joystick, TalonSRX *talon_drivebase_left_connected, TalonSRX *talon_drivebase_right_connected) : joystick(joystick), talon_drivebase_left_connected(talon_drivebase_left_connected), talon_drivebase_right_connected(talon_drivebase_right_connected) {};</strong>
<p>
Constructs an instance of DriveBase
<p>
Parameters:
<p>
<strong>Joystick *joystick = an Object of a joystick</strong>
<p>
<strong>TalonSRX *talon_drivebase_left_connected = an object of a Talon</strong>
   </td>
  </tr>
  <tr>
   <td><strong>void Drive(double left, double right, double lcalc, double rcalc, double &multi, double &x);</strong>
<p>
Spins the motor depending how much you presses the right trigger
<p>
Parameters:
<p>
double left, double right, double lcalc, double rcalc, double &multi, double &x are necessary but are not parameters in robot.cpp. 
<p>
Returns:
<p>
None
<p>
Usage:
<p>
To be run in TeleopPeriodic
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β18 -->