#include "CBIRD.h"
#include <Windows.h>

CBIRD::CBIRD(int Xcoor, int Ycoor, bool direction /* 0 for left, 1 for right*/)
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
		this->shape[0][1] = '*';
		this->shape[0][2] = '.';
		this->shape[0][3] = '*';
		this->shape[0][4] = '.';
		this->shape[0][5] = '*';

		// 2nd row
		this->shape[1][0] = '|';
		this->shape[1][1] = ']';
		this->shape[1][2] = 32;
		this->shape[1][3] = '>';
		this->shape[1][4] = 32;
		this->shape[1][5] = '|';
	}
	else
	{
		// 1st row
		this->shape[0][0] = '*';
		this->shape[0][1] = '.';
		this->shape[0][2] = '*';
		this->shape[0][3] = '.';
		this->shape[0][4] = '*';
		this->shape[0][5] = 32;

		// 2nd row
		this->shape[1][0] = '|';
		this->shape[1][1] = 32;
		this->shape[1][2] = '<';
		this->shape[1][3] = 32;
		this->shape[1][4] = '[';
		this->shape[1][5] = '|';
	}

	// 3rd row
	this->shape[2][0] = 32;
	this->shape[2][1] = '^';
	this->shape[2][2] = 32;
	this->shape[2][3] = 32;
	this->shape[2][4] = '^';
	this->shape[2][5] = 32;
}

int CBIRD::get_type()
{
	return ANIMAL_TYPE_BIRD;
}

void CBIRD::sound()
{
	PlaySound(TEXT("./sound/Bird.WAV"), NULL, SND_ASYNC);
}