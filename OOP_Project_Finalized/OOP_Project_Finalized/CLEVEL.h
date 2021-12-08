#ifndef _CLEVEL_H_
#define _CLEVEL_H_

#include "CPEOPLE.h"
#include "CANIMALROW.h"
#include "CVEHICLEROW.h"
#include "Console.h"
#include <fstream>

#define FINISH_LINE 1
#define FIRST_LINE 31
#define LAST_LINE 4
#define ROWS_NUMBER 10

class CLEVEL
{
public:
	CLEVEL(unsigned int);
	CLEVEL(std::ifstream&);
	

	~CLEVEL();

	void play(); 

	void change_state(std::string);

	std::string get_state();

	void player_movement(char);

	void save_level(std::ofstream&);

	void draw();

private:
	CPEOPLE player;
	CROW** rows; // const = 10
	std::string state;
	unsigned int level_label;
};

#endif // !_CLEVEL_H_

