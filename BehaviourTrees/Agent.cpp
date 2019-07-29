#include "Agent.h"
#include <Input.h>
#include "Behaviour.h"
#include "Behaviours.h"


Agent::Agent(float x, float y)
{
	m_maxSpeed = 100;
	m_texture = new Texture("./textures/redOutline.png");
	m_attackTexture = new Texture("./textures/redOutline.png");
	m_status = BH_BETA;
	//behaviour tree construction
	m_BT = (new Selector())->add(new FleeAction())->add(new Sequence())->add(new AttackAction())->add((new Sequence())->add(new StopAttackAction())->add(new SeekAction()));
}


Agent::~Agent()
{
	delete m_texture;
	delete m_attackTexture;

	if (m_BT != nullptr)
		delete m_BT;
}

void Agent::update(float deltaTime)
{
	if (m_BT != nullptr)
		m_BT->tick(this, deltaTime);
	m_velocity.x += m_accelleration.x;
	m_velocity.y += m_accelleration.y;

	if (m_velocity.x > m_maxSpeed)
		m_velocity.x = m_maxSpeed;
	else if (m_velocity.x < -m_maxSpeed)
		m_velocity.x < -m_maxSpeed;
	if (m_velocity.y > m_maxSpeed)
		m_velocity.y = m_maxSpeed;
	else if (m_velocity.y < -m_maxSpeed)
		m_velocity.y < -m_maxSpeed;

	m_accelleration.x = 0;
	m_accelleration.y = 0;

	m_position.x += m_velocity.x * deltaTime;
	m_position.y += m_velocity.y * deltaTime;

}

void Agent::draw(aie::Renderer2D* renderer) {
	if (!m_bAttack)
		renderer->drawSprite(m_texture, m_position.x, m_position.y);
	else
		renderer->drawSprite(m_attackTexture, m_position.x, m_position.y);

}