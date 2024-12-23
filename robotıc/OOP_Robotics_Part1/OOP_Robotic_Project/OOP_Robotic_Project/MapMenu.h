/**
 * @file MapMenu.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the MapMenu.h class.
 *
 * This class is responsible for managing the map menu of the robot.
 *
 */
#pragma once

#include "Menus.h"
#include "MAP.h"
#include "Mapper.h"
#include "LidarSensor.h"
#include "IRSensor.h"

class MapMenu : public Menus {
private:
    string choice = "1. Update Map\n"
		"2. Record Map\n"
		"3. Show Map\n"
		"4. Back\n"
		"5. Quit\n";

public:
    MapMenu(Robot* robot) : Menus(robot) {}

	void printChoice() override;

	bool run();
};