#ifndef _CGAME_H_
#define _CGAME_H_

#include "CLEVEL.h"

#define DEFAULT_BACKGROUND_MUSIC_STATE 1

class CGAME
{
public:
	CGAME();

	~CGAME();

	std::string get_game_state();
	void set_game_state(std::string);

	std::string get_main_state();
	void set_main_state(std::string);

	std::string get_pre_state();
	void set_pre_state(std::string);

	char get_menu_choice();
	void set_menu_choice(int);
	void reset_menu_choice();

	void level_up();
	void restart();

	void update_player(char);

	void gameplay();
	void main_menu();
	void save_menu();
	void load_menu();
	void lose_menu();
	void win_menu();
	void setting_menu();
	void pause();
	//bool yes_no_form(int, int);

	void turn_background_music(int);

private:
	char menu_choice;
	std::string pre_state;

	bool background_music;

	std::string main_state;
	int level_label;
	CLEVEL *current_level;
};

#endif // !_CGAME_H_
