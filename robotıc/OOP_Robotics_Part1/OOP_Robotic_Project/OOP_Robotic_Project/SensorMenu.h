/**
 * @file SensorMenu.h
 * @author Furkan Gemici
 * @date December, 2024
 * @brief Declaration of the SensorMenu.h class.
 *
*
 * This class is responsible for managing the sensor menu and interactions,
 * allowing users to retrieve and display sensor-related information.
 */

#include <string>
#include "Menus.h"
#include "SensorInterface.h"
#include "LidarSensor.h"
#include "IRSensor.h"

#ifndef SENSORMENU_H
#define SENSORMENU_H

class SensorMenu : public Menus {
private:
	int state0 = 0;
	int state1 = 1;
	string choice = "1. IR Sensor Info\n"
		"2. Lidar Sensor Info\n"
		"3. Back\n"
		"4. Quit\n";
public:
	SensorMenu(Robot* robot) : Menus(robot) {}
	void printChoice() override;

	bool run() override;
};

#endif
