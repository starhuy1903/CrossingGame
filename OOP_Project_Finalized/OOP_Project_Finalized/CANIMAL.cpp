#include "CANIMAL.h"
#include "Map.h"
#include "Console.h"
#include <iostream>

// --------------------> Destructor

CANIMAL::~CANIMAL()
{
	for (int i = 0; i < ANIMAL_HEIGHT; i++)
	{
		delete[ANIMAL_WIDTH] this->shape[i];
	}
	delete[ANIMAL_HEIGHT] this->shape;
}

// --------------------> Getter

int CANIMAL::get_Xcoor()
{
	return this->Xcoor;
}

int CANIMAL::get_Ycoor()
{
	return this->Ycoor;
}

// --------------------> Movement

bool CANIMAL::just_move()
{
	return ((this->oldXcoor != this->Xcoor) || (this->oldYcoor != this->Ycoor));
}

void CANIMAL::move(int Xcoor, int Ycoor)
{
	this->oldXcoor = this->Xcoor;
	this->oldYcoor = this->Ycoor;
	this->Xcoor = Xcoor;
	this->Ycoor = Ycoor;
}

// --------------------> Draw object

void CANIMAL::draw()
{
	if (this->is_out_of_bound()) return;

	if (this->Xcoor <= SCREEN_LEFT_BORDER)
	{
		int first_cell_in_bound = SCREEN_LEFT_BORDER - this->Xcoor + 1;

		int new_Xcoor_to_draw = this->Xcoor + first_cell_in_bound;

		gotoXY(new_Xcoor_to_draw, this->Ycoor);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << this->shape[0][i];
		}
		gotoXY(new_Xcoor_to_draw, this->Ycoor + 1);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << this->shape[1][i];
		}
		gotoXY(new_Xcoor_to_draw, this->Ycoor + 2);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << this->shape[2][i];
		}

		return;
	}

	if (this->Xcoor + ANIMAL_WIDTH - 1 >= SCREEN_RIGHT_BORDER)
	{
		int last_cell_in_bound = SCREEN_RIGHT_BORDER - this->Xcoor - 1;

		gotoXY(this->Xcoor, this->Ycoor);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << this->shape[0][i];
		}
		gotoXY(this->Xcoor, this->Ycoor + 1);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << this->shape[1][i];
		}
		gotoXY(this->Xcoor, this->Ycoor + 2);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << this->shape[2][i];
		}

		return;
	}

	gotoXY(this->Xcoor, this->Ycoor);
	for (int i = 0; i < ANIMAL_WIDTH; i++)
	{
		std::cout << this->shape[0][i];
	}
	gotoXY(this->Xcoor, this->Ycoor + 1);
	for (int i = 0; i < ANIMAL_WIDTH; i++)
	{
		std::cout << this->shape[1][i];
	}
	gotoXY(this->Xcoor, this->Ycoor + 2);
	for (int i = 0; i < ANIMAL_WIDTH; i++)
	{
		std::cout << this->shape[2][i];
	}
}

void CANIMAL::erase_old()
{
	if (this->oldXcoor <= SCREEN_LEFT_BORDER)
	{
		int first_cell_in_bound = SCREEN_LEFT_BORDER - this->oldXcoor + 1;

		int new_Xcoor_to_draw = this->oldXcoor + first_cell_in_bound;

		gotoXY(new_Xcoor_to_draw, this->oldYcoor);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << " ";
		}
		gotoXY(new_Xcoor_to_draw, this->oldYcoor + 1);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << " ";
		}
		gotoXY(new_Xcoor_to_draw, this->oldYcoor + 2);
		for (int i = first_cell_in_bound; i < ANIMAL_WIDTH; i++)
		{
			std::cout << " ";
		}
		return;
	}

	if (this->oldXcoor + ANIMAL_WIDTH - 1 >= SCREEN_RIGHT_BORDER)
	{
		int last_cell_in_bound = SCREEN_RIGHT_BORDER - this->oldXcoor - 1;

		gotoXY(this->oldXcoor, this->oldYcoor);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << " ";
		}
		gotoXY(this->oldXcoor, this->oldYcoor + 1);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << " ";
		}
		gotoXY(this->oldXcoor, this->oldYcoor + 2);
		for (int i = 0; i <= last_cell_in_bound; i++)
		{
			std::cout << " ";
		}
		return;
	}

	gotoXY(this->oldXcoor, this->oldYcoor);
	for (int i = 0; i <= ANIMAL_WIDTH; i++)
	{
		std::cout << " ";
	}
	gotoXY(this->oldXcoor, this->oldYcoor + 1);
	for (int i = 0; i <= ANIMAL_WIDTH; i++)
	{
		std::cout << " ";
	}
	gotoXY(this->oldXcoor, this->oldYcoor + 2);
	for (int i = 0; i <= ANIMAL_WIDTH; i++)
	{
		std::cout << " ";
	}
}

// --------------------> Condition checking

bool CANIMAL::is_out_of_bound()
{
	if (this->Xcoor >= SCREEN_RIGHT_BORDER) return 1;
	if (this->Xcoor + ANIMAL_WIDTH <= SCREEN_LEFT_BORDER) return 1;
	return 0;
}



