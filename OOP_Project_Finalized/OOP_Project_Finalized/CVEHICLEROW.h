#ifndef _CVEHICLEROW_H_
#define _CVEHICLEROW_H_

#include "CROW.h"
#include "CCAR.h"
#include "CTRUCK.h"

#define VEHICLE_LEFT_STARTING_XCOOR (SCREEN_LEFT_BORDER - VEHICLE_WIDTH)
#define VEHICLE_RIGHT_STARTING_XCOOR (SCREEN_RIGHT_BORDER + 1)
#define MAX_RED_LIGHT_DELAY 150
#define MIN_RED_LIGHT_DELAY 50
#define MIN_GREEN_LIGHT_TIME 200

class CVEHICLEROW :public CROW
{
public:
	CVEHICLEROW(int, bool, int, int, int);
	CVEHICLEROW(int, std::ifstream&);

	~CVEHICLEROW();

	int get_type();

	bool spawnable();

	void spawn();

	void reset(int);

	bool is_collide(int, int);

	void one_loop_actions();

	void draw_traffic_light(bool);
	void change_light();

	void save_row(std::ofstream&);

	void draw();

private:
	CVEHICLE** vehicleList;

	int trafficCountDown;
	bool trafficLight; // 1 for green, 0 for red

};

#endif // !_CVEHICLEROW_H_

