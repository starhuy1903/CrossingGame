#include "CPEOPLE.h"
#include "Console.h"
#include "Map.h"
#include <iostream>

// --------------------> Constructor
CPEOPLE::CPEOPLE()
{
	this->Xcoor = STARTING_XCOOR;
	this->Ycoor = STARTING_YCOOR;
	this->oldXcoor = STARTING_XCOOR;
	this->oldYcoor = STARTING_YCOOR;
	this->state = 1;
	this->justMove = 1;
}

// --------------------> Getter

int CPEOPLE::get_Xcoor()
{
	return this->Xcoor;
}

int CPEOPLE::get_Ycoor()
{
	return this->Ycoor;
}

bool CPEOPLE::get_state()
{
	return this->state;
}

// --------------------> Setter

void CPEOPLE::set_state(bool state)
{
	this->state = state;
}

// --------------------> Draw object
void CPEOPLE::draw()
{
	//if (this->justMove)
	{
		gotoXY(this->Xcoor, this->Ycoor);		std::cout << "  O  ";
		gotoXY(this->Xcoor, this->Ycoor + 1);	std::cout << "/(_)\\";
		gotoXY(this->Xcoor, this->Ycoor + 2);	std::cout << " / \\ ";
		this->justMove = 0;
	}
	
}

void CPEOPLE::erase_old()
{
	if (this->justMove)
	{
		gotoXY(this->oldXcoor, this->oldYcoor);		std::cout << "     ";
		gotoXY(this->oldXcoor, this->oldYcoor + 1);	std::cout << "     ";
		gotoXY(this->oldXcoor, this->oldYcoor + 2);	std::cout << "     ";
	}
}

// --------------------> Movement

void CPEOPLE::move(int Xcoor, int Ycoor)
{
	this->Xcoor = Xcoor;
	this->Ycoor = Ycoor;
}

void CPEOPLE::go_up()
{
	this->update_old_coor();
	if (this->Ycoor - Y_AXIS_DELTA < SCREEN_TOP_BORDER + 1) this->Ycoor = SCREEN_TOP_BORDER + 1;
	else this->Ycoor -= Y_AXIS_DELTA;
	this->justMove = 1;
}

void CPEOPLE::go_down()
{
	this->update_old_coor();
	if (this->Ycoor + Y_AXIS_DELTA + PLAYER_HEIGHT > SCREEN_BOT_BORDER) this->Ycoor = SCREEN_BOT_BORDER - PLAYER_HEIGHT;
	else this->Ycoor += Y_AXIS_DELTA;
	this->justMove = 1;
}

void CPEOPLE::go_left()
{
	this->update_old_coor();
	if (this->Xcoor - X_AXIS_DELTA < SCREEN_LEFT_BORDER + 1) this->Xcoor = SCREEN_LEFT_BORDER + 1;
	else this->Xcoor -= X_AXIS_DELTA;
	this->justMove = 1;
}

void CPEOPLE::go_right()
{
	this->update_old_coor();
	if (this->Xcoor + X_AXIS_DELTA + PLAYER_WIDTH > SCREEN_RIGHT_BORDER) this->Xcoor = SCREEN_RIGHT_BORDER - PLAYER_WIDTH;
	else this->Xcoor += X_AXIS_DELTA;
	this->justMove = 1;
}

void CPEOPLE::update_old_coor()
{
	this->oldXcoor = this->Xcoor;
	this->oldYcoor = this->Ycoor;
}

