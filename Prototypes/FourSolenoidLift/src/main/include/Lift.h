/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <vector>
#include <frc/Solenoid.h>
#include <frc/DoubleSolenoid.h>


class Lift {
 public:
  Lift();

  void AddSolenoid(frc::DoubleSolenoid& solenoid);
  void AddSolenoid(frc::Solenoid& solenoid);

  private:
    std::vector<frc::DoubleSolenoid> m_dblSolenoids;
    std::vector<frc::DoubleSolenoid> m_sglSolenoids;

    
};
