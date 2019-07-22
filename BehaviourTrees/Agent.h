#pragma once

#include <glm\glm.hpp>
#include <list>
#include <Texture.h>
#include <Renderer2D.h>
using aie::Texture;
using glm::vec2;
class Behaviour;
class Agent
{
public:
	Agent(float x, float y);
	~Agent();

	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D renderer);
	void SetAttack(bool state) {m_bAttack}

protected:
	Behaviour* m_BT;
	Texture* m_texture;
	Texture* m_attackTexture;
	bool m_bAttack;
private:
	float m_maxSpeed;
	vec2 m_accelleration;
	vec2 m_velocity;
	vec2 m_position;
};

