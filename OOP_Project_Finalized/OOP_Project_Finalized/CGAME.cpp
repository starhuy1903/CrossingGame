#include "CGAME.h"
#include <iostream>
#include <Windows.h>

//--------------------> Constructor 

CGAME::CGAME()
{
	this->level_label = 1;
	this->main_state = "MAINMENU";
	this->current_level = new CLEVEL(this->level_label);
	this->menu_choice = '\0';
	this->pre_state = "MAINMENU";
	this->background_music = DEFAULT_BACKGROUND_MUSIC_STATE;
}

//--------------------> Destructor

CGAME::~CGAME()
{
	delete this->current_level;
}

//--------------------> Game
void CGAME::gameplay()
{
	clearScreen();
	draw_outline();
	draw_game_guide(this->level_label);

	if(this->background_music) this->turn_background_music(2);

	this->current_level->draw();
	this->current_level->play();
	if (this->current_level->get_state() == "WIN")
	{
		this->level_up();
		this->main_state = "WIN";
	}
	if (this->current_level->get_state() == "LOSE")
	{
		this->restart();
		this->main_state = "LOSE";
	}

}

void CGAME::main_menu()
{
	clearScreen();
	draw_outline();

	if (this->background_music) this->turn_background_music(1);

	int temp = 1;
	std::string text[4] = { "New game","Load game","Setting","Exit", };

	int choice = 0;

	while (this->main_state == "MAINMENU")
	{
		setColor(temp);
		draw_banner_1(10, 10);
		setColor(COLOR_WHITE);
		if (temp == 8) temp = 1;
		else temp++;

		for (int i = 0; i < 4; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(20, 23 + i); std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(20, 23 + i); std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 0) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 3) choice++;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				switch (choice)
				{
				case 0:
					this->main_state = "RUNNING";
					break;
				case 1:
					this->pre_state = "MAINMENU";
					this->main_state = "LOADING";
					break;
				case 2:
					this->main_state = "SETTING";
					break;
				case 3:
					this->main_state = "EXIT";
					break;
				}
			}
		}
	}
}

void CGAME::save_menu()
{
	clearScreen();
	draw_outline();
	this->turn_background_music(0);
	std::string text[12] = {"Select slot to save:","Save_slot_1","Save_slot_2" ,"Save_slot_3" ,"Save_slot_4" ,"Save_slot_5" ,"Save_slot_6" ,"Save_slot_7" ,"Save_slot_8" ,"Save_slot_9" ,"Save_slot_10" ,"Return"};

	int choice = 1;

	draw_banner_2(10, 10);

	while (this->main_state == "SAVING")
	{
		for (int i = 0; i < 12; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(20, 16 + i); std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(20, 16 + i); std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 1) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 11) choice++;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				if (choice == 11)
				{
					clearScreen();
					this->main_state = this->pre_state;
				}
				else
				{
					std::ofstream ofs("./save/" + text[choice] + ".bin", std::ios::binary);
					this->current_level->save_level(ofs);
					gotoXY(60, 16 + choice); std::cout << "Saved!";
				}
			}
		}

	}
}

void CGAME::load_menu()
{
	clearScreen();
	draw_outline();
	this->turn_background_music(0);
	std::string text[12] = { "Select slot to load:","Save_slot_1","Save_slot_2" ,"Save_slot_3" ,"Save_slot_4" ,"Save_slot_5" ,"Save_slot_6" ,"Save_slot_7" ,"Save_slot_8" ,"Save_slot_9" ,"Save_slot_10" ,"Return" };

	int choice = 1;

	draw_banner_3(10, 10);

	while (this->main_state == "LOADING")
	{
		for (int i = 0; i < 12; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(20, 16 + i); std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(20, 16 + i); std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 1) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 11) choice++;
				this->reset_menu_choice();
			}

			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				if (choice == 11)
				{
					clearScreen();
					this->main_state = this->pre_state;
				}
				else
				{
					std::ifstream ifs("./save/" + text[choice] + ".bin", std::ios::binary);
					if (ifs)
					{
						ifs.seekg(0, std::ios::end);
						if (ifs.tellg() == 0)
						{
							gotoXY(60, 16 + choice); std::cout << "Error!";
						}
						else
						{
							ifs.seekg(0, std::ios::beg);
							delete this->current_level;
							this->current_level = new CLEVEL(ifs);
							clearScreen();
							this->main_state = "PAUSE";
						}
					}
					else
					{
						gotoXY(60, 16 + choice); std::cout << "Error!";
					}
				}
			}

		}
	}
}

void CGAME::win_menu()
{
	clearScreen();
	draw_outline();
	std::string text[5] = { "Continue", "Save game", "Load game", "Main menu", "Exit" };

	int choice = 0;

	draw_banner_4(10, 10);

	while (this->main_state == "WIN")
	{
		for (int i = 0; i < 5; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(20, 23 + i); std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(20, 23 + i); std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 0) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 4) choice++;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				switch (choice)
				{
				case 0:
					this->main_state = "RUNNING";
					break;
				case 1:
					this->pre_state = "WIN";
					this->main_state = "SAVING";
					break;
				case 2:
					this->pre_state = "WIN";
					this->main_state = "LOADING";
					break;
				case 3:
					this->restart();
					this->main_state = "MAINMENU";
					break;
				case 4:
					this->main_state = "EXIT";
					break;
				}
			}
		}
	}
}

