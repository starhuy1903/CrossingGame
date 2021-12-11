#include "Map.h"
#include "Console.h"
#include <iostream>

void draw_banner_1(int Xcoor, int Ycoor)
{
	gotoXY(Xcoor, Ycoor);		 std::cout << "        ___________________ ________    _________ _________.___ _______    ________  ";
	gotoXY(Xcoor, Ycoor + 1);	 std::cout << "        \\_   ___ \\______   \\\\_____  \\  /   _____//   _____/|   |\\      \\  /  _____/  ";
	gotoXY(Xcoor, Ycoor + 2);	 std::cout << "        /    \\  \\/|       _/ /   |   \\ \\_____  \\ \\_____  \\ |   |/   |   \\/   \\  ___  ";
	gotoXY(Xcoor, Ycoor + 3);	 std::cout << "        \\     \\___|    |   \\/    |    \\/        \\/        \\|   /    |    \\    \\_\\  \\ ";
	gotoXY(Xcoor, Ycoor + 4);	 std::cout << "         \\______  /____|_  /\\_______  /_______  /_______  /|___\\____|__  /\\______  / ";
	gotoXY(Xcoor, Ycoor + 5);	 std::cout << "                \\/       \\/         \\/        \\/        \\/             \\/        \\/  ";
	gotoXY(Xcoor, Ycoor + 6);	 std::cout << "                    __________ ________      _____  ________                         ";
	gotoXY(Xcoor, Ycoor + 7);	 std::cout << "                    \\______   \\\\_____  \\    /  _  \\ \\______ \\                        ";
	gotoXY(Xcoor, Ycoor + 8);	 std::cout << "                     |       _/ /   |   \\  /  /_\\  \\ |    |  \\                       ";
	gotoXY(Xcoor, Ycoor + 9);	 std::cout << "                     |    |   \\/    |    \\/    |    \\|    `   \\                      ";
	gotoXY(Xcoor, Ycoor + 10);	 std::cout << "                     |____|_  /\\_______  /\\____|__  /_______  /                      ";
	gotoXY(Xcoor, Ycoor + 11);	 std::cout << "                            \\/         \\/         \\/        \\/                       ";

}

void draw_banner_2(int Xcoor, int Ycoor)
{
	gotoXY(Xcoor, Ycoor);		 std::cout << "                   _______ _   ______  ________   __  _______           ";
	gotoXY(Xcoor, Ycoor + 1);	 std::cout << "                  / __/ _ | | / / __/ / ___/ _ | /  |/  / __/           ";
	gotoXY(Xcoor, Ycoor + 2);	 std::cout << "                 _\\ \\/ __ | |/ / _/  / (_ / __ |/ /|_/ / _/             ";
	gotoXY(Xcoor, Ycoor + 3);	 std::cout << " ____________   /___/_/ |_|___/___/  \\___/_/ |_/_/  /_/___/ ____________";
	gotoXY(Xcoor, Ycoor + 4);	 std::cout << "/___/___/___/                                              /___/___/___/";

}

void draw_banner_3(int Xcoor, int Ycoor)
{
	gotoXY(Xcoor, Ycoor);		 std::cout << "                   __   ____  ___   ___    ________   __  _______           ";
	gotoXY(Xcoor, Ycoor + 1);	 std::cout << "                  / /  / __ \\/ _ | / _ \\  / ___/ _ | /  |/  / __/           ";
	gotoXY(Xcoor, Ycoor + 2);	 std::cout << "                 / /__/ /_/ / __ |/ // / / (_ / __ |/ /|_/ / _/             ";
	gotoXY(Xcoor, Ycoor + 3);	 std::cout << " ____________   /____/\\____/_/ |_/____/  \\___/_/ |_/_/  /_/___/ ____________";
	gotoXY(Xcoor, Ycoor + 4);	 std::cout << "/___/___/___/                                                  /___/___/___/";
	
}

