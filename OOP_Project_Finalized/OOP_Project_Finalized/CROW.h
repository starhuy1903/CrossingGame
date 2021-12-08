#ifndef _CROW_H_
#define _CROW_H_

#include "CPEOPLE.h"
#include "Map.h"
#include <random>
#include <fstream>

#define ENEMY_DELTA 3
#define ROW_TYPE_ANIMAL 100
#define ROW_TYPE_VEHICLE 200

class CROW
{
public:
	// dummy
	virtual bool spawnable() = 0;

	virtual void spawn() = 0;

	virtual void reset(int) = 0;

	virtual bool is_collide(int, int) = 0;

	virtual void one_loop_actions() = 0;

	virtual int get_type() = 0;

	virtual void save_row(std::ofstream&) = 0;

	virtual void draw() = 0;

	
protected:
	int Ycoor;
	bool direction; //0 for left, 1 for right

	int minDistance;

	int delay;
	int delayCountDown;

	int enemyNumber;
	bool* enemyState; // 1 for living, 0 for not 
};

#endif // !_CROW_H_

