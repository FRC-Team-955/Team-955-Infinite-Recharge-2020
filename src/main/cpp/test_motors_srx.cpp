#include <test_motors_srx.h>
#include <ctre/Phoenix.h>

using namespace frc;


void TestMotorsSRX::RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder)
{
	if (joystick -> GetRawButton(button_forward))            //Press button_foward to run forward
    {
    	talon -> Set(ControlMode::PercentOutput, output_percentage);
		std::cout<<"Get RunMotor Joystick Input! Just not running it."<<std::endl;
    }
    else if (joystick -> GetRawButton(button_backward))            //Press button_backward to run backward
    {
    	talon -> Set(ControlMode::PercentOutput, -output_percentage); 
	}
	else           //Dont press to stop the motor (or, like... disable it)
	{
    	talon -> Set(ControlMode::PercentOutput, 0);
	}

	print->AddToPipeDelimitedFile("Time", print->ToString(timer->Get()), storage_header, storage, false);
	print->AddToPipeDelimitedFile("Battery Voltage", print->ToString(DriverStation::GetInstance().GetBatteryVoltage()), storage_header, storage, false);
	if (has_encoder == true) 
	{
		print->AddToPipeDelimitedFile("Talon Amperage", print->ToString(talon->GetOutputCurrent()), storage_header, storage, false);
		print->AddToPipeDelimitedFile("Talon Velocity", print->ToString(talon->GetSelectedSensorVelocity(0)), storage_header, storage, false);
	}	
	print->EndLoop(storage);
	
}

void TestMotorsSRX::SaveVersionNum()
{
	int version = print -> SaveVersionNumber();
    std::cout<<"TestMotors Luke V"<<version<<std::endl;
}

void TestMotorsSRX::SaveData()
{
	if (storage.find(std::string("|")) != std::string::npos) print->CreateSaveFile(storage_header + "\n" + storage);
}
void TestMotorsSRX::StartTimer()
{
	timer -> Start();
}
