

#include <iostream>
#include <string>
using namespace std;
#include "Pose.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "RobotControler.h"



RobotControler::RobotControler(FestoRobotInterface* _robot)
    : robotOperator(name, surname, accessCode), record("output.txt") {
    this->robot = _robot;
    robot->connect();
    this->position = new Pose();
    Sleep(100);

    this->robot->changeStatus(1);
}

RobotControler::~RobotControler() {
    delete this->position;
    cout << "RobotControler destroyed and resources cleaned up." << endl;
}

/**
 * @brief This function turns the robot to the left if it is connected.
 */
void RobotControler::turnLeft() {
    robot->turnLeft();
}

/**
 * @brief This function turns the robot to the right if it is connected.
 */
void RobotControler::turnRight() {
    robot->turnRight();

}

/**
 * @brief This function moves the robot forward if it is connected.
 */
void RobotControler::moveForward() {
    robot->moveForward();
}

/**
 * @brief This function moves the robot backward if it is connected.
 */
void RobotControler::moveBackward() {
    robot->moveBackward();
}

/**
 * @brief This function moves the robot to the left if it is connected.
 */
void RobotControler::moveLeft() {
    robot->moveLeft();
}

/**
 * @brief This function moves the robot to the right if it is connected.
 */
void RobotControler::moveRight() {
    robot->moveRight();
}

/**
 * @brief This function stops the robot if it is connected.
 */
void RobotControler::stop() {
    robot->stop();
}

/**
 * @brief This function returns the current position and orientation of the robot.
 * @return The current position of the robot as a Pose object.
 */
Pose RobotControler::getPose() {
    cout << "Getting the current position of the robot." << endl;
    double x, y, th;
    this->robotAPI->getXYTh(x, y, th);
    this->position->setX(x);
    this->position->setY(y);
    this->position->setTh(th);
    return *this->position;
}

/**
 * @brief This function prints the current status of the robot.
 */
void RobotControler::print() {
    robot->print();
}

/**
 * @brief This function connects the robot to the API if it is not already connected.
 * @return true if the connection is successful, false otherwise.
 */
bool RobotControler::connectRobot() {
    if(!this->connectionStatus && this->robotAPI != nullptr) {
		this->robotAPI->connect();
		this->connectionStatus = true;
		cout << "RobotControler connected successfully." << endl;
	}
    return this->connectionStatus;
}

/**
 * @brief This function disconnects the robot from the API if it is connected.
 * @return true if the disconnection is successful, false otherwise.
 */
bool RobotControler::disconnectRobot() {
    if (this->connectionStatus && this->robotAPI != nullptr) {
        this->robotAPI->disconnect();
        this->connectionStatus = false;
        cout << "RobotControler disconnected successfully." << endl;
    }
    return this->connectionStatus;
}

SensorInterface* RobotControler::getSensor(string type) {
    for (int i = 0; i < robot->getSensors().size(); i++)
    {
        if (this->robot->getSensors()[i]->getSensorType() == type)
        {
            return this->robot->getSensors()[i];
        }
    }

    return nullptr;
}

void RobotControler::printSensor(string type)
{
    for (int i = 0; i < robot->getSensors().size(); i++)
    {
        if (this->robot->getSensors()[i]->getSensorType() == type)
        {
            this->robot->getSensors()[i]->print();
        }
    }
}

bool RobotControler::recordSensor(string type)
{
    /*for (int i = 0; i < robot->getSensors().size(); i++)
    {
        if (this->robot->getSensors()[i]->getSensorType() == type)
        {
            this->record << this->robot->getSensors()[i];
            return true;
        }
    }*/

    return false;
}