<!----- Conversion time: 0.534 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β18
* Thu Feb 13 2020 18:41:12 GMT-0800 (PST)
* Source doc: https://docs.google.com/open?id=1d0h-_yy2qm8nfGBsRW0lOG0X2tbbsxMAMMr8-hufIoo
----->


<p style="text-align: right">
BC 2/13/2020</p>


Shooter API Documentation


<table>
  <tr>
   <td>Shooter(TalonFX * talon_shooter_connected, TalonFX * talon_shooter_noconnected,TalonSRX *talon_hopper, frc::Joystick * joystick1)
<p>
Constructs an instance of Shooter Class
<p>
Parameters:
<p>
talon_shooter_connected is the talon directly connected to the shooter
<p>
talon_shooter_noconnected is the talon connected by chain to the shooter
<p>
talon_hopper is the talon that controls the hopper
<p>
joystick1 is the instance of a Joystick
   </td>
  </tr>
  <tr>
   <td><strong>void Spin_Motor_Axis()</strong>
<p>
To be run in TeleopPeriodic
<p>
Parameters:
<p>
None
<p>
Returns:
<p>
None
<p>
Usage:
<p>
 to spin the motor with the control of an axis (Use Follower for the other motor and Don't use)
   </td>
  </tr>
  <tr>
   <td><strong>void Spin_Motor_PercentOutput()</strong>
<p>
To be run in TeleopPeriodic 
<p>
Parameters:
<p>
None
<p>
Returns:
<p>
None
<p>
Usage:
<p>
Toggles the shooter with the press of a button (Don’t use)
   </td>
  </tr>
  <tr>
   <td><strong>Void Spin_Motor_Velocity()</strong>
<p>
Use in TeleopPeriodic
<p>
Parameters:
<p>
target_velocity
<p>
Returns:
<p>
None
<p>
Usage:
<p>
Spin the motors to a certain velocity and then spins the hopper (Use Follower for the second motor)
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β18 -->

