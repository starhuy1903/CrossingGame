#ifndef _CTRUCK_H_
#define _CTRUCK_H_

#include "CVEHICLE.h"

class CTRUCK :public CVEHICLE
{
public:
	CTRUCK(int, int, bool);

	int get_type();
	void sound();
};

#endif // !_CTRUCK_H_

