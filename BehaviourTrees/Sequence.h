#pragma once
#include "Composite.h"
class Sequence : public Composite
{
public:
	~Sequence();
	virtual void onInit();
	virtual Status update(Agent* agent, float deltaTime);

	Behaviours::iterator m_current;
};

