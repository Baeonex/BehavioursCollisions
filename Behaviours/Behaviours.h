#pragma once
#include "MathLib4.h"
class Behaviours 
{
public:
	Behaviours();
	virtual ~Behaviours();

	Vector2 seek(Vector2 target, Vector2& agent, float maxVelocity, Vector2& currentVelocity, float deltaTime);
	Vector2 flee(Vector2 target, Vector2& agent, float maxVelocity, Vector2& currentVelocity, float deltaTime);
	void pursue(Vector2 targetPos, Vector2 targetVel, Vector2 agentPos, Vector2 agentVel, float maxVel, float deltaTime);

};

