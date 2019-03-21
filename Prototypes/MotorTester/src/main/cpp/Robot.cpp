/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/GenericHID.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {

    // m_robotDrive.SetSafetyEnabled(false);

}

void Robot::TeleopPeriodic() {

  double throttle = m_gamepad.GetY( frc::GenericHID::kRightHand);
  
  double frontLeftSpeed = 0.0;
	double rearLeftSpeed = 0.0;
  double frontRightSpeed = 0.0;
	double rearRightSpeed = 0.0;

  if ( m_gamepad.GetAButton() ) {
    std::cout << "Back Right" << std::endl;
    rearRightSpeed = throttle;
  }

  if ( m_gamepad.GetBButton() ) {
    std::cout << "Rear Left" << std::endl;
    rearLeftSpeed = throttle;
  }

  if ( m_gamepad.GetXButton() ) {
    std::cout << "Rear Right" << std::endl;
    rearRightSpeed = throttle;
  }

  if ( m_gamepad.GetYButton() ) {
    std::cout << "Front Left" << std::endl;
    frontLeftSpeed = throttle;
  }

  m_frontLeftMotor.SetSpeed(frontLeftSpeed);
	m_rearLeftMotor.SetSpeed(frontLeftSpeed);
  m_frontRightMotor.SetSpeed(frontLeftSpeed);
	m_rearRightMotor.SetSpeed(frontLeftSpeed);

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif