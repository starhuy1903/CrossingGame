#ifndef _CGAME_H_
#define _CGAME_H_

#include "CLEVEL.h"

class CGAME
{
public:
	CGAME();

	~CGAME();

	void main_loop();

	std::string get_game_state();
	void set_game_state(std::string);

	std::string get_main_state();
	void set_main_state(std::string);

	void update_player(char);

	void main_menu();
	void save_menu();
	void load_menu();
	void lose_menu();
	void win_menu();

private:
	std::string main_state;
	int level_label;
	CLEVEL *current_level;
};

#endif // !_CGAME_H_
