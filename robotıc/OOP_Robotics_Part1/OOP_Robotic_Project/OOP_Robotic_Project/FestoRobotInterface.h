/**
 * @file FestoRobotInterface.h
 * @author Furkan Gemici
 * @date December, 2024
 * @brief Declaration of the FestoRobotInterface.h class.
 *
 * This class is responsible for managing the Festo robot interface, including moving the robot and updating its position.
 *
 */
#include <vector>
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "Pose.h"
#include "RobotInterface.h"
#include "SensorInterface.h"

#ifndef NAOROBOTINTERFACE_H
#define NAOROBOTINTERFACE_H

class FestoRobotInterface : public RobotInterface
{
private:
    FestoRobotAPI* robotAPI;
public:
    FestoRobotInterface(FestoRobotAPI* _robotAPI);
    void turnLeft() override;
    void turnRight() override;
    void moveForward() override;
    void moveBackward() override;
    void moveLeft() override;
    void moveRight() override;
    void stop() override;
    void print() override;
    void connect();
    void changeStatus(int newStatus);
    void updatePositions();







    vector<SensorInterface*> getSensors();
};

#endif