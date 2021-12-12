#pragma once
#include "CANIMAL.h"

#include "CBIRD.h"
#include "CDINAUSOR.h"

// Apply Factory Pattern
class AnimalFactory
{

public:
	CANIMAL* getAnimal(AnimalType type, int XCoor, int YCoor, bool direction) {
		switch (type)
		{
		case ANIMAL_TYPE_BIRD:
			return new CBIRD(XCoor, YCoor, direction);

		case ANIMAL_TYPE_DINAUSOR:
			return new CDINAUSOR(XCoor, YCoor, direction);

		default:
			break;
		}
	}			
};

