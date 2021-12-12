#ifndef _CANIMAL_H_
#define _CANIMAL_H_

#include <string>

#define ANIMAL_HEIGHT 3
#define ANIMAL_WIDTH 6

enum AnimalType {
	ANIMAL_TYPE_BIRD = 1000, ANIMAL_TYPE_DINAUSOR = 1001
};

// abstract class, prototype, factory, MVC, singleton
class CANIMAL
{
public:

	~CANIMAL();

	int get_Xcoor();
	int get_Ycoor();

	void move(int, int);
	virtual void sound() = 0;

	virtual AnimalType get_type() = 0;

	bool just_move();

	void draw();
	void erase_old();

	bool is_out_of_bound();

protected:
	//std::string type;

	int Xcoor;
	int Ycoor;

	int oldXcoor;
	int oldYcoor;

	char** shape;// 3 * 6
};

#endif // !_CANIMAL_H_

