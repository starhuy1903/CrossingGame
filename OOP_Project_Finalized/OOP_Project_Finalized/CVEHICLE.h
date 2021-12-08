#ifndef _CVEHICLE_H_
#define _CVEHICLE_H_

#include <string>

#define VEHICLE_HEIGHT 3
#define VEHICLE_WIDTH 8
#define VEHICLE_TYPE_CAR 2000
#define VEHICLE_TYPE_TRUCK 2001

class CVEHICLE
{
public:
	~CVEHICLE();

	int get_Xcoor();
	int get_Ycoor();

	void move(int, int);
	virtual void sound() = 0;

	virtual int get_type() = 0;

	bool just_move();	

	void draw();
	void erase_old();

	bool is_out_of_bound();

protected:

	int Xcoor;
	int Ycoor;

	int oldXcoor;
	int oldYcoor;

	char** shape;// 3 * 8
};

#endif // !_CVEHICLE_H_

