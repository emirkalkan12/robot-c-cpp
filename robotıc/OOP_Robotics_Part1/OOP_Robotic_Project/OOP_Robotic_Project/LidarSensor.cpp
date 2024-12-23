


#include "LidarSensor.h"
#include <limits>
#include <stdexcept>
#undef max
#include <iostream>
#include <sstream>





LidarSensor::LidarSensor(FestoRobotAPI* robotAPI) : FestoRobotSensorInterface("Lidar Sensor", robotAPI) {
    if(robotAPI) {
		this->robotAPI = robotAPI;
        this->robotAPI->connect();
	}
	else {
		throw std::runtime_error("robotAPI is not initialized.");
	}
    rangeNumber = robotAPI->getLidarRangeNumber();
    ranges = new double[rangeNumber];
    for (int i = 0; i < rangeNumber; ++i) {
        ranges[i] = 0.0;
    }
}



LidarSensor::~LidarSensor() {
    delete[] ranges;

}


void LidarSensor::update() {
    if (!robotAPI) {
        throw std::runtime_error("robotAPI is not initialized.");
    }

    std::cout << "Updating Lidar Sensor..." << std::endl;
    std::cout << "Range Number: " << rangeNumber << std::endl;

    // Temp array to hold the raw float values from the API
    float* tempRanges = new float[rangeNumber];

    try {
        // Retrieve all range data into the temp array
        robotAPI->getLidarRange(tempRanges);

        for (int i = 0; i < rangeNumber; ++i) {
            if (i < 0 || i >= rangeNumber) {
                throw std::out_of_range("Index out of bounds.");
            }

            // Convert float values to double and store in ranges
            ranges[i] = static_cast<double>(tempRanges[i]);
            std::cout << "Lidar Sensor [" << i << "] = " << ranges[i] << " meters" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error during Lidar update: " << e.what() << std::endl;
    }

    

    // Clean up the allocated memory
    delete[] tempRanges;

    std::cout << "Lidar Sensor update completed." << std::endl;
}



double LidarSensor::getRange(int index) const {
    if (index >= 0 && index < rangeNumber) {
        return ranges[index];
    }
    throw std::out_of_range("Index out of bounds in getRange.");
}


double LidarSensor::getMin(int& index) const {
    double minVal = INFINITY; // En büyük baþlangýç deðeri
    index = -1;

    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] < minVal) {
            minVal = ranges[i];
            index = i;
        }
    }

    return minVal;
}


double LidarSensor::getMax(int& index) const {
    double maxVal = std::numeric_limits<double>::lowest();
    index = -1;
    for (int i = 0; i < rangeNumber; ++i) {
        if (ranges[i] > maxVal) {
            maxVal = ranges[i];
            index = i;
        }
    }
    return maxVal;
}


double LidarSensor::operator[](int i) const {
    return getRange(i);
}


double LidarSensor::getAngle(int i) const {
    if (i >= 0 && i < rangeNumber) {
        std::cout << "Index: " << i << ", RangeNumber: " << rangeNumber
            << ", Angle: " << i * (360.0 / rangeNumber) << std::endl;
        return i * (360.0 / rangeNumber);
    }
    return -1.0;
}

void LidarSensor::updateSensor() {
    update();
}

std::string LidarSensor::getSensorValue() {
    std::ostringstream values;
    for (int i = 0; i < rangeNumber; ++i) {
        values << ranges[i] << " ";
    }
    return values.str();
}

void LidarSensor::print() {
    std::cout << "Lidar Sensor Values: ";
    for (int i = 0; i < rangeNumber; ++i) {
        if (std::isinf(ranges[i])) {
            cout << "LidarSensorValue[" << i << "] = " << ranges[i] << endl;
        }
        else {
            cout << "LidarSensorValue[" << i << "] = " << ranges[i] << " meters" << endl;
        }
    }
    std::cout << std::endl;
}