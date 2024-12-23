/**
 * @file   MAP.h
 * @author Emirhan Kalkan
 * @date   December, 2024
 * @brief  Header file for the MAP class.
 *
 * This file contains the definition of the MAP class, which represents
 * a map system responsible for storing, updating, and managing the map.
 * It provides utilities for inserting points, getting and setting grid values,
 * clearing the map, printing map information, and showing the map.
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "Point.h"
 /**
  * @class MAP
  * @brief Represents a map system responsible for storing, updating, and managing the map.
  *
  * The MAP class provides functionalities to manage a grid-based map. It includes methods
  * to insert points, modify and access grid values, clear the map, print its details, and
  * display the map visually.
  */
class MAP {
private:
    std::vector<std::vector<int>> grid; /*!< 2D vector to store the map grid. */
    int numberX;  /*!< Number of grids in the x direction. */
    int numberY;  /*!< Number of grids in the y direction. */
    double gridSize; /*!< Size of each grid cell. */

public:
    /**
    * @brief Default constructor.
    *
    * Initializes the map with default parameters.
    */
    MAP();
    /**
    * @brief Constructor that initializes the map with the given parameters.
    *
    * @param numberX Number of grids in the x direction.
    * @param numberY Number of grids in the y direction.
    * @param gridSize Size of each grid cell.
    */
    MAP(int numberX, int numberY, double gridSize);
    /**
     * @brief Inserts a point into the map.
     *
     * Updates the grid value based on the given point's coordinates.
     * @param point The Point object to be inserted into the map.
     */
    void insertPoint(const Point& point);
    /**
     * @brief Retrieves the size of each grid cell.
     *
     * @return The size of each grid cell.
     */
    int getGrid(int x, int y) const;
    /**
     * @brief Sets the value of a specific grid cell.
     *
     * @param x The x-coordinate of the grid cell.
     * @param y The y-coordinate of the grid cell.
     * @param value The value to set in the grid cell.
     */
    void setGrid(int x, int y, int value);
    /**
     * @brief Clears the map.
     *
     * Resets all grid values to zero.
     */
    void clearMap();
    /**
    * @brief Prints information about the map.
    *
    * Displays details such as dimensions and grid size.
    */
    void printInfo();
    /**
     * @brief Retrieves the number of grids in the x direction.
     *
     * @return The number of grids in the x direction.
     */
    int getNumberX() const;
    /**
     * @brief Retrieves the number of grids in the y direction.
     *
     * @return The number of grids in the y direction.
     */
    int getNumberY() const;
    /**
	 * @brief Retrieves the size of each grid cell.
	 *
	 * @return The size of each grid cell.
	 */
    double getGridSize() const;
    /*
    * @brief Sets the number of grids in the x direction.
    * 
    */
    void setGridSize(double _gridsize);
};

#endif // MAP_H