void draw_banner_4(int Xcoor, int Ycoor)
{
	gotoXY(Xcoor, Ycoor);		 std::cout << ".____     _______________   _______________.____                    ";
	gotoXY(Xcoor, Ycoor + 1);	 std::cout << "|    |    \\_   _____/\\   \\ /   /\\_   _____/|    |                   ";
	gotoXY(Xcoor, Ycoor + 2);	 std::cout << "|    |     |    __)_  \\   Y   /  |    __)_ |    |                   ";
	gotoXY(Xcoor, Ycoor + 3);	 std::cout << "|    |___  |        \\  \\     /   |        \\|    |___                ";
	gotoXY(Xcoor, Ycoor + 4);	 std::cout << "|_______ \\/_______  /   \\___/   /_______  /|_______ \\               ";
	gotoXY(Xcoor, Ycoor + 5);	 std::cout << "        \\/        \\/                    \\/         \\/               ";
	gotoXY(Xcoor, Ycoor + 6);	 std::cout << "      __________  _____    _________ ____________________________   ";
	gotoXY(Xcoor, Ycoor + 7);	 std::cout << "      \\______   \\/  _  \\  /   _____//   _____/\\_   _____/\\______ \\  ";
	gotoXY(Xcoor, Ycoor + 8);	 std::cout << "       |     ___/  /_\\  \\ \\_____  \\ \\_____  \\  |    __)_  |    |  \\ ";
	gotoXY(Xcoor, Ycoor + 9);	 std::cout << "       |    |  /    |    \\/        \\/        \\ |        \\ |    `   \\";
	gotoXY(Xcoor, Ycoor + 10);	 std::cout << "       |____|  \\____|__  /_______  /_______  //_______  //_______  /";
	gotoXY(Xcoor, Ycoor + 11);	 std::cout << "                       \\/        \\/        \\/         \\/         \\/ ";

}

void draw_banner_5(int Xcoor, int Ycoor)
{
	gotoXY(Xcoor, Ycoor);		 std::cout << "                                                                                        ,---,  ";
	gotoXY(Xcoor, Ycoor + 1);	 std::cout << "                                                          ,--,                       ,`--.' |  ";
	gotoXY(Xcoor, Ycoor + 2);	 std::cout << "     ,----..  ,-.----.      ,---,       .--.--.         ,--.'|    ,---,.    ,---,    |   :  :  ";
	gotoXY(Xcoor, Ycoor + 3);	 std::cout << "    /   /   \\ \\    /  \\    '  .' \\     /  /    '.    ,--,  | :  ,'  .' |  .'  .' `\\  '   '  ;  ";
	gotoXY(Xcoor, Ycoor + 4);	 std::cout << "   |   :     :;   :    \\  /  ;    '.  |  :  /`. / ,---.'|  : ',---.'   |,---.'     \\ |   |  |  ";
	gotoXY(Xcoor, Ycoor + 5);	 std::cout << "   .   |  ;. /|   | .\\ : :  :       \\ ;  |  |--`  |   | : _' ||   |   .'|   |  .`\\  |'   :  ;  ";
	gotoXY(Xcoor, Ycoor + 6);	 std::cout << "   .   ; /--` .   : |: | :  |   /\\   \\|  :  ;_    :   : |.'  |:   :  |-,:   : |  '  ||   |  '  ";
	gotoXY(Xcoor, Ycoor + 7);	 std::cout << "   ;   | ;    |   |  \\ : |  :  ' ;.   :\\  \\    `. |   ' '  ; ::   |  ;/||   ' '  ;  :'   :  |  ";
	gotoXY(Xcoor, Ycoor + 8);	 std::cout << "   |   : |    |   : .  / |  |  ;/  \\   \\`----.   \\'   |  .'. ||   :   .''   | ;  .  |;   |  ;  ";
	gotoXY(Xcoor, Ycoor + 9);	 std::cout << "   .   | '___ ;   | |  \\ '  :  | \\  \\ ,'__ \\  \\  ||   | :  | '|   |  |-,|   | :  |  '`---'. |  ";
	gotoXY(Xcoor, Ycoor + 10);	 std::cout << "   '   ; : .'||   | ;\\  \\|  |  '  '--' /  /`--'  /'   : |  : ;'   :  ;/|'   : | /  ;  `--..`;  ";
	gotoXY(Xcoor, Ycoor + 11);	 std::cout << "   |   :    / :   : :-'  |  | ,'        `--'---'  ;   : ;--'  |   :   .';   :  .'    |    |`.  ";
	gotoXY(Xcoor, Ycoor + 12);	 std::cout << "    \\   \\ .'  |   |.'    `--''                    |   ,/      |   | ,'  |   ,.'      `-- -`, ; ";
	gotoXY(Xcoor, Ycoor + 13);	 std::cout << "     `---`    `---'                               '---'       `----'    '---'          '---`\"  ";
	
	gotoXY(Xcoor, Ycoor + 17);	 std::cout << "                                    `-------`                                                  ";
	gotoXY(Xcoor, Ycoor + 18);	 std::cout << "                               ....--:-.......-:-.....`                                        ";
	gotoXY(Xcoor, Ycoor + 19);	 std::cout << "                             -:----:-------------:-...--`                                      ";
	gotoXY(Xcoor, Ycoor + 20);	 std::cout << "                          `-::-------------------------:/-.                                 ";
	gotoXY(Xcoor, Ycoor + 21);	 std::cout << "                         ./-/:--------------------------+-/-`                             ";
	gotoXY(Xcoor, Ycoor + 22);	 std::cout << "                       /--/::------///+:---/o+::------:/::-/       ";
	gotoXY(Xcoor, Ycoor + 23);	 std::cout << "                        /:-:----:::/:/o/.:--:-+/:/:::----:-:/                               ";
	gotoXY(Xcoor, Ycoor + 24);	 std::cout << "                        `.-::/::/:---:/:-:.:::+:---:/::/::-.`                            ";
	gotoXY(Xcoor, Ycoor + 25);	 std::cout << "                              ```-:::/:o///++s:/:---.``             ";
	gotoXY(Xcoor, Ycoor + 26);	 std::cout << "                                       -osoos+                      ";
	gotoXY(Xcoor, Ycoor + 27);	 std::cout << "                                       `syo+s.                      ";
	gotoXY(Xcoor, Ycoor + 28);	 std::cout << "                                   `...-//::+---.`                  ";
	gotoXY(Xcoor, Ycoor + 29);	 std::cout << "                                   :/::/+/:/o/:://`                 ";
	gotoXY(Xcoor, Ycoor + 30);	 std::cout << "                                    `.../ooo+...`                   ";
	gotoXY(Xcoor, Ycoor + 31);	 std::cout << "                                        -o/o/                       ";
	gotoXY(Xcoor, Ycoor + 32);	 std::cout << "                             ``````----:::::/::::-```````           ";
	gotoXY(Xcoor, Ycoor + 33);	 std::cout << "                         ``-::://-/:::::-----::--:+::+::::``        ";
	gotoXY(Xcoor, Ycoor + 34);	 std::cout << "                    ```-:+/+:--------:------------------:/+::-```   ";
	gotoXY(Xcoor, Ycoor + 35);	 std::cout << "                  `.-::---------------------------------------:---.`";

}

