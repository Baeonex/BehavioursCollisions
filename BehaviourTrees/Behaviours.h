#pragma once

#include <glm\glm.hpp>
#include "Selector.h"
#include "Sequence.h"
#include "Input.h"
#include "Agent.h"
#include "MathLib4.h"

/*
class MouseCloseCondition : public Behaviour
{
public:
	virtual Status update(Agent* agent, float deltaTime)
	{
		aie::Input* in = aie::Input::GetSingleton();
		int x, y;
		in->GetMouseXY(&x, &y);

		glm::vec2 mouse(x, y);
		float distance = glm::length(mouse - agent->m_position);
		if (distance <= 50)
			return BH_SUCCESS;

		return BH_FAILURE;
	}
};
*/
class FleeAction : public Behaviour
{
	virtual Status update(Agent* agent, float deltaTime)
	{
		if (agent->m_status == BH_ALPHA)
		{
			Vector2 runVector;
			Vector2 force;
			Agent* target = agent->m_target;
			runVector = runVector.normalise(agent->m_position - target->m_position) * agent->m_maxSpeed;
			force = runVector - agent->m_velocity;
			agent->m_velocity = agent->m_velocity + force * deltaTime;
			agent->m_position = agent->m_position + agent->m_velocity * deltaTime;
		}
		else
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
		Vector2 followVector;
		Vector2 force;
		Agent* target = agent->m_target;
		followVector = followVector.normalise(target->m_position - agent->m_position) * agent->m_maxSpeed;
		force = followVector - agent->m_velocity;
		agent->m_velocity = agent->m_velocity + force * deltaTime;
		agent->m_position = agent->m_position + agent->m_velocity * deltaTime;

		return BH_SUCCESS;
	}
};

