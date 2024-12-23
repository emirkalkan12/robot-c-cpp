#include "RobotInterface.h"
#include <iostream>

// Pose d�nd�ren fonksiyon
Pose* RobotInterface::getPose() {
    return position; // Mevcut konumu d�nd�r�r
}

// Sens�rleri g�ncelleyen fonksiyon
void RobotInterface::updateSensors() {
    if (sensorList) { // Sensor listesi kontrol edilir
        for (auto sensor : *sensorList) {
            sensor->updateSensor(); // Her sens�r�n updateSensor() metodunu �a��r
        }
    }
}

// Sens�r ekleyen fonksiyon
void RobotInterface::addSensor(SensorInterface* sensor) {
    if (sensor) {
        sensorList->push_back(sensor); // Sens�r� listeye ekle
        std::cout << "Sensor added: " << sensor->getSensorType() << std::endl;
    }
}
