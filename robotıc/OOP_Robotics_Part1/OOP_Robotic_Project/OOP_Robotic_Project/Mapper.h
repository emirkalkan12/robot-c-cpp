/**
 * @file   Mapper.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the Mapper class.
 *
 * This file contains the definition of the Mapper class, which represents
 * a system for mapping the environment of a robot using lidar sensor data
 * and robot control information. It provides functionalities for updating the map,
 * saving the map to a file, and displaying the current map.
 */
#ifndef MAPPER_H
#define MAPPER_H

#include "MAP.h"
#include "RobotControler.h"
#include "LidarSensor.h"
#include "Record.h"
#include <iostream>

 /**
  * @class Mapper
  * @brief Maps the environment using lidar sensors and robot control data.
  *
  * The Mapper class manages a grid-based map using data from a LidarSensor and a
  * RobotControler. It provides methods to update the map based on sensor data,
  * save the map to a file, and display the map visually.
  */
class Mapper {
private:
    MAP* map;                      /**< Haritayý temsil eden MAP sýnýfý pointer'ý. */
    RobotControler* robotControler; /**< Robotun pozisyonunu ve hareketlerini yöneten sýnýf pointer'ý. */
    LidarSensor* lidarSensor;      /**< Lidar sensör verilerini saðlayan sýnýf pointer'ý. */

public:
    /**
     * @brief Default constructor.
     */

    
    /*
    * @brief Default constructor.
    * 
    * Initializes the Mapper with a default map, robot controler, and lidar sensor.
    * @param map Pointer to the MAP object representing the map.
    * @param robotControler Pointer to the RobotControler object managing the robot.
    * @param lidarSensor Pointer to the LidarSensor object providing sensor data.
    * 
    */
    Mapper(MAP* map, RobotControler* robotControler, LidarSensor* lidarSensor);

    
    /**
     * @brief Updates the map using lidar sensor data.
     *
     * Retrieves the latest data from the lidar sensor and updates the map accordingly.
     */
    void updateMap();

    /**
     * @brief Saves the current state of the map to a file.
     *
     * Stores the map data into a file for later use.
     * @return True if the map is successfully saved, false otherwise.
     */
    bool recordMap();

    /**
     * @brief Displays the current map on the console.
     *
     * Prints the current state of the map grid to the console for visualization.
     */
    void showMap();
};

#endif // MAPPER_H
