#include "CGAME.h"

//--------------------> Constructor 

CGAME::CGAME()
{
	this->level_label = 1;
	this->main_state = "MAINMENU";
	this->current_level = new CLEVEL(this->level_label);
}

//--------------------> Destructor

CGAME::~CGAME()
{
	delete this->current_level;
}

//--------------------> Game
void CGAME::main_loop()
{
	this->current_level->play();
}

void CGAME::save_menu()
{
	std::ofstream ofs("");

	this->current_level->save_level(ofs);
}

void CGAME::load_menu()
{
	std::ifstream ifs("");

	if (ifs)
	{

		delete this->current_level;

		this->current_level = new CLEVEL(ifs);

	}
}

//--------------------> Getter

std::string CGAME::get_game_state()
{
	return this->current_level->get_state();
}

std::string CGAME::get_main_state()
{
	return this->main_state;
}

// --------------------> Setter

void CGAME::set_game_state(std::string state)
{
	this->current_level->change_state(state);
}

void CGAME::set_main_state(std::string state)
{
	this->main_state = state;
}

void CGAME::update_player(char move)
{
	this->current_level->player_movement(move);
}

