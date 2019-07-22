#include "Selector.h"

Selector::~Selector()
{
	clear();
}

void Selector::onInit()
{
	m_current = m_children.begin();
}

Status Selector::update(Agent* agent, float deltaTime)
{
	while (true)
	{
		Status s = (*m_current)->tick(agent, deltaTime);
		if (s != BH_FAILURE)
			return s;
		if (++m_current == m_children.end())
			return BH_FAILURE;
	}
}
