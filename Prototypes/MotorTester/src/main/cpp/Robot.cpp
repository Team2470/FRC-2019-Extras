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

  m_frontLeftMotors.SetInverted(true);
  m_backLeftMotors.SetInverted(true);
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

  double xr_move = m_gamepad.GetX( frc::GenericHID::kRightHand);
  double yr_move = m_gamepad.GetY( frc::GenericHID::kRightHand);
  double xl_move = m_gamepad.GetX( frc::GenericHID::kLeftHand);
  double yl_move = m_gamepad.GetY( frc::GenericHID::kLeftHand);

  // m_robotDrive.DriveCartesian(y_move, x_move, 0.0);
  m_robotDrive1.TankDrive(xr_move, yr_move);
  m_robotDrive2.TankDrive(xl_move, yl_move);

  // if ( m_gamepad.GetAButton() ) {
  //   std::cout << "Back Right" << std::endl;
  //   m_backRightMotors.SetSpeed( 0.5 );
  // } else {
  //   m_backRightMotors.SetSpeed( 0.0 );
  // }

  // if ( m_gamepad.GetBButton() ) {
  //   std::cout << "Back Left" << std::endl;
  //   m_backLeftMotors.SetSpeed( 0.5 );
  // } else {
  //   m_backLeftMotors.SetSpeed( 0.0 );
  // }

  // if ( m_gamepad.GetXButton() ) {
  //   std::cout << "Front Right" << std::endl;
  //   m_frontRightMotors.SetSpeed( 0.5 );
  // } else {
  //   m_frontRightMotors.SetSpeed( 0.0 );
  // }

  // if ( m_gamepad.GetYButton() ) {
  //   std::cout << "Front Left" << std::endl;
  //   m_frontLeftMotors.SetSpeed( 0.5 );
  // } else {
  //   m_backLeftMotors.SetSpeed( 0.0 );
  // }

}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
