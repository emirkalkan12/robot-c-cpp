
#include "IRSensor.h"
#include <sstream>
#include <iostream>


IRSensor::IRSensor() : FestoRobotSensorInterface("IR Sensor", robotAPI) {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = 0.0;
    }
}



IRSensor::IRSensor(FestoRobotAPI* robotAPI) : FestoRobotSensorInterface("IR Sensor", robotAPI) {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = 0.0; ///< Initialize all range values to 0.0
    }
}


void IRSensor::update() {
    for (int i = 0; i < 9; ++i) {
        ranges[i] = robotAPI->getIRRange(i); /*!< Retrieve range value for sensor i */
    }
}

double IRSensor::getRange(int index) const {
    if (index >= 0 && index < 9) {
        return this->ranges[index];
    }
    return -1.0; /*!< Return - 1.0 for invalid indices */
}


double IRSensor::operator[](int i) const {
    return getRange(i);
}

void IRSensor::updateSensor() {
    update();
}

std::string IRSensor::getSensorValue() {
    std::ostringstream values;
    for (int i = 0; i < 9; ++i) {
        values << ranges[i] << " ";
    }
    return values.str();
}

void IRSensor::print() {
    std::cout << "IR Sensor Data: ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ranges[i] << " ";
    }
    std::cout << std::endl;
}