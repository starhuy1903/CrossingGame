#include "Console.h"
#include "CVEHICLEROW.h"
#include <iostream>

//--------------------> Constructor

CVEHICLEROW::CVEHICLEROW(int Ycoor, bool direction, int distance, int delay, int count)
{
	this->Ycoor = Ycoor;
	this->direction = direction;

	this->minDistance = distance + VEHICLE_WIDTH;

	this->delay = delay;
	this->delayCountDown = 1;

	this->enemyNumber = count;
	this->vehicleList = new CVEHICLE* [count];
	this->enemyState = new bool[count];
	for (int i = 0; i < count; i++)
	{
		if (rand() % 2 == 0)
		{
			this->vehicleList[i] = new CTRUCK((direction) ? VEHICLE_LEFT_STARTING_XCOOR : VEHICLE_RIGHT_STARTING_XCOOR, Ycoor, direction);
		}
		else
		{
			this->vehicleList[i] = new CCAR((direction) ? VEHICLE_LEFT_STARTING_XCOOR : VEHICLE_RIGHT_STARTING_XCOOR, Ycoor, direction);
		}
		this->enemyState[i] = 0;
	}

	this->trafficCountDown = 0;
	this->trafficLight = 0;
}

CVEHICLEROW::CVEHICLEROW(int ycoor, std::ifstream& ifs)
{
	this->Ycoor = ycoor;
	
	ifs.read(reinterpret_cast<char*>(&this->direction), sizeof(bool));

	ifs.read(reinterpret_cast<char*>(&this->minDistance), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->delay), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->delayCountDown), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->enemyNumber), sizeof(int));

	this->vehicleList = new CVEHICLE* [this->enemyNumber];
	this->enemyState = new bool[this->enemyNumber];

	for (int i = 0; i < this->enemyNumber; i++)
	{
		int enemy_type;
		ifs.read(reinterpret_cast<char*>(&enemy_type), sizeof(int));

		int enemyXcoor, enemyYcoor;
		ifs.read(reinterpret_cast<char*>(&enemyXcoor), sizeof(int));
		ifs.read(reinterpret_cast<char*>(&enemyYcoor), sizeof(int));

		ifs.read(reinterpret_cast<char*>(&this->enemyState[i]), sizeof(bool));

		if (enemy_type == VEHICLE_TYPE_CAR) this->vehicleList[i] = new CCAR(enemyXcoor, enemyYcoor, this->direction);
		else if (enemy_type == VEHICLE_TYPE_TRUCK) this->vehicleList[i] = new CTRUCK(enemyXcoor, enemyYcoor, this->direction);
	}

	ifs.read(reinterpret_cast<char*>(&this->trafficLight), sizeof(bool));
	ifs.read(reinterpret_cast<char*>(&this->trafficCountDown), sizeof(int));

}

//--------------------> Destructor

CVEHICLEROW::~CVEHICLEROW()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		delete this->vehicleList[i];
	}
	delete[this->enemyNumber] this->vehicleList;

	delete[this->enemyNumber] this->enemyState;
}

//--------------------> Getter

int CVEHICLEROW::get_type()
{
	return ROW_TYPE_VEHICLE;
}

//--------------------> Movement

void CVEHICLEROW::spawn()
{
	if ((this->spawnable()) && (rand() % 5 == 0))
	{
		for (int i = 0; i < this->enemyNumber; i++)
		{
			if (!this->enemyState[i])
			{
				this->enemyState[i] = 1;
				break;
			}
		}
	}
}

void CVEHICLEROW::reset(int index)
{
	if (this->enemyState[index])
	{
		this->enemyState[index] = 0;
		this->vehicleList[index]->move((this->direction) ? VEHICLE_LEFT_STARTING_XCOOR : VEHICLE_RIGHT_STARTING_XCOOR, this->Ycoor);
	}
}

//--------------------> Condition checking

bool CVEHICLEROW::spawnable()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			if (direction)
			{
				if (this->vehicleList[i]->get_Xcoor() - VEHICLE_LEFT_STARTING_XCOOR < this->minDistance) return 0;
			}
			else
			{
				if (VEHICLE_RIGHT_STARTING_XCOOR - this->vehicleList[i]->get_Xcoor() < this->minDistance) return 0;
			}
		}
	}

	return 1;
}

