#include "Console.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>
#include <thread>

#include "CGAME.h"

CGAME game;

void mainloop()
{
	while (game.get_main_state() != "EXIT")
	{
		if (game.get_main_state() == "MAINMENU") game.main_menu();
		if (game.get_main_state() == "RUNNING") game.gameplay();
		if (game.get_main_state() == "PAUSE") game.pause();
		if (game.get_main_state() == "SAVING") game.save_menu();
		if (game.get_main_state() == "LOADING") game.load_menu();
		if (game.get_main_state() == "LOSE") game.lose_menu();
		if (game.get_main_state() == "WIN") game.win_menu();
		if (game.get_main_state() == "SETTING") game.setting_menu();

	}
}

int main()
{
	srand(time(0));
	resizeWindow(1200, 700);

	setWindowPosition(100, 100);

	fixConsoleWindow();

	showConsoleCursor(0);	

	std::thread t1(mainloop);

	while (1)
	{
		char key = inputKey();
		if (key != -1)
		{
			if (game.get_main_state() == "RUNNING")
			{
				if (key == 'P')
				{
					if (game.get_game_state() == "RUNNING")
					{
						game.set_game_state("PAUSE");
						game.set_main_state("PAUSE");
					}
				}

				if (key == 'T')
				{
					game.set_game_state("PAUSE");
					game.set_pre_state("PAUSE");
					game.set_main_state("LOADING");
				}

				if (key == 'L')
				{
					game.set_game_state("PAUSE");
					game.set_pre_state("PAUSE");
					game.set_main_state("SAVING");
				}

				if ((key == 'W') || (key == 'A') || (key == 'S') || (key == 'D'))
				{
					if (game.get_game_state() == "RUNNING") game.update_player(key);
				}
			}
			else if (game.get_main_state() == "MAINMENU")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "SAVING")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "LOADING")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "WIN")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "LOSE")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "SETTING")
			{
				if ((key == 'W') || (key == 'S') || (key == 13)) game.set_menu_choice(key);
			}

			else if (game.get_main_state() == "PAUSE")
			{
				if (key == 'P')
				{
					game.set_main_state("RUNNING");
					game.set_game_state("RUNNING");
				}

				if (key == 'T')
				{
					game.set_pre_state("PAUSE");
					game.set_main_state("LOADING");
				}

				if (key == 'L')
				{
					game.set_pre_state("PAUSE");
					game.set_main_state("SAVING");
				}		

				if (key == 27)
				{
					game.restart();
					game.set_main_state("MAINMENU");
				}
			}
		}

		if (game.get_main_state() == "EXIT") break;
	}


	t1.join();
	clearScreen();
	return 0;
}