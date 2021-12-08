#include "CTRUCK.h"
#include <Windows.h>

// --------------------> Constructor 

CTRUCK::CTRUCK(int Xcoor, int Ycoor, bool direction /* 0 for left, 1 for right*/)
{
	this->Xcoor = Xcoor;
	this->Ycoor = Ycoor;

	this->oldXcoor = Xcoor;
	this->oldYcoor = Ycoor;

	this->shape = new char* [VEHICLE_HEIGHT];
	for (int i = 0; i < VEHICLE_HEIGHT; i++)
	{
		this->shape[i] = new char[VEHICLE_WIDTH];
	}

	// shape
	// 1st row
	this->shape[0][0] = 218;
	this->shape[0][1] = 196;
	this->shape[0][2] = 196;
	this->shape[0][3] = 196;
	this->shape[0][4] = 196;
	this->shape[0][5] = 196;
	this->shape[0][6] = 196;
	this->shape[0][7] = 191;

	// 3rd row
	this->shape[2][0] = 192;
	this->shape[2][1] = 'O';
	this->shape[2][2] = 196;
	this->shape[2][3] = 196;
	this->shape[2][4] = 196;
	this->shape[2][5] = 196;
	this->shape[2][6] = 'O';
	this->shape[2][7] = 217;

	if (direction)
	{
		// 2nd row
		this->shape[1][0] = 179;
		this->shape[1][1] = 32;
		this->shape[1][2] = 32;
		this->shape[1][3] = 32;
		this->shape[1][4] = 32;
		this->shape[1][5] = 32;
		this->shape[1][6] = '[';
		this->shape[1][7] = 179;
	}
	else
	{
		// 2nd row
		this->shape[1][0] = 179;
		this->shape[1][1] = ']';
		this->shape[1][2] = 32;
		this->shape[1][3] = 32;
		this->shape[1][4] = 32;
		this->shape[1][5] = 32;
		this->shape[1][6] = 32;
		this->shape[1][7] = 179;
	}
}

int CTRUCK::get_type()
{
	return VEHICLE_TYPE_TRUCK;
}

void CTRUCK::sound()
{
	PlaySound(TEXT("./sound/TRUCK.WAV"), NULL, SND_ASYNC);
}