<p style="text-align: right">
EW 2/7/2020</p>


Version API Documentation


<table><p style="text-align: right">
EW 2/7/2020</p>


Version API Documentation


<table>
  <tr>
   <td><strong>Version(std::string filename)</strong>
<p>
Constructs an instance of version/data control
<p>
Parameters:
<p>
filename = a string without spaces that is specific to the code you are running
   </td>
  </tr>
  <tr>
   <td><strong>int SaveVersionNumber()</strong>
<p>
Saves the version number of your code (based on filename) to a file on the roboRio
<p>
Returns:
<p>
The numerical version of your file
<p>
Usage:
<p>
Run in RobotInit to increment file version every deploy. Print out the version number to verify that your code deployed.
   </td>
  </tr>
  <tr>
   <td><strong>std::string ToString(float number)</strong>
<p>
Converts a number into a string to be saved and printed out
<p>
Parameters:
<p>
number: the number you want to convert into a string, can be of any type (int, bool, float, etc)
<p>
Returns:
<p>
A string that represents that number
<p>
Usage:
<p>
Can be used to convert the second parameter for AddToPipeDelimitedFile() (the data) into a string. 
   </td>
  </tr>
  <tr>
   <td><strong>void AddToPipeDelimitedFile(std::string topic, std::string data, std::string &storage_topic, std::string &storage_data, bool print)</strong>
<p>
Adds data to a string such that it will be dumped into a table like format (a pipe delimited file) once the robot is disabled. Also adds the meaning of that data (the topic) into a separate string to be dumped as the header to the file. Also prints the data in the form: topic: data
<p>
Parameters:
<p>
topic: a string representing the meaning of the data
<p>
data: a string with the value that you are printing out
<p>
storage_topic: a string pointer (create an empty string where you point to the talons and joysticks) that will be filled with all of the topics you create (a string pointer returns a value without returning anything by filling memory that has already been allocated)
<p>
storage_data: a string pointer (same steps as above) that will be filled with all of the data you store
<p>
print: a boolean that represents if you want the data to print to the driver station or not (true to print, false to not print it, such as if you want to speed up response time and avoid lag)
<p>
Usage:
<p>
Run in TeleopPeriodic for all print statements that are NOT only run when conditions are met (ie. If statements, for loops). storage_topic and storage_data should be initialized where the pointers are, outside of the scope of any functions. data should be first converted to a string. 
<p>
If your program meets the criteria inside of the ** **, it needs to have the corresponding usage of the function. The instance of version is called “print” in these examples: (note, be specific about which talon’s amperage/position/velocity it is. Don’t use “Talon”, use “Talon Elevator”, etc. 
<ol>

<li>** Has any talons, use for each talon ** print->AddToPipeDelimitedFile(“Talon Amperage”, print->ToString(talon->GetOutputCurrent()), storage_topic, storage_data, true)

<li>** Is a program (make sure to construct an instance of Timer, shown here as timer) ** print->AddToPipeDelimitedFile(“Time”, print->ToString(timer->Get()), storage_topic, storage_data, true)

<li>** Is a program ** print->AddToPipeDelimitedFile(“Battery Voltage”, print->ToString(DriverStation::GetInstance().GetBatteryVoltage()), storage_topic, storage_data, true)

<li>** Has encoder on the talon, use for each talon with an encoder ** print->AddToPipeDelimitedFile(“Talon Velocity”, print->ToString(talon->GetSelectedSensorVelocity(0)), storage_topic, storage_data, true)

<li>** Has encoder on the talon, use for each talon with an encoder ** print->AddToPipeDelimitedFile(“Talon Position”, print->ToString(talon->GetSelectedSensorPosition(0)), storage_topic, storage_data, true)

<li>ANY OTHER IMPORTANT VARIABLES
</li>
</ol>
   </td>
  </tr>
  <tr>
   <td><strong>void EndLoop(std::string &string_data)</strong>
<p>
Adds a newline at the end of the data string so that it is ready to add more data.
<p>
Parameters:
<p>
string_data: the string pointer that is used to store the data from AddToPipeDelimitedFile()
<p>
Usage:
<p>
Use at the end of the TeleopPeriodic loop (last line of the function)
   </td>
  </tr>
  <tr>
   <td><strong>void CreateSaveFile(std::string string_total)</strong>
<p>
Dumps all of the data from TeleopPeriodic into a text file based on the version of the code, the filename, and the date and time
<p>
Parameters: \
string_total: a string encompassing the topic string and the data string
<p>
Usage:
<p>
To format string_total in the correct way, use CreateSaveFile(string_topic + “\n” + string_data). Run in DisabledInit (don’t forget to add DisabledInit to Robot.h too). If you want to add something helpful, only run CreateSaveFile when string_data has data in it (otherwise it also runs after you deploy your code).
   </td>
  </tr>
  <tr>
   <td><strong>std::string GetFileName()</strong>
<p>
Returns the title that is included in the version number and data file names
<p>
Usage:
<p>
To verify that the right data file has been received or to print out to check the right code is on the bot before enabling
   </td>
  </tr>
</table>



<!-- Docs to Markdown version 1.0β17 -->
</table>