void draw_outline()
{
	gotoXY(0, 0);	std::cout << (char)201;
	gotoXY(142, 0);	std::cout << (char)187;
	gotoXY(0, 40);	std::cout << (char)200;
	gotoXY(142, 40); std::cout << (char)188;
	gotoXY(100, 0);	std::cout << (char)203;
	gotoXY(100, 40); std::cout << (char)202;
	for (int i = 1; i < 100; i++)
	{
		gotoXY(i, 0);	std::cout << (char)205;
		gotoXY(i, 40);	std::cout << (char)205;
	}
	for (int i = 101; i < 142; i++)
	{
		gotoXY(i, 0);	std::cout << (char)205;
		gotoXY(i, 40);	std::cout << (char)205;
	}

	for (int i = 1; i < 40; i++)
	{
		gotoXY(0, i);	std::cout << (char)186;
		gotoXY(100, i);	std::cout << (char)186;
		gotoXY(142, i);	std::cout << (char)186;
	}
}

void draw_game_guide(int level)
{
	gotoXY(105, 1); std::cout << "<<<< Crossing Road Game >>>>";
	gotoXY(105, 3); std::cout << "Lv. " << level << std::endl;
	gotoXY(105, 5); std::cout << "CONTROL" << std::endl;
	gotoXY(105, 6); std::cout << "[ W ]: UP" << std::endl;
	gotoXY(105, 7); std::cout << "[ S ]: DOWN" << std::endl;
	gotoXY(105, 8); std::cout << "[ A ]: LEFT" << std::endl;
	gotoXY(105, 9); std::cout << "[ D ]: RIGHT" << std::endl;
	gotoXY(105, 11); std::cout << "COMMANDS" << std::endl;
	gotoXY(105, 12); std::cout << "[ L ]: Save game" << std::endl;
	gotoXY(105, 13); std::cout << "[ T ]: Load game" << std::endl;
	gotoXY(105, 14); std::cout << "[ P ]: Pause game/Unpause" << std::endl;
}