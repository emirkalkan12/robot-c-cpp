#include "RobotInterface.h"
#include <iostream>

// Pose döndüren fonksiyon
Pose* RobotInterface::getPose() {
    return position; // Mevcut konumu döndürür
}

// Sensörleri güncelleyen fonksiyon
void RobotInterface::updateSensors() {
    if (sensorList) { // Sensor listesi kontrol edilir
        for (auto sensor : *sensorList) {
            sensor->updateSensor(); // Her sensörün updateSensor() metodunu çaðýr
        }
    }
}

// Sensör ekleyen fonksiyon
void RobotInterface::addSensor(SensorInterface* sensor) {
    if (sensor) {
        sensorList->push_back(sensor); // Sensörü listeye ekle
        std::cout << "Sensor added: " << sensor->getSensorType() << std::endl;
    }
}
