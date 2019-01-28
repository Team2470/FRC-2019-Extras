/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

using namespace std;
using namespace frc;

void Robot::RobotInit() {

	std::cout << "FOUR SOLENOID LIFT Bot" << std::endl;
}

void Robot::AutonomousInit() {

	cout << "ROBOT::AutonomousInit()" << endl;
}

void Robot::AutonomousPeriodic() {

}

void Robot::TeleopInit() {

	cout << "Robot::TeleopInit()" << endl;
}

void Robot::TeleopPeriodic() {

	// toggle based on gamepad bumper...
	if ( m_gamepad.GetBumper(GenericHID::kRightHand)) {

		if ( m_rightBumberDepressed == false )  {

			m_rightBumberDepressed = true;

			cout << "Toggle Direction of Front Solenoids" << endl;

			if ( m_doubleSolenoid_FR.Get() == DoubleSolenoid::Value::kForward  ) {

				m_doubleSolenoid_FR.Set(DoubleSolenoid::Value::kReverse);
				m_doubleSolenoid_FL.Set(DoubleSolenoid::Value::kReverse);
			}
			else {

				m_doubleSolenoid_FR.Set(DoubleSolenoid::Value::kForward);
				m_doubleSolenoid_FL.Set(DoubleSolenoid::Value::kForward);
			}
		}
	}
	else {

		m_rightBumberDepressed = false;
	}

	// toggle based on gamepad bumper...
	if ( m_gamepad.GetBumper(GenericHID::kLeftHand)) {

		if ( m_leftBumberDepressed == false )  {

			m_leftBumberDepressed = true;

			cout << "Toggle Direction of Back Solenoids" << endl;

			if ( m_doubleSolenoid_BR.Get() == DoubleSolenoid::Value::kForward  ) {

				m_doubleSolenoid_BR.Set(DoubleSolenoid::Value::kReverse);
				m_doubleSolenoid_BL.Set(DoubleSolenoid::Value::kReverse);
			}
			else {

				m_doubleSolenoid_BR.Set(DoubleSolenoid::Value::kForward);
				m_doubleSolenoid_BL.Set(DoubleSolenoid::Value::kForward);
			}
		}
	}
	else {

		m_leftBumberDepressed = false;
	}

	// drive the robot at half speed
	m_robotDrive.ArcadeDrive( (m_gamepad.GetY(GenericHID::kRightHand)) * 0.5, (m_gamepad.GetX(GenericHID::kRightHand))*0.5);

}

void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
