#include "BehavioursApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

BehavioursApp::BehavioursApp() {

}

BehavioursApp::~BehavioursApp() {

}

bool BehavioursApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	borderLengths();
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	alpha.m_center = {600,600};
	beta.m_center = { 400,400 }; 
	alpha.m_velocity = { 100,200 };
	beta.m_velocity = { 100,-200 };
	alpha.m_radius = 20;
	beta.m_radius = 20;
	return true;
}

void BehavioursApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}


void BehavioursApp::borderLengths()
{
	height = aie::Application::getWindowHeight(); // stores the current height of the window
	width = aie::Application::getWindowWidth(); // stores the current width of the window
	//set the positions of the planes to their corresponding side
	borderLeft = { 1,0,0 };
	borderRight = { -1,0, (float)width };
	borderTop = { 0, -1, (float)height };
	borderBottom = { 0, 1, 0 };
}

void BehavioursApp::update(float deltaTime) {

	// input example
	borderLengths();
	alpha.flee(beta.m_center, alpha.m_center, 200, alpha.m_velocity, deltaTime);
	beta.seek(alpha.m_center, beta.m_center, 200, beta.m_velocity, deltaTime);
	beta.overlaps(alpha);
	aie::Input* input = aie::Input::getInstance();
	//this checks if the starter circle collides with any border also makes the circle bounce from the border if it does collide 
	if (borderLeft.testSide(beta) == ePlaneResult::INTERSECTS)
		borderLeft.collRes(beta);
	if (borderRight.testSide(beta) == ePlaneResult::INTERSECTS)
		borderRight.collRes(beta);
	if (borderTop.testSide(beta) == ePlaneResult::INTERSECTS)
		borderTop.collRes(beta);
	if (borderBottom.testSide(beta) == ePlaneResult::INTERSECTS)
		borderBottom.collRes(beta);

	if (borderLeft.testSide(alpha) == ePlaneResult::INTERSECTS)
		borderLeft.collRes(alpha);
	if (borderRight.testSide(alpha) == ePlaneResult::INTERSECTS)
		borderRight.collRes(alpha);
	if (borderTop.testSide(alpha) == ePlaneResult::INTERSECTS)
		borderTop.collRes(alpha);
	if (borderBottom.testSide(alpha) == ePlaneResult::INTERSECTS)
		borderBottom.collRes(alpha);
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BehavioursApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->drawCircle(alpha.m_center.x, alpha.m_center.y, alpha.m_radius);
	m_2dRenderer->drawCircle(beta.m_center.x, beta.m_center.y, beta.m_radius);
	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}