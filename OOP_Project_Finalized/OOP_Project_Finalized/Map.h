#ifndef _MAP_H_
#define _MAP_H_

#include <fstream>
#include <string>

#define SCREEN_TOP_BORDER 0
#define SCREEN_BOT_BORDER 40
#define SCREEN_LEFT_BORDER 1
#define SCREEN_RIGHT_BORDER 99

int read_int(std::ifstream&);

std::string read_string(std::ifstream&);

bool read_bool(std::ifstream&);

#endif // !_MAP_H_
