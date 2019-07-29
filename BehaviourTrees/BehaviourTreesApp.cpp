#include "BehaviourTreesApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Agent.h"
#include <glm\glm.hpp>
#include <list>

BehaviourTreesApp::BehaviourTreesApp() {

}

BehaviourTreesApp::~BehaviourTreesApp() {

}

bool BehaviourTreesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_target = new Agent(200, 400);
	m_target->m_status = BH_ALPHA;
	m_agent = new Agent(200, 200);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void BehaviourTreesApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_agent;
}

void BehaviourTreesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_agent->update(deltaTime);


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BehaviourTreesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_agent->draw(m_2dRenderer);
	m_target->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}