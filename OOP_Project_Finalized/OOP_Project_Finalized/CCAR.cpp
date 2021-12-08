#include "CCAR.h"
#include <Windows.h>

// --------------------> Constructor 

CCAR::CCAR(int Xcoor, int Ycoor, bool direction /* 0 for left, 1 for right*/)
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
	this->shape[0][0] = 32;
	this->shape[0][1] = '_';
	this->shape[0][2] = '_';
	this->shape[0][3] = '_';
	this->shape[0][4] = '_';
	this->shape[0][5] = '_';
	this->shape[0][6] = '_';
	this->shape[0][7] = 32;
	// 2nd row
	this->shape[1][0] = '/';
	this->shape[1][1] = 32;
	this->shape[1][2] = 32;
	this->shape[1][3] = 32;
	this->shape[1][4] = 32;
	this->shape[1][5] = 32;
	this->shape[1][6] = 32;
	this->shape[1][7] = '\\';
	
	if (direction)
	{
		// 3rd row
		this->shape[2][0] = 240;
		this->shape[2][1] = 'O';
		this->shape[2][2] = '-';
		this->shape[2][3] = '-';
		this->shape[2][4] = '-';
		this->shape[2][5] = 'O';
		this->shape[2][6] = '-';
		this->shape[2][7] = 217;
	}
	else
	{
		// 3rd row
		this->shape[2][0] = 217;
		this->shape[2][1] = '-';
		this->shape[2][2] = 'O';
		this->shape[2][3] = '-';
		this->shape[2][4] = '-';
		this->shape[2][5] = '-';
		this->shape[2][6] = 'O';
		this->shape[2][7] = 240;
	}
}

int CCAR::get_type()
{
	return VEHICLE_TYPE_CAR;
}

void CCAR::sound()
{
	PlaySound(TEXT("./sound/Car.WAV"), NULL, SND_ASYNC);
}