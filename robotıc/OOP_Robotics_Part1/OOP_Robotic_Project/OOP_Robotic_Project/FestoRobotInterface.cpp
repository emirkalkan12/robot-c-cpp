#pragma once
#include "FestoRobotInterface.h"
#include <iostream>
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "SensorInterface.h"
#include "Pose.h"
#include "RobotInterface.h"



FestoRobotInterface::FestoRobotInterface(FestoRobotAPI* _robotAPI)
{
	this->robotAPI = _robotAPI;
	this->position = new Pose(0, 0, 0);
	this->status = 0;

	SensorInterface* lidar = new LidarSensor(this->robotAPI);

	this->addSensor(new LidarSensor(this->robotAPI));
	this->addSensor(new IRSensor(this->robotAPI));

}


/**
 * @brief Updates the internal position information based on the current robot status.
 */


void FestoRobotInterface::updatePositions()
{

	double x, y, th;
	this->robotAPI->getXYTh(x, y, th);
	this->position->setPose(x, y, th);
}


/**
 * @brief Turns the robot to the left.
 */
void FestoRobotInterface::turnLeft()
{
	this->robotAPI->rotate(LEFT);
}

/**
 * @brief Turns the robot to the right.
 */
void FestoRobotInterface::turnRight()
{
	this->robotAPI->rotate(RIGHT);
}

/**
 * @brief Moves the robot forward.
 */
void FestoRobotInterface::moveForward()
{
	this->robotAPI->move(FORWARD);
	Sleep(2000);
}

/**
 * @brief Prints the current status and position of the robot.
 */
void FestoRobotInterface::print()
{
	std::cout << "status : " << this->status << std::endl;

	std::cout << "Robot' s position : " << std::endl;
	std::cout << "X : " << this->position->getX() << std::endl;
	std::cout << "Y : " << this->position->getY() << std::endl;
	std::cout << "Th : " << this->position->getTh() << std::endl;
}

void FestoRobotInterface::connect()
{
	robotAPI->connect();
	Sleep(100);

	this->updatePositions();
	this->updateSensors();
}

void FestoRobotInterface::changeStatus(int newStatus)
{
	this->status = newStatus;
}

vector<SensorInterface*> FestoRobotInterface::getSensors()
{
	return *this->sensorList;
}

/**
 * @brief Moves the robot backward.
 */

void FestoRobotInterface::moveBackward()
{
	this->robotAPI->move(BACKWARD);
}

/**
 * @brief Moves the robot to the left.
 */
void FestoRobotInterface::moveLeft()
{
	this->robotAPI->move(LEFT);
}

/**
 * @brief Moves the robot to the right.
 */
void FestoRobotInterface::moveRight()
{
	this->robotAPI->move(RIGHT);
}


/**
 * @brief Stops the robot's motion.
 */
void FestoRobotInterface::stop()
{
	this->robotAPI->stop();
	this->updatePositions();
	this->updateSensors();
}


