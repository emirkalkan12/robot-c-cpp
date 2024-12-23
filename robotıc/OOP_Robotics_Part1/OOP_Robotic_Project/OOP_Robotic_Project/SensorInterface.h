/**
 * @file SensorInterface.h
 * @author Furkan Gemici
 * @date December, 2024
 * @brief Declaration of the SensorInterface.h class.
 *
 * This class defines an interface for managing sensor interactions,
 * including retrieving sensor types, values, and updating sensor states.
 */
#pragma once
#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>

class SensorInterface
{
protected:
	std::string sensorType;
public:
	SensorInterface(std::string _sensorType) : sensorType(_sensorType) {}
	virtual void updateSensor() = 0;
	std::string getSensorType() { return sensorType; }
	virtual std::string getSensorValue() = 0;
	virtual void print() = 0;
};
#endif