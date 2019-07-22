#pragma once
#include "Composite.h"

class Selector : public Composite
{
protected:
	virtual ~Selector();
	virtual void onInit();
	virtual Status update(Agent* agent, float deltaTIme);

	Behaviours::iterator m_current;

};

