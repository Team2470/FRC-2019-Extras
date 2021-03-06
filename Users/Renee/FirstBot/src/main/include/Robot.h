/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Ultrasonic.h>
#include <frc/AnalogInput.h>
#include <Spark.h>
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
  	frc::XboxController m_gamepad{0}; 

    int frameCounter = 0;
    int countCounter = 1;

    frc::AnalogInput m_ultrasonic{2};

    // todo: create variable for motor controller
    
    frc::Spark m_leftMotor {1};
    frc::Spark m_rightMotor{0};
    frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};

    
  
   
};
