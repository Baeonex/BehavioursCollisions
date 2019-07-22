#pragma once

#include <glm\glm.hpp>
#include "Selector.h"
#include "Sequence.h"
#include "Input.h"
#include "Agent.h"

class MouseCloseCondition : public Behaviour
{
public:
	virtual Status update(Agent* agent, float deltaTime)
	{
		Input* in = Input::GetSingleton();
		int x, y;
		in->GetMouseXY(&x, &y);

		glm::vec2 mouse(x, y);
		float distance = glm::length(mouse - agent->m_position);
		if (distance <= 50)
			return BH_SUCCESS;

		return BH_FAILURE;
	}
};

class AttackAction : public Behaviour
{
	virtual Status update(Agent* agent, float deltaTime)
	{
		agent->SetAttack(true);
		return BH_SUCCESS;
	}
};

class StopAttackAction : public Behaviour
{
	virtual Status update(Agent* agent, float deltaTime)
	{
		agent->SetAttack(false);
		return BH_SUCCESS;
	}
};

class SeekAction : public Behaviour
{
	virtual Status update(Agent* agent, float deltaTime)
	{
		Input* in = Input::GetSingleton();
		int x, y;
		in->GetMouseXY(&x, &y);
		glm::vec2 mouse(x, y);

		glm::vec2 direction = mouse - agent->m_position;

		agent->m_acceleration = glm::normalize(direction) * agent->m_maxSpeed * deltaTime;

		return BH_SUCCESS;
	}
};

