#include <test_motors_fx.h>
#include <ctre/Phoenix.h>

using namespace frc;

void TestMotorsFX::RunMotor(float output_percentage, int button_forward, int button_backward, bool has_encoder)
{
	if (joystick -> GetRawButton(1))            //Press A to run forward
    {
    	talon -> Set(ControlMode::PercentOutput, output_percentage);
    }
    else if (joystick -> GetRawButton(2))            //Press B to run backward
    {
    	talon -> Set(ControlMode::PercentOutput, -output_percentage); 
	}
	else           //Press Y to stop the motor (or, like... disable it)
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

void TestMotorsFX::SaveVersionNum()
{
	int version = print -> SaveVersionNumber();
    std::cout<<"TestMotors Luke V"<<version<<std::endl;
}

void TestMotorsFX::SaveData()
{
	if (storage.find(std::string("|")) != std::string::npos) print->CreateSaveFile(storage_header + "\n" + storage);
}
void TestMotorsFX::StartTimer()
{
	timer -> Start();
}
