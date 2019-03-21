/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <iostream>


void Robot::RobotInit() {
  
}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  
  std::cout << "I'm in AutonomousInit()" << std::endl;
}

void Robot::AutonomousPeriodic() {

  frameCounter = frameCounter + 1;
  
  if (frameCounter == 50) {
    std::cout << countCounter << std::endl;
    countCounter = countCounter + 1;
    frameCounter = 0;
  }
}

void Robot::TeleopInit() {
  
  std::cout << "TeleopInit, READY!!" << std::endl;
}

void Robot::TeleopPeriodic() {

  /*
  if ( m_gamepad.GetBumper(frc::GenericHID::kRightHand)) {
    std::cout << "Right Button Pressed!" << std::endl;
  }
  if ( m_gamepad.GetBumper(frc::GenericHID::kLeftHand)) {
    std::cout << "Left Button Pressed!" << std::endl;
  }
  */

/*
  if ( m_gamepad.GetBumper(frc::GenericHID::kRightHand)) {
    
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 1.0);
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0.0);
  } 

  if ( m_gamepad.GetBumper(frc::GenericHID::kLeftHand)) {
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 1.0);
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0.0);
  }

  if (m_gamepad.GetAButton()){
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0.0);
    m_gamepad.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0.0);
  }
*/

// todo add the arcade drive code here....
m_robotDrive.TankDrive(m_gamepad.GetY(frc::GenericHID::kRightHand), m_gamepad.GetX(frc::GenericHID::kRightHand));


  // output the distance, in inches, from the ultrasonic sensor 
  // equation determined from measuring the actual readings and 
  // graphing the results: y = mx + b
  double currentDistance = 0.140 * m_ultrasonic.GetValue() - 1.32;
  std::cout << currentDistance << std::endl;
}

void Robot::TestPeriodic() {

}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
