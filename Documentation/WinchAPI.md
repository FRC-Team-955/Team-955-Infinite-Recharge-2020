<!----- Conversion time: 0.579 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β17
* Tue Feb 04 2020 18:07:04 GMT-0800 (PST)
* Source doc: https://docs.google.com/a/student.csd509j.net/open?id=1kw0c90MzhzvLyuGz5SmanO2S6valWcnoD6NrluF2Cis
----->


<p style="text-align: right">
Owen McManus 2/4/2020</p>


Winch API Documentation


<table>
  <tr>
   <td><strong>Winch(TalonSRX *talon_winch_enc)</strong>
<p>
Constructs an instance of the Winch class
<p>
Parameters: 
<p>
TalonSRX *talon_winch_enc = a member of the TalonSRX the will spool in the winch
   </td>
  </tr>
  <tr>
   <td><strong>void RaiseWinchButton(int tics)</strong>
<p>
Spools in the winch a given number of tics
<p>
Parameters:
<p>
int tics = the number of tics the winch will spin when lifting the robot
<p>
Usage:
<p>
Used to raise the robot after ataching the hook in endgame
   </td>
  </tr>
  <tr>
   <td><strong>void RaiseWinchAxis()</strong>
<p>
Spools in the according to a joystick
<p>
Usage:
<p>
Use to raise the robot using a joystick input
   </td>
  </tr>
   <td><strong>void LowerWinch()</strong>
<p>
Resets the winch back to 0 tics
<p>
Useage:
<p>
Used to lower the robot if something bad happens
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->

