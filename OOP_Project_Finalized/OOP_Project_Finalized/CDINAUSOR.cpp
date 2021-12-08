#include "CDINAUSOR.h"
#include <Windows.h>

//--------------------> Constructor 

CDINAUSOR::CDINAUSOR(int Xcoor, int Ycoor, bool direction /* 0 for left, 1 for right*/)
{
	this->Xcoor = Xcoor;
	this->Ycoor = Ycoor;

	this->oldXcoor = Xcoor;
	this->oldYcoor = Ycoor;

	this->shape = new char* [ANIMAL_HEIGHT];
	for (int i = 0; i < ANIMAL_HEIGHT; i++)
	{
		this->shape[i] = new char[ANIMAL_WIDTH];
	}

	// shape

	if (direction)
	{
		// 1st row
		this->shape[0][0] = 32;
		this->shape[0][1] = 32;
		this->shape[0][2] = 32;
		this->shape[0][3] = 32;
		this->shape[0][4] = 219;
		this->shape[0][5] = 223;

		// 2nd row
		this->shape[1][0] = 223;
		this->shape[1][1] = 254;
		this->shape[1][2] = 219;
		this->shape[1][3] = 219;
		this->shape[1][4] = 219;
		this->shape[1][5] = 221;

		// 3rd row
		this->shape[2][0] = 32;
		this->shape[2][1] = '|';
		this->shape[2][2] = '|';
		this->shape[2][3] = 32;
		this->shape[2][4] = '|';
		this->shape[2][5] = '|';
	}
	else
	{
		// 1st row
		this->shape[0][0] = 223;
		this->shape[0][1] = 219;
		this->shape[0][2] = 32;
		this->shape[0][3] = 32;
		this->shape[0][4] = 32;
		this->shape[0][5] = 32;

		// 2nd row
		this->shape[1][0] = 222;
		this->shape[1][1] = 219;
		this->shape[1][2] = 219;
		this->shape[1][3] = 219;
		this->shape[1][4] = 254;
		this->shape[1][5] = 223;
		
		// 3rd row
		this->shape[2][0] = '|';
		this->shape[2][1] = '|';
		this->shape[2][2] = 32;
		this->shape[2][3] = '|';
		this->shape[2][4] = '|';
		this->shape[2][5] = 32;
	}
}

int CDINAUSOR::get_type()
{
	return ANIMAL_TYPE_DINAUSOR;
}

void CDINAUSOR::sound()
{
	PlaySound(TEXT("./sound/Dino.WAV"), NULL, SND_ASYNC);
}