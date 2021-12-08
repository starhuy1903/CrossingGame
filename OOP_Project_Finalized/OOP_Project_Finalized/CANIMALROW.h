#ifndef _CANIMALROW_H_
#define _CANIMAL_ROW_H_

#include "CROW.h"
#include "CDINAUSOR.h"
#include "CBIRD.h"

#define ANIMAL_LEFT_STARTING_XCOOR (SCREEN_LEFT_BORDER - ANIMAL_WIDTH)
#define ANIMAL_RIGHT_STARTING_XCOOR (SCREEN_RIGHT_BORDER + 1)

class CANIMALROW: public CROW
{
public:
	CANIMALROW(int, bool, int, int, int);
	CANIMALROW(int, std::ifstream&);

	~CANIMALROW();

	int get_type();

	bool spawnable();

	void spawn();

	void reset(int);

	bool is_collide(int, int);

	void one_loop_actions();

	void save_row(std::ofstream&);

	void draw();

private:
	CANIMAL** animalList;

};

#endif // !_CANIMALROW_H_

