#include "MotionMenu.h"
#include "SafeNavigation.h"
#include <thread>   // Sleep için
#include <chrono>   // Sleep için

#include <sstream>
#define SAFE_DISTANCE 0.4
#include <map>
const double MIN_DISTANCE = 0.3;
const int MOVE_DURATION = 300;  // Hareket adýmý süresi (ms)
const double WARNING_DISTANCE = 0.4; // Yavaþlama mesafesi

void MotionMenu::printChoice()
{
	cout << choice << endl;
}

std::vector<double> convertToDoubles(const std::string& sensorValues) {
	std::vector<double> doubles;
	std::istringstream stream(sensorValues);
	std::string value;

	while (stream >> value) {
		try {
			doubles.push_back(std::stod(value)); // String'i double'a çevirir
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Geçersiz bir deðer bulundu: " << value << std::endl;
		}
	}
	return doubles;
}

/**
 * @brief Runs the motion menu and performs corresponding robot motions.
 *
 * This function displays the motion menu and allows the user to choose various
 * robot motion options such as moving forward, backward, turning left or right,
 * printing the controller status, and returning to the main menu or exiting the program.
 *
 * @return Returns true to continue executing the main menu, false to exit the program.
 */
bool MotionMenu::run() {
	cout << "Motion Menu" << endl;
	bool motion = true;

	while (motion)
	{
		printChoice();

		int pick2;
		cin >> pick2;

		switch (pick2)
		{
			case 1:
				if (robot->robotControler)
				{
					robot->robotControler->moveForward();
					cout << "Robot moving forward." << endl;
					Sleep(1000);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 2:
				if (robot->robotControler)
				{
					int ms = 0;

					bool collision = false;

					while (!collision) { // 10 saniye boyunca kontrol et
						// IR sensörünü al ve doðru þekilde cast et
						SensorInterface* irsensor = robot->robotControler->getSensor("IR Sensor");
						IRSensor* ir = dynamic_cast<IRSensor*>(irsensor);

						if (ir == nullptr) {
							std::cerr << "IR Sensor could not be retrieved or cast correctly." << std::endl;
							break;
						}

						// Sensör verilerini al
						std::string sensorVals = ir->getSensorValue();
						std::vector<double> distances = convertToDoubles(sensorVals);

						if (distances.size() < 8) {
							std::cerr << "Incomplete sensor data received!" << std::endl;
							continue;
						}

						// Sensör verilerini analiz et
						double frontLeft = distances[0];
						double frontCenter = distances[1];
						double frontRight = distances[2];
						double backLeft = distances[6];
						double backCenter = distances[7];
						double backRight = distances[5];

						std::cout << "Front Distances: Left=" << frontLeft
							<< ", Center=" << frontCenter
							<< ", Right=" << frontRight << std::endl;
						std::cout << "Back Distances: Left=" << backLeft
							<< ", Center=" << backCenter
							<< ", Right=" << backRight << std::endl;

						// Ön ve arka engelleri kontrol et
						bool frontObstacle = frontLeft < MIN_DISTANCE || frontCenter < MIN_DISTANCE || frontRight < MIN_DISTANCE;
						bool backObstacle = backLeft < MIN_DISTANCE || backCenter < MIN_DISTANCE || backRight < MIN_DISTANCE;

						if (frontObstacle && backObstacle) {
							std::cout << "Obstacles detected on both sides! Stopping robot." << std::endl;
							robot->robotControler->stop();
							collision = true;
							break; // Döngüyü sonlandýr
						}
						else if (frontObstacle) {
							std::cout << "Obstacle detected in front! Moving backward." << std::endl;
							collision = true;
							robot->robotControler->moveBackward();
						}
						else if (backObstacle) {
							std::cout << "Obstacle detected at the back! Moving forward." << std::endl;
							collision = true;
							robot->robotControler->moveForward();
						}
						else {
							std::cout << "No obstacles detected. Moving forward..." << std::endl;
							robot->robotControler->moveForward();
						}

						// Hareket esnasýnda 100 ms bekle
						std::this_thread::sleep_for(std::chrono::milliseconds(50));
						robot->robotControler->stop();

					}

					std::cout << "Operation completed or stopped due to collision possibility." << std::endl;

				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 3:
				if (robot->robotControler)
				{
					robot->robotControler->turnLeft();
					cout << "Robot turning left." << endl;
					Sleep(500);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 4:
				if (robot->robotControler)
				{
					robot->robotControler->turnRight();
					cout << "Robot turning right." << endl;
					Sleep(500);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 5:
				if (robot->robotControler)
				{
					robot->robotControler->moveBackward();
					cout << "Robot moving backward..." << endl;
					Sleep(1000);
					robot->robotControler->stop();
					cout << "Robot stopped." << endl << endl;
				}
				else
				{
					cout << connectionErr << endl << endl;
				}
				break;
			case 6:
				if (robot->robotControler)
				{
					robot->robotControler->print();
				}
				else
				{
					cout << connectionErr;
				}
				break;
			case 7:
				motion = false;
				cout << "Back to main menu..." << endl << endl;
				break;
			case 8:
				motion = false;
				cout << "Exit..." << endl;
				return false;
				break;
			default:
				cout << "Please enter a valid number!" << endl << endl;
				break;
		}
		return true;
	}
}

