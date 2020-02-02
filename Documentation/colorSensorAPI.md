<!----- Conversion time: 0.611 seconds.


Using this Markdown file:

1. Cut and paste this output into your source file.
2. See the notes and action items below regarding this conversion run.
3. Check the rendered output (headings, lists, code blocks, tables) for proper
   formatting and use a linkchecker before you publish this page.

Conversion notes:

* Docs to Markdown version 1.0β17
* Sun Feb 02 2020 14:32:55 GMT-0800 (PST)
* Source doc: https://docs.google.com/a/student.csd509j.net/open?id=1khIthIYxJF8ERSHGNQhb5NNzGmnaRVx2kQ_aimf4EJw
----->


<p style="text-align: right">
OM-1/29/2020</p>


ColorSensor API Documentation


<table>
  <tr>
   <td><strong>ColorSensor(ColorSensorV3 *color_sensor, ColorMatch *color_matcher)</strong>
<p>
Constructs an instance of ColorSensor
<p>
Parameters:
<p>
ColorSensorV3 *color_sensor = an object of the ColorSensorV3 class
<p>
ColorMatch *color_matcher = an object of the ColorMatch class
   </td>
  </tr>
  <tr>
   <td><strong>void SetBlue(double red, double green, double blue)</strong>
<p>
Sets the blue color on the control panel for use in FindClosestColor()
<p>
Parameters:
<p>
double red = a double between 0-1 that sets the red component
<p>
double green = a double between 0-1 that sets the green component
<p>
double blue = a double between 0-1 that sets the blue component
<p>
Usage:
<p>
To be run in RobotInit to tune the sensor to the venue’s lighting conditions
   </td>
  </tr>
  <tr>
   <td><strong>void SetGreen(double red, double green, double blue)</strong>
<p>
Sets the green color on the control panel for use in FindClosestColor()
<p>
Parameters:
<p>
double red = a double between 0-1 that sets the red component
<p>
double green = a double between 0-1 that sets the green component
<p>
double blue = a double between 0-1 that sets the blue component
<p>
Usage:
<p>
To be run in RobotInit to tune the sensor to the venue’s lighting conditions
   </td>
  </tr>
  <tr>
   <td><strong>void SetYellow(double red, double green, double blue)</strong>
<p>
Sets the blue color on the control panel for use in FindClosestColor()
<p>
Parameters:
<p>
double red = a double between 0-1 that sets the red component
<p>
double green = a double between 0-1 that sets the green component
<p>
double blue = a double between 0-1 that sets the blue component
<p>
Usage:
<p>
To be run in RobotInit to tune the sensor to the venue’s lighting conditions
   </td>
  </tr>
  <tr>
   <td><strong>void SetRed(double red, double green, double blue)</strong>
<p>
Sets the red color on the control panel for use in FindClosestColor()
<p>
Parameters:
<p>
double red = a double between 0-1 that sets the red component
<p>
double green = a double between 0-1 that sets the green component
<p>
double blue = a double between 0-1 that sets the blue component
<p>
Usage:
<p>
To be run in RobotInit to tune the sensor to the venue’s lighting conditions
   </td>
  </tr>
  <tr>
   <td><strong>std::string FindClosestColor()</strong>
<p>
Matches the raw value of the color sensor to the color swatches on the control panel
<p>
Returns:
<p>
The name of the color the sensor detected: “Blue”, “Red”, “Green”, “Yellow”, or “Unknown”.
<p>
Usage: \
Use to display what color the sensor detects or as closestC in IsMatch()
   </td>
  </tr>
  <tr>
   <td><strong>frc::Color GetColor()</strong>
<p>
Get the normalized RGB color from the sensor
<p>
Returns:
<p>
frc::Color class with normalized sRGB value
<p>
Usage:
<p>
Find values for SetBlue, SetRed, etc...
   </td>
  </tr>
  <tr>
   <td><strong>std::string GetFMSColor()</strong>
<p>
Gets the color sent by FMS
<p>
Returns:
<p>
a string with the assigned FMS color: “R”, ”G”, ”B”, ”Y”, or “n/a”
<p>
Usage:
<p>
Use to findwhat color the control panel must be spun to
   </td>
  </tr>
  <tr>
   <td><strong>bool IsMatch(std::string fms_color, std::string closest_color)</strong>
<p>
Parameters:
<p>
fms_color = the color assigned by FMS
<p>
closest_color = the color returned from FindClosestColor
<p>
Returns:
<p>
true: if the FMS color and closest color match
<p>
false:  if the FMS color and closest color do not match
<p>
Usage:
<p>
Determines when position control is completed
   </td>
  </tr>
  <tr>
   <td><strong>int CountColors()</strong>
<p>
Returns:
<p>
an int counting how many different color swatches have passed by
<p>
Usage:
<p>
Determine how far the wheel has spun in rotation control
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->

