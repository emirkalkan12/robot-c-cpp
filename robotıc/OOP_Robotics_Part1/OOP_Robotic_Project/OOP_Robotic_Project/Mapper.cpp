#include "Mapper.h"
#include <cmath>
#include <iostream>
#include <fstream>


#define M_PI 3.14159265358979323846


static double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}


Mapper::Mapper(MAP* map, RobotControler* robotControler, LidarSensor* lidarSensor) {
    this->map = map;
    this->robotControler = robotControler;
    this->lidarSensor = lidarSensor;
}


void Mapper::updateMap() {
    if (!map || !robotControler || !lidarSensor) {
        std::cerr << "Error: Mapper components are not initialized!" << std::endl;
        return;
    }

    std::cout << "Updating Map with Lidar Data..." << std::endl;

    Pose robotPose = robotControler->getPose();
    int mapCenterX = map->getNumberX() / 2;
    int mapCenterY = map->getNumberY() / 2;

    int robotGridX = mapCenterX + static_cast<int>(robotPose.getX() / map->getGridSize());
    int robotGridY = mapCenterY + static_cast<int>(robotPose.getY() / map->getGridSize());

    lidarSensor->update();

    for (int i = 0; i < lidarSensor->getRangeNumber(); ++i) {
        double distance = lidarSensor->getRange(i);
        double angle = lidarSensor->getAngle(i);

        if (distance <= 0.0 || std::isinf(distance)) {
            continue;
        }

        int gridX = robotGridX + static_cast<int>((distance * std::cos(degreesToRadians(angle))) / map->getGridSize());
        int gridY = robotGridY + static_cast<int>((distance * std::sin(degreesToRadians(angle))) / map->getGridSize());

        if (gridX >= 0 && gridX < map->getNumberX() && gridY >= 0 && gridY < map->getNumberY()) {
            map->setGrid(gridX, gridY, 1);
        }
    }
}


bool Mapper::recordMap() {
    if (!map) {
        std::cerr << "Error: Map is not initialized!" << std::endl;
        return false;
    }

    std::ofstream outFile("map.txt");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open map.txt" << std::endl;
        return false;
    }

    for (int y = 0; y < map->getNumberY(); ++y) {
        for (int x = 0; x < map->getNumberX(); ++x) {
            outFile << (map->getGrid(x, y) ? 'x' : '.') << ' ';
        }
        outFile << '\n';
    }

    outFile.close();
    std::cout << "Map saved to map.txt" << std::endl;
    return true;
}


void Mapper::showMap() {
    if (!map) {
        std::cerr << "Error: Map is not initialized!" << std::endl;
        return;
    }

    for (int y = 0; y < map->getNumberY(); ++y) {
        for (int x = 0; x < map->getNumberX(); ++x) {
            std::cout << (map->getGrid(x, y) ? 'x' : '.') << ' ';
        }
        std::cout << std::endl;
    }
}
