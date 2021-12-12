#pragma once

class GameData
{
private:
	static GameData instance;
	GameData();

public:
	static GameData getInstance();

	void openFile();
};

