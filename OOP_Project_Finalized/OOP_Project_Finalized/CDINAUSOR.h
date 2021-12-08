#ifndef _CDINAUSOR_H_
#define _CDINAUSOR_H_

#include "CANIMAL.h"

class CDINAUSOR :public CANIMAL
{
public:
	CDINAUSOR(int, int, bool);

	int get_type();
	void sound();
};

#endif // !_CDINAUSOR_H_

