#pragma once

#include <glm\glm.hpp>
#include <list>
#include <Texture.h>
#include <Renderer2D.h>
#include "MathLib4.h"
using aie::Texture;
using glm::vec2;
class Behaviour;
enum Status;
class Agent
{
public:
	Agent(float x, float y);
	~Agent();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* renderer);
	void SetAttack(bool state) { m_bAttack; }
	void SetTarget(Agent* target) { m_target = target; }
protected:
	Behaviour* m_BT;
	Texture* m_texture;
	Texture* m_attackTexture;
	bool m_bAttack;
public:
    Agent* m_target;
	float m_maxSpeed;
	Status m_status;

	Vector2 m_accelleration;
	Vector2 m_velocity;
	Vector2 m_position;
};

