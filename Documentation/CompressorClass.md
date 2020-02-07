<!----- Conversion time: 0.577 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β17
* Thu Feb 06 2020 20:30:01 GMT-0800 (PST)
* Source doc: https://docs.google.com/a/student.csd509j.net/open?id=1MlAOz3Ls8NgGvRGbAQq5PKHyOVgboGKRwB1OeyX5evw
----->


<p style="text-align: right">
OM 2/5/20</p>


CompressorClass API Documentation


<table>
  <tr>
   <td><strong>CompressorClass(Compressor *compressor)</strong>
<p>
Constructs an instance of ComprssorClass class.
<p>
Parameters:
<p>
Compressor *compressor = an instance of the compressor class
   </td>
  </tr>
  <tr>
   <td><strong>void CompressorOn()</strong>
<p>
Turns on the compressor closed loop controller
<p>
Useage:
<p>
Turns on the compressor closed loop controller when no voltage demanding tasks are running
   </td>
  </tr>
  <tr>
   <td><strong>void CompressorOff()</strong>
<p>
Turns off the compressor closed loop controller
<p>
Useage:
<p>
Turns off the compressor closed loop controller if the shooter is running
   </td>
  </tr>
  <tr>
   <td><strong>void CompressorBatteryVoltage(int volts)</strong>
<p>
Turns off the compressor closed loop controller when battery voltage is below a threshold
<p>
Parameters:
<p>
int volts = the threshold of battery volts at which the compressor will turn off
<p>
Useage:
<p>
Use to prevent the compressor from turning on when the shooter is running so that the robot won't brown out 
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->