bool CVEHICLEROW::is_collide(int playerXcoor, int playerYcoor)
{
	if (this->Ycoor != playerYcoor) return 0;

	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			if (this->vehicleList[i]->get_Xcoor() > playerXcoor)
			{
				if (playerXcoor + PLAYER_WIDTH >= this->vehicleList[i]->get_Xcoor())
				{
					this->vehicleList[i]->sound();
					return 1;
				}
			}
			else
			{
				if (this->vehicleList[i]->get_Xcoor() + VEHICLE_WIDTH >= playerXcoor)
				{
					this->vehicleList[i]->sound();
					return 1;
				}
			}
		}
	}

	return 0;
}

//--------------------> Perform action

void CVEHICLEROW::one_loop_actions()
{
	if (this->trafficCountDown-- <= 0) this->change_light();

	if (this->delayCountDown != 0)
	{
		this->delayCountDown--;
		return;
	}

	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			// move the object to its next position
			this->vehicleList[i]->move((this->vehicleList[i]->get_Xcoor() + ((this->direction) ? ENEMY_DELTA : -ENEMY_DELTA)), this->Ycoor);

			// erase the old shape of the object at the old position 
			this->vehicleList[i]->erase_old();

			// check and reset an object if it is out of bound
			if ((this->vehicleList[i]->is_out_of_bound()) && (this->vehicleList[i]->just_move())) this->reset(i);

			// draw object at new position
			this->vehicleList[i]->draw();
		}
	}

	this->spawn();

	this->delayCountDown = delay;
}

void CVEHICLEROW::save_row(std::ofstream& ofs)
{
	ofs.write(reinterpret_cast<char*>(&this->direction), sizeof(bool));

	ofs.write(reinterpret_cast<char*>(&this->minDistance), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->delay), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->delayCountDown), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->enemyNumber), sizeof(int));

	for (int i = 0; i < this->enemyNumber; i++)
	{
		int enemy_type = this->vehicleList[i]->get_type();
		ofs.write(reinterpret_cast<char*>(&enemy_type), sizeof(int));

		int enemyXcoor = this->vehicleList[i]->get_Xcoor();
		int enemyYcoor = this->vehicleList[i]->get_Ycoor();

		ofs.write(reinterpret_cast<char*>(&enemyXcoor), sizeof(int));
		ofs.write(reinterpret_cast<char*>(&enemyYcoor), sizeof(int));

		ofs.write(reinterpret_cast<char*>(&this->enemyState[i]), sizeof(bool));
	}

	ofs.write(reinterpret_cast<char*>(&this->trafficLight), sizeof(bool));
	ofs.write(reinterpret_cast<char*>(&this->trafficCountDown), sizeof(int));
}

//--------------------> Traffic light

void CVEHICLEROW::draw_traffic_light(bool is_green)
{
	setColor((is_green) ? COLOR_GREEN : COLOR_RED);

	gotoXY((this->direction) ? SCREEN_RIGHT_BORDER : SCREEN_LEFT_BORDER, this->Ycoor);		std::cout << (char)219;
	gotoXY((this->direction) ? SCREEN_RIGHT_BORDER : SCREEN_LEFT_BORDER, this->Ycoor + 2);	std::cout << (char)219;

	setColor(COLOR_WHITE);
}

void CVEHICLEROW::change_light()
{
	if (this->trafficLight == 0)
	{
		this->trafficLight = 1;
		this->draw_traffic_light(1);
		this->trafficCountDown = MIN_GREEN_LIGHT_TIME;
	}
	else
	{
		if (rand() % 30 == 0)
		{
			this->trafficLight = 0;
			this->draw_traffic_light(0);
			int stop_time = (rand() % MAX_RED_LIGHT_DELAY + MIN_RED_LIGHT_DELAY);
			this->trafficCountDown = (stop_time > MAX_RED_LIGHT_DELAY) ? MAX_RED_LIGHT_DELAY : stop_time;
			this->delayCountDown = this->trafficCountDown;
		}
	}
}

void CVEHICLEROW::draw()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			this->vehicleList[i]->draw();
		}
	}
	this->draw_traffic_light(this->trafficLight);
}