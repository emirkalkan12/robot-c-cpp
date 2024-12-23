

#include "SafeNavigation.h"
#include <iostream>
#define SAFE_DISTANCE 0.4
#include <sstream>
#include "Helper.h"








SafeNavigation::SafeNavigation(IRSensor* sensor, RobotControler* ctrl)
    : IR(sensor), controller(ctrl), state(STOP)
{
	// constructor
}


void SafeNavigation::moveForwardSafe()
{
	// will be implemented
}


void SafeNavigation::moveBackwardSafe()
{
	
    // will be implemented
}


