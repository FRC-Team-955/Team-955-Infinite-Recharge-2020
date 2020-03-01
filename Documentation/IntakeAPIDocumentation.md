

<p style="text-align: right">
LW	 2 / 9 / 20</p>


Intake API Documentation


<table>
  <tr>
   <td><strong>Intake(TalonSRX *intake_talon, frc::Solenoid *solenoid_intake_right_0, frc::Solenoid *solenoid_intake_right_1, frc::Solenoid *solenoid_intake_left_0, frc::Solenoid *solenoid_intake_left_1, frc::Joystick *joystick);</strong>
<p>
Constructs an instance of Intake
<p>
Parameters:
<p>
intake_talon: Runs the motor that spins the wheels which intake the ball
<p>
solenoid_intake_right_0: the out solenoid for the rightmost pneumatic of the Intake deployment
<p>
solenoid_intake_right_1: the in solenoid for the rightmost pneumatic of the Intake deployment
<p>
solenoid_intake_left_0: the out solenoid for the leftmost pneumatic of the Intake deployment
<p>
solenoid_intake_left_1: the in solenoid for the leftmost pneumatic of the Intake deployment
<p>
joystick: joystick to use in controlling the Intake
   </td>
  </tr>
  <tr>
   <td><strong>void DeployIntakePNE();</strong>
<p>
Moves the intake between the deployed and undeployed positions at the press of a button 
<p>
Usage: 
<p>
Run in TelopPeriodic().
   </td>
  </tr>
  <tr>
   <td><strong>void RunIntake(float output_percentage);</strong>
<p>
Moves the motor to intake balls.
<p>
Parameters:
<p>
output_percentage: The PercentOutput to run the motor at.
<p>
Usage: 
<p>
Run in TelopPeriodic() 
   </td>
  </tr>
</table>


