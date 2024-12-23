/**
 * @file RobotInterface.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the RobotInterface.h class.
 *
 * This class is responsible for managing the robot's interface and interactions.
 */
#include <vector>
#include "Pose.h"
#include "SensorInterface.h"
#include "LidarSensor.h"
#include "IRSensor.h"

#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H

class RobotInterface
{
public:
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;
    virtual void moveForward() = 0;
    virtual void moveBackward() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void stop() = 0;
    virtual void print() = 0;

    Pose* getPose();
    void updateSensors();
    void addSensor(SensorInterface* sensor);

protected:
    Pose* position;
    int status;
    std::vector<SensorInterface*>* sensorList = new vector<SensorInterface*>;
};

#endif // ROBOT_INTERFACE_H