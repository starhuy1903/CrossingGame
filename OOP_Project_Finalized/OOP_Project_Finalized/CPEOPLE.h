#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 3
#define STARTING_XCOOR 51
#define STARTING_YCOOR 37
#define X_AXIS_DELTA 3
#define Y_AXIS_DELTA 3

class CPEOPLE
{
public:
	CPEOPLE();

	~CPEOPLE(){};

	void draw();
	void erase_old();

	void go_up();
	void go_down();
	void go_right();
	void go_left();
	void move(int, int);
	void set_state(bool);

	void update_old_coor();

	int get_Xcoor();
	int get_Ycoor();
	bool get_state();

private:
	int Xcoor;
	int Ycoor;

	int oldXcoor;
	int oldYcoor;

	bool state; // 1 for live, 0 for dead
	bool justMove;

};

#endif // !_CPEOPLE_H_
