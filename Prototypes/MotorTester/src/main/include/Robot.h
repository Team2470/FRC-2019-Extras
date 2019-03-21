/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/Spark.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/drive/DifferentialDrive.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  static constexpr int kGamepad = 0;
	static constexpr int kFrontLeftMotors = 0;
  static constexpr int kRearLeftMotors = 1;
  static constexpr int kFrontRightMotors = 2;
	static constexpr int kRearRightMotors = 3;

  frc::XboxController m_gamepad{kGamepad};

	frc::Spark m_frontLeftMotor{kFrontLeftMotors};
	frc::Spark m_rearLeftMotor{kRearLeftMotors};
  frc::Spark m_frontRightMotor{kFrontRightMotors};
	frc::Spark m_rearRightMotor{kRearRightMotors};
	
};
