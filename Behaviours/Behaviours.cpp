#include "Behaviours.h"



Behaviours::Behaviours()
{
}


Behaviours::~Behaviours()
{
}

Vector2 Behaviours::seek(Vector2 target, Vector2& agent, float maxVelocity, Vector2& currentVelocity, float deltaTime)
{
	Vector2 followVector;
	Vector2 force;
	followVector = followVector.normalise(target - agent) * maxVelocity;
	force = followVector - currentVelocity;
	currentVelocity = currentVelocity + force * deltaTime;
	agent = agent + currentVelocity * deltaTime;
	return force;

}


Vector2 Behaviours::flee(Vector2 target, Vector2& agent, float maxVelocity, Vector2& currentVelocity, float deltaTime)
{
	Vector2 runVector;
	Vector2 force;
	runVector = runVector.normalise(agent - target) * maxVelocity;
	force = runVector - currentVelocity;
	currentVelocity = currentVelocity + force * deltaTime;
	agent = agent + currentVelocity * deltaTime;
	return force;
}