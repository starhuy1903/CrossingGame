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
	game.main_loop();
}


//int main()
//{
//	std::ofstream ofs("save.bin", std::ios::binary);
//
//	CLEVEL a(1);
//
//	a.save_menu(ofs);
//
//
//
//	
//	return 0;
//}

int main()
{
	srand(time(0));
	resizeWindow(1200, 700);

	fixConsoleWindow();

	showConsoleCursor(0);
	

	std::thread t1(mainloop);

	while (1)
	{
		char key = inputKey();
		if (key != -1)
		{
			if (key == 'P')
			{
				if (game.get_game_state() == "RUNNING")
				{
					game.set_game_state("PAUSE");
				}
				else
				{
					game.set_game_state("RUNNING");
				}
			}


			if ((key == 'W') || (key == 'A') || (key == 'S') || (key == 'D'))
			{
				if(game.get_game_state() == "RUNNING") game.update_player(key);
			}
		}
	}


	t1.join();
	return 0;
}