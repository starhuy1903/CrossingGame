#ifndef _CCAR_H_
#define _CCAR_H_

#include "CVEHICLE.h"

class CCAR :public CVEHICLE
{
public:
	CCAR(int, int, bool);

	int get_type();
	void sound();
};

#endif // !_CCAR_H_

