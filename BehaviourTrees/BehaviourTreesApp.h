#pragma once

#include "Application.h"
#include "Renderer2D.h"

class BehaviourTreesApp : public aie::Application {
public:

	BehaviourTreesApp();
	virtual ~BehaviourTreesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	Agent* m_agent;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};