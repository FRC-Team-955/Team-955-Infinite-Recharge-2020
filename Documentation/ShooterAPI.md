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
   <td>Shooter()
<p>
Constructs an instance of Class
   </td>
  </tr>
  <tr>
   <td><strong>void Spin_Motor_Axis()</strong>
<p>
Spins the motor depending how much you presses the right trigger
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
To be run in TeleopPeriodic to spin the motor with the control of an axis (Use Follower for the other motor and Don't use)
   </td>
  </tr>
  <tr>
   <td><strong>void Spin_Motor_PercentOutput()</strong>
<p>
Toggles the shooter
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
To be run in TeleopPeriodic to toggle the shooter with the press of a button (Don’t use)
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