void CGAME::lose_menu()
{
	clearScreen();
	draw_outline();
	std::string text[4] = { "New game", "Load game", "Main menu", "Exit" };

	int choice = 0;

	draw_banner_5(2, 2);

	while (this->main_state == "LOSE")
	{
		for (int i = 0; i < 4; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(102, 32 + i); std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(102, 32 + i); std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 0) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 3) choice++;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				switch (choice)
				{
				case 0:
					this->main_state = "RUNNING";
					break;
				case 1:
					this->pre_state = "LOSE";
					this->main_state = "LOADING";
					break;
				case 2:
					this->restart();
					this->main_state = "MAINMENU";
					break;
				case 3:
					this->main_state = "EXIT";
					break;
				}
			}
		}
	}
}

void CGAME::setting_menu()
{
	clearScreen();
	draw_outline();
	std::string text[4] = { "Setting", "Background music: ON", "Return", "Background music: OFF"};

	int choice = 1;
	static bool state[1] = { DEFAULT_BACKGROUND_MUSIC_STATE };

	while (this->main_state == "SETTING")
	{
		for (int i = 0; i < 3; i++)
		{
			if (choice == i)
			{
				setColor(COLOR_RED);
				gotoXY(20, 23 + i);
				if (i == 1)
				{
					if (state[i - 1] == 1)std::cout << text[i];
					else std::cout << text[i + 2];
				}
				else std::cout << text[i];
				setColor(COLOR_WHITE);
			}
			else
			{
				gotoXY(20, 23 + i); 
				if (i == 1)
				{
					if (state[i - 1] == 1)std::cout << text[i];
					else std::cout << text[i + 2];
				}
				else std::cout << text[i];
			}
		}

		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'W')
			{
				if (choice > 1) choice--;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 'S')
			{
				if (choice < 2) choice++;
				this->reset_menu_choice();
			}
			if (this->menu_choice == 13)
			{
				this->reset_menu_choice();
				switch (choice)
				{
				case 1:
					state[0] = (state[0]) ? 0 : 1;
					this->background_music = state[0];
					if (!this->background_music) this->turn_background_music(0);
					break;
				case 2:
					this->main_state = "MAINMENU";
					break;
				}
			}
		}
	}
}

void CGAME::pause()
{
	this->turn_background_music(0);
	draw_game_guide(this->level_label);
	this->current_level->draw();
	gotoXY(105, 30); std::cout << "Pausing...";
	gotoXY(105, 31); std::cout << "[ ESC ]: exit to menu";

	while (this->main_state == "PAUSE")
	{

	}
}
 
void CGAME::level_up()
{
	delete this->current_level;

	this->level_label++;

	this->current_level = new CLEVEL(this->level_label);
}

void CGAME::restart()
{
	delete this->current_level;

	this->level_label = 1;

	this->current_level = new CLEVEL(this->level_label);
}

/*bool CGAME::yes_no_form(int Xcoor, int Ycoor)
{
	int choice = 1;
	while (1)
	{
		if (choice == 1)
		{
			setColor(COLOR_RED);
			gotoXY(Xcoor, Ycoor); std::cout << "Yes";
			setColor(COLOR_WHITE);
			gotoXY(Xcoor + 5, Ycoor); std::cout << "No";
		}
		else if (choice == 0)
		{
			gotoXY(Xcoor, Ycoor); std::cout << "Yes";
			setColor(COLOR_RED);
			gotoXY(Xcoor + 5, Ycoor); std::cout << "No";
			setColor(COLOR_WHITE);
		}
		
		if (this->menu_choice != '\0')
		{
			if (this->menu_choice == 'A')
			{
				reset_menu_choice();
				if (choice == 0) choice = 1;
			}
			if (this->menu_choice == 'D')
			{
				reset_menu_choice();
				if (choice == 1) choice = 0;
			}

			if (this->menu_choice == 10)
			{
				reset_menu_choice();
				return choice;
			}
		}
	}
	return 1;
}*/

void CGAME::turn_background_music(int index)
{
	if(index == 1)
		PlaySound(TEXT("./sound/Background1.WAV"), NULL, SND_LOOP | SND_ASYNC);
	else if(index == 2)
		PlaySound(TEXT("./sound/Background2.WAV"), NULL, SND_LOOP | SND_ASYNC);
	else
		PlaySound(NULL, 0, 0);
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

char CGAME::get_menu_choice()
{
	return this->menu_choice;
}

std::string CGAME::get_pre_state()
{
	return this->pre_state;
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

void CGAME::set_menu_choice(int choice)
{
	this->menu_choice = choice;
}

void CGAME::reset_menu_choice()
{
	this->menu_choice = '\0';
}

void CGAME::set_pre_state(std::string state)
{
	this->pre_state = state;
}

void CGAME::update_player(char move)
{
	this->current_level->player_movement(move);
}

