#include "Sequence.h"


Sequence::~Sequence()
{
	clear()
}

void Sequence::onInit()
{
	m_current = m_children.begin();
}

Status Sequence::update(Agent* agent, float deltaTIme)
{
	while (true)
	{
		Status s = (*m_current)->tick(agent, deltaTIme);

		if (s != BH_SUCCESS)
			return s;
		if (++m_current == m_children.end())
			return BH_SUCCESS;
	}
}

