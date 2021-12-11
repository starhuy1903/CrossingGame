#include "CLEVEL.h"
#include <Windows.h>

//--------------------> Constructor 

CLEVEL::CLEVEL(std::ifstream& ifs)
{
	this->state = "PAUSE";
	ifs.read(reinterpret_cast<char*>(&this->level_label), sizeof(int));

	// player
	int playerXcoor, playerYcoor;

	ifs.read(reinterpret_cast<char*>(&playerXcoor), sizeof(int));
	ifs.read(reinterpret_cast<char*>(&playerYcoor), sizeof(int));

	this->player.move(playerXcoor, playerYcoor);

	// enemy
	int line = LAST_LINE;
	this->rows = new CROW * [ROWS_NUMBER];

	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		int row_type;

		ifs.read(reinterpret_cast<char*>(&row_type), sizeof(int));

		if (row_type == ROW_TYPE_ANIMAL) this->rows[i] = new CANIMALROW(line, ifs);
		else if (row_type == ROW_TYPE_VEHICLE) this->rows[i] = new CVEHICLEROW(line, ifs);
		
		line += 3;
	}
}

CLEVEL::CLEVEL(unsigned int level_label)
{
	this->state = "PAUSE";
	this->level_label = level_label;

	this->rows = new CROW * [ROWS_NUMBER];

	int line = LAST_LINE;
	int min_distance, max_distance;
	int min_delay, max_delay;
	int min_amount, max_amount;
	

	switch (level_label)
	{
	case 1:case 2:case 3:
	{
		min_distance = 12; max_distance = min_distance + 35 - level_label * 5;
		min_delay = 10; max_delay = min_delay + 24 - level_label * 2;
		min_amount = 3; max_amount = min_amount + 4 + level_label;
		break;
	}
	case 4:case 5:case 6:
	{
		min_distance = 12 - level_label - 3; max_distance = 20;
		min_delay = 10 - level_label - 3; max_delay = 18;
		min_amount = 3 + level_label - 3; max_amount = 8;
		break;
	}

	default:
	{
		min_distance = 7; max_distance = 15;
		min_delay = 3; max_delay = 7;
		min_amount = 7; max_amount = 10;
		break;
	}
	}

	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		bool isAnimal = (rand() % 2 == 0);
		bool isLeft = (rand() % 2 == 0);

		int distance = rand() % max_distance; distance = (distance < min_distance) ? distance + min_distance : distance;
		int delay = rand() % max_delay; delay = (delay < min_delay) ? delay + min_delay : delay;
		int amount = rand() % max_amount; amount = (amount < min_amount) ? amount + min_amount : amount;

		if (isAnimal)
		{
			this->rows[i] = new CANIMALROW(line, isLeft, distance, delay, amount);
		}
		else
		{
			this->rows[i] = new CVEHICLEROW(line, isLeft, distance, delay, amount);
		}

		line += 3;
	}
}

//--------------------> Destructor

CLEVEL::~CLEVEL()
{
	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		delete this->rows[i];
	}
	delete[ROWS_NUMBER] this->rows;
}

//--------------------> Setter

void CLEVEL::change_state(std::string state)
{
	this->state = state;
}

void CLEVEL::player_movement(char move)
{
	if (move == 'W') this->player.go_up();
	if (move == 'S') this->player.go_down();
	if (move == 'A') this->player.go_left();
	if (move == 'D') this->player.go_right();
}

//--------------------> Getter

std::string CLEVEL::get_state()
{
	return this->state;
}

//--------------------> Play

void CLEVEL::play()
{
	this->state = "RUNNING";

	while ((this->state == "RUNNING"))
	{
		Sleep(10);
		
		for (int i = 0; i < ROWS_NUMBER; i++)
		{
			this->rows[i]->one_loop_actions();
		}

		this->player.erase_old();
		this->player.draw();

		// lose condition
		if ((this->player.get_Ycoor() >= LAST_LINE) && (this->player.get_Ycoor() <= FIRST_LINE))
		{
			if (this->rows[(this->player.get_Ycoor() - 1) / 3 - 1]->is_collide(this->player.get_Xcoor(), this->player.get_Ycoor()))
			{
				this->player.set_state(0);
				this->state = "LOSE";
				break;
			}
		}

		//win condition
		if (this->player.get_Ycoor() == FINISH_LINE)
		{
			this->state = "WIN";
			PlaySound(TEXT("./sound/Win.WAV"), NULL, SND_ASYNC);
			break;
		}
	}
}

void CLEVEL::save_level(std::ofstream& ofs)
{
	// level label
	ofs.write(reinterpret_cast<char*>(&this->level_label), sizeof(unsigned int));

	// player
	int playerXcoor = this->player.get_Xcoor();
	int playerYcoor = this->player.get_Ycoor();

	ofs.write(reinterpret_cast<char*>(&playerXcoor), sizeof(int));
	ofs.write(reinterpret_cast<char*>(&playerYcoor), sizeof(int));

	// enemy
	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		int row_type = this->rows[i]->get_type();
		ofs.write(reinterpret_cast<char*>(&row_type), sizeof(int));

		this->rows[i]->save_row(ofs);
	}
}

void CLEVEL::draw()
{
	this->player.draw();
	for (int i = 0; i < ROWS_NUMBER; i++)
	{
		this->rows[i]->draw();
	}
}