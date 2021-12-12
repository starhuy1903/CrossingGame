#pragma once
#include "CVEHICLE.h"

#include "CCAR.h"
#include "CTRUCK.h"


class VehicleFactory
{
public:
	CVEHICLE* getVehicle(VehicleType type, int XCoor, int YCoor, bool direction) {
		switch (type)
		{
		case VEHICLE_TYPE_CAR:
			return new CCAR(XCoor, YCoor, direction);
		case VEHICLE_TYPE_TRUCK:
			return new CTRUCK(XCoor, YCoor, direction);
		default:
			break;
		}
	}

};

