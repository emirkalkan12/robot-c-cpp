/**
 * @file Robot.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the Robot.h class.
 *
 * This class is responsible for managing the robot's components and interactions.
 *
 */
#pragma once

#include "RobotControler.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
// sensor.h
#include <iostream>
#include <string>
#include "IRSensor.h"
#include "LidarSensor.h"
#include "FestoRobotInterface.h"
#include "SafeNavigation.h"

class Robot {
public:
    FestoRobotAPI* robotAPI;
    RobotControler* robotControler;
    //MapManager* mapManager;
    SafeNavigation* safeNavigation;
    FestoRobotInterface* robot;
    Robot();
};