#include "CANIMALROW.h"

//--------------------> Constructor

CANIMALROW::CANIMALROW(int Ycoor, bool direction, int distance, int delay, int count)
{
	this->Ycoor = Ycoor;
	this->direction = direction;

	this->minDistance = distance + ANIMAL_WIDTH;
	
	this->delay = delay;
	this->delayCountDown = 1;

	this->enemyNumber = count;
	this->animalList = new CANIMAL * [count];
	this->enemyState = new bool[count];
	for (int i = 0; i < count; i++)
	{
		if (rand() % 2 == 0)
		{
			this->animalList[i] = new CDINAUSOR((direction)? ANIMAL_LEFT_STARTING_XCOOR:ANIMAL_RIGHT_STARTING_XCOOR,Ycoor,direction);
		}
		else
		{
			this->animalList[i] = new CBIRD((direction) ? ANIMAL_LEFT_STARTING_XCOOR : ANIMAL_RIGHT_STARTING_XCOOR, Ycoor, direction);
		}
		this->enemyState[i] = 0;

	}
}

CANIMALROW::CANIMALROW(int ycoor, std::ifstream& ifs)
{
	this->Ycoor = ycoor;

	ifs.read(reinterpret_cast<char*>(&this->direction), sizeof(bool));

	ifs.read(reinterpret_cast<char*>(&this->minDistance), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->delay), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->delayCountDown), sizeof(int));

	ifs.read(reinterpret_cast<char*>(&this->enemyNumber), sizeof(int));

	this->animalList = new CANIMAL*[this->enemyNumber];
	this->enemyState = new bool[this->enemyNumber];

	for (int i = 0; i < this->enemyNumber; i++)
	{
		int enemy_type;
		ifs.read(reinterpret_cast<char*>(&enemy_type), sizeof(int));
		
		int enemyXcoor, enemyYcoor;
		ifs.read(reinterpret_cast<char*>(&enemyXcoor), sizeof(int));
		ifs.read(reinterpret_cast<char*>(&enemyYcoor), sizeof(int));

		ifs.read(reinterpret_cast<char*>(&this->enemyState[i]), sizeof(bool));

		if (enemy_type == ANIMAL_TYPE_BIRD) this->animalList[i] = new CBIRD(enemyXcoor, enemyYcoor, this->direction);
		else if (enemy_type == ANIMAL_TYPE_DINAUSOR) this->animalList[i] = new CDINAUSOR(enemyXcoor, enemyYcoor, this->direction);

	}
}

//--------------------> Destructor

CANIMALROW::~CANIMALROW()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		delete this->animalList[i];
	}
	delete[this->enemyNumber] this->animalList;
	delete[this->enemyNumber] this->enemyState;
}

//--------------------> Getter

int CANIMALROW::get_type()
{
	return ROW_TYPE_ANIMAL;
}

//--------------------> Movement

void CANIMALROW::spawn()
{
	if((this->spawnable()) && (rand() % 5 == 0))
	//if(this->spawnable())
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

void CANIMALROW::reset(int index)
{
	if (this->enemyState[index])
	{
		this->enemyState[index] = 0;
		this->animalList[index]->move((this->direction) ? ANIMAL_LEFT_STARTING_XCOOR : ANIMAL_RIGHT_STARTING_XCOOR, this->Ycoor);
	}
}

//--------------------> Condition checking

bool CANIMALROW::spawnable()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			if (direction)
			{
				if (this->animalList[i]->get_Xcoor() - ANIMAL_LEFT_STARTING_XCOOR < this->minDistance) return 0;
			}
			else
			{
				if (ANIMAL_RIGHT_STARTING_XCOOR - this->animalList[i]->get_Xcoor() < this->minDistance) return 0;
			}
		}
	}

	return 1;
}

bool CANIMALROW::is_collide(int playerXcoor, int playerYcoor)
{
	if (this->Ycoor != playerYcoor) return 0;

	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			if (this->animalList[i]->get_Xcoor() > playerXcoor)
			{
				if (playerXcoor + PLAYER_WIDTH >= this->animalList[i]->get_Xcoor())
				{
					this->animalList[i]->sound();
					return 1;
				}
			}
			else
			{
				if (this->animalList[i]->get_Xcoor() + ANIMAL_WIDTH >= playerXcoor)
				{
					this->animalList[i]->sound();
					return 1;
				}
			}
		}
	}

	return 0;
}

//--------------------> Perform action

void CANIMALROW::one_loop_actions()
{
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
			this->animalList[i]->move((this->animalList[i]->get_Xcoor() + ((this->direction) ? ENEMY_DELTA : -ENEMY_DELTA)), this->Ycoor);
		
			// erase the old shape of the object at the old position 
			this->animalList[i]->erase_old();

			// check and reset an object if it is out of bound
			if ((this->animalList[i]->is_out_of_bound()) && (this->animalList[i]->just_move())) this->reset(i);

			// draw object at new position
			this->animalList[i]->draw();
		}
	}

	this->spawn();

	this->delayCountDown = delay;
}

void CANIMALROW::save_row(std::ofstream& ofs)
{
	ofs.write(reinterpret_cast<char*>(&this->direction), sizeof(bool));

	ofs.write(reinterpret_cast<char*>(&this->minDistance), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->delay), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->delayCountDown), sizeof(int));

	ofs.write(reinterpret_cast<char*>(&this->enemyNumber), sizeof(int));

	for (int i = 0; i < this->enemyNumber; i++)
	{
		int enemy_type = this->animalList[i]->get_type();
		ofs.write(reinterpret_cast<char*>(&enemy_type), sizeof(int));

		int enemyXcoor = this->animalList[i]->get_Xcoor();
		int enemyYcoor = this->animalList[i]->get_Ycoor();

		ofs.write(reinterpret_cast<char*>(&enemyXcoor), sizeof(int));
		ofs.write(reinterpret_cast<char*>(&enemyYcoor), sizeof(int));

		ofs.write(reinterpret_cast<char*>(&this->enemyState[i]), sizeof(bool));
	}
}

void CANIMALROW::draw()
{
	for (int i = 0; i < this->enemyNumber; i++)
	{
		if (this->enemyState[i])
		{
			this->animalList[i]->draw();
		}
	}
}