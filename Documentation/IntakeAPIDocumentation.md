
<p style="text-align: right">
LW	 2 / 9 / 20</p>


Intake API Documentation


<table>
  <tr>
   <td><strong>Intake( TalonSRX *deployment_talon, Solenoid *pneu, TalonSRX *intake_talon, Joystick *joystick);</strong>
<p>
Constructs an instance of Intake
<p>
Parameters:
<p>
depoyment_talon: The talon which moves the intake mechanism outside of frame perimeter and into its ball-receiving position.  (Only relevant if the bot uses a talon for this)
<p>
pneu: The pneumatic version of deployment_talon (Only relevant if the bot uses a pneumatic)
<p>
intake_talon: Runs the motor that spins the wheels which intake the ball
<p>
joystick: joystick to use in controlling the Intake
   </td>
  </tr>
  <tr>
   <td><strong>void DeployIntakeSRX( int input_button, int rotation_distance);</strong>
<p>
Moves the intake between the deployed and undeployed positions at the press of a button (DeployIntakeSRX uses a talonSRX and DeployIntakePNE uses a pneumatic)
<p>
Parameters:
<p>
input_button: the number associated with the button to deploy/undeploy.
<p>
rotation_distance: the distance (in encoder ticks) for the motor to turn to deploy 
<p>
Usage: 
<p>
Run in TelopPeriodic().
   </td>
  </tr>
  <tr>
   <td><strong>void DeployIntakePNE( int input_button);</strong>
<p>
Moves the intake between the deployed and undeployed positions at the press of a button (DeployIntakeSRX uses a talonSRX and DeployIntakePNE uses a pneumatic)
<p>
Parameters:
<p>
input_button: the number associated with the button to deploy/undeploy.
<p>
rotation_distance: the distance (in encoder ticks) for the motor to turn to deploy 
<p>
Usage: 
<p>
Run in TelopPeriodic().
   </td>
  </tr>
  <tr>
   <td><strong>void RunIntake( int input_button, float output_percentage);</strong>
<p>
Moves the motor to intake balls.
<p>
Parameters:
<p>
input_button: the number associated with the button to run the motor.
<p>
output_percentage: The PercentOutput to run the motor at.
<p>
Usage: 
<p>
Run in TelopPeriodic() 
   </td>
  </tr>
  <tr>
   <td><strong>void ApplyDeploySoftLimits( int forward_limit, int backward_limit);</strong>
<p>
Configures and enables soft limits on the deployment_talon.
<p>
Parameters:
<p>
forward_limit: the desired soft limit in the direction positive on the motor.
<p>
backward_limit: the desired soft limit in the direction negative on the motor.
<p>
Usage:
<p>
Run in RobotInit()
   </td>
  </tr>
</table>


