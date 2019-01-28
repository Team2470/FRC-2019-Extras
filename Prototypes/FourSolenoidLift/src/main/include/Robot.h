/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>

#include <frc/XboxController.h>
#include <frc/Spark.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Drive/DifferentialDrive.h>

#include <frc/DoubleSolenoid.h>

class Robot : public frc::TimedRobot {

public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	static constexpr int kGamepad = 0;

	static constexpr int kLeftMotors = 1;
	static constexpr int kRightMotors = 0;

	static constexpr int kDoubleSolenoidForwardChannel_FR = 2;
	static constexpr int kDoubleSolenoidReverseChannel_FR = 3;
	static constexpr int kDoubleSolenoidForwardChannel_FL = 0;
	static constexpr int kDoubleSolenoidReverseChannel_FL = 1;
	static constexpr int kDoubleSolenoidForwardChannel_BR = 4;
	static constexpr int kDoubleSolenoidReverseChannel_BR = 5;
	static constexpr int kDoubleSolenoidForwardChannel_BL = 6;
	static constexpr int kDoubleSolenoidReverseChannel_BL = 7;

	frc::XboxController m_gamepad{kGamepad};
	frc::Spark m_leftMotors{kLeftMotors};
	frc::Spark m_rightMotors{kRightMotors};
	frc::DifferentialDrive m_robotDrive{m_leftMotors, m_rightMotors};

	frc::DoubleSolenoid m_doubleSolenoid_FR{kDoubleSolenoidForwardChannel_FR, kDoubleSolenoidReverseChannel_FR};
	frc::DoubleSolenoid m_doubleSolenoid_FL{kDoubleSolenoidForwardChannel_FL, kDoubleSolenoidReverseChannel_FL};
	frc::DoubleSolenoid m_doubleSolenoid_BR{kDoubleSolenoidForwardChannel_BR, kDoubleSolenoidReverseChannel_BR};
	frc::DoubleSolenoid m_doubleSolenoid_BL{kDoubleSolenoidForwardChannel_BL, kDoubleSolenoidReverseChannel_BL};

	bool m_rightBumberDepressed = false;
	bool m_leftBumberDepressed = false;

	int m_frameCounter = 0;

};
