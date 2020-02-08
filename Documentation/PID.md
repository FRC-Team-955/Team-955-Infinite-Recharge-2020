<!----- Conversion time: 0.501 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β17
* Fri Feb 07 2020 18:38:05 GMT-0800 (PST)
* Source doc: https://docs.google.com/open?id=1G8P13xFbMThqFNxjxfZb3T0Tk2NmJL1ylNoXoup8muM
----->


J L

2/7/2020

PID API DOCUMENTATION


<table>
  <tr>
   <td>PID ()
<p>
Construct an instance of PID Class
<p>
No parameters needed
   </td>
  </tr>
  <tr>
   <td>Void PID::PIDTune((TalonSRX * talon_enc,  double p_value, double i_value, double d_value, double f_value)
<p>
Configs the PID Values for a SINGLE talon!
<p>
Parameters:
<p>
Talon_enc = the talon to set pid values
<p>
P_value = the p value to set to the talon
<p>
I_value = the i value to set to the talon
<p>
D_value = the d value to set to the talon
<p>
F_value = the f value to set to the talon (used in velocity only)
<p>
Returns: nothing
<p>
Usage:
<p>
Use in TeleopInit() and AutonomousInit() to config the talon
<p>
Example:
<p>
talonpid ->PIDTune(drive_talon_right_enc, 3, 0.1, 0, 0);
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->
