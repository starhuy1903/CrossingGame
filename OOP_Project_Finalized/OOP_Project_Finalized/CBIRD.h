#ifndef _CBIRD_H_
#define _CBIRD_H_

#include "CANIMAL.h"

class CBIRD : public CANIMAL
{
public:
	CBIRD(int, int, bool);

	int get_type();
	void sound();
};

#endif // !_CBIRD_H_

