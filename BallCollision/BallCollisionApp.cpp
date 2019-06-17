#include "BallCollisionApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
BallCollisionApp::BallCollisionApp() {

}

BallCollisionApp::~BallCollisionApp() {

}
#define exeTest
bool BallCollisionApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	//intialisations of variables (radius, textures, positions, size, hierarchies)
	balls.reserve(100);
	circle.setPosition(200, 200);
	circle.m_radius = 20;
	outline.m_radius = 25;
	outline2.m_radius = 35;
	starterCircle.m_radius = 20;
#ifdef exeTest
	outline.load("redOutline.png");
	outline2.load("redOutline.png");
#else
	outline.load("./textures/redOutline.png");
	outline2.load("./textures/redOutline.png");
#endif
	outline.setScale(0.025, 0.025); 
	outline2.setScale(1.35, 1.35);											// circle //
	starterCircle.addChild(&outline); //outline childed to starter circle	//outline //
	outline.addChild(&outline2); //outline2 childed to outline				//outline2//
	starterCircle.setPosition(600, 400);//									
	borderLengths();
	starterCircle.m_velocity.x = 10;
	starterCircle.m_velocity.y = -10;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void BallCollisionApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void BallCollisionApp::borderLengths()
{
	height = aie::Application::getWindowHeight(); // stores the current height of the window
	width = aie::Application::getWindowWidth(); // stores the current width of the window
	//set the positions of the planes to their corresponding side
	borderLeft = { 1,0,0 }; 
	borderRight = { -1,0, (float)width };
	borderTop = { 0, -1, (float)height };
	borderBottom = { 0, 1, 0 };
}

void BallCollisionApp::update(float deltaTime) {
 
	borderLengths(); // resize the borders if the window has changed dimensions
	aie::Input* input = aie::Input::getInstance();
	//move the starter circle
	starterCircle.m_center.y += starterCircle.m_velocity.y * deltaTime;
	starterCircle.m_center.x += starterCircle.m_velocity.x * deltaTime;
	starterCircle.conversionMatrix(); //converts the current position of the circle's center to a matrix
	////////////////////////////////////so that the children of the object are able to follow
	
	//this checks if the starter circle collides with any border also makes the circle bounce from the border if it does collide 
	if (borderLeft.testSide(starterCircle) == ePlaneResult::INTERSECTS)
		borderLeft.collRes(starterCircle);
	if (borderRight.testSide(starterCircle) == ePlaneResult::INTERSECTS)
		borderRight.collRes(starterCircle);
	if (borderTop.testSide(starterCircle) == ePlaneResult::INTERSECTS)
		borderTop.collRes(starterCircle);
	if (borderBottom.testSide(starterCircle) == ePlaneResult::INTERSECTS)
		borderBottom.collRes(starterCircle);

	//checks if the circles that the user has created has collided with anything
	//this also does the collision resolution if they have collided
	for (int i = 0, j = balls.size(); i < balls.size(); ++i, --j)
	{
		//moves every circle in the container
		balls[i].m_center.y += balls[i].m_velocity.y * deltaTime; 
		balls[i].m_center.x += balls[i].m_velocity.x * deltaTime;
		balls[i].conversionMatrix(); //converts the center vector to a matrix so that the children is also following
		//collision checks
		balls[i].overlaps(starterCircle); 
		outline.overlaps(balls[i]);

		if (outline2.overlaps(balls[i]))
			outline2.setScale(0.035, 0.035);
		
		//collsion checks against the borders
		if (borderLeft.testSide(balls[i]) == ePlaneResult::INTERSECTS)
			borderLeft.collRes(balls[i]);
		if (borderRight.testSide(balls[i]) == ePlaneResult::INTERSECTS)
			borderRight.collRes(balls[i]);
		if (borderTop.testSide(balls[i]) == ePlaneResult::INTERSECTS)
			borderTop.collRes(balls[i]);
		if (borderBottom.testSide(balls[i]) == ePlaneResult::INTERSECTS)
			borderBottom.collRes(balls[i]);
	}
	//checks if the circles inside the container have collided with each other
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls.size() != 1)
		{
			for (int j = i + 1; j < balls.size(); ++j)
			{
				balls[i].overlaps(balls[j]);
			}
		}
	}

	//lets the user create circles where ever they want
	if (input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT))
	{	
		//store the mouse x,y position
		float mouseX = (float)input->getMouseX();
		float mouseY = (float)input->getMouseY();
		circle.setPosition(mouseX, mouseY); //set circle spawn to mouse position
		circle.m_velocity.x = (float)(rand() % 400 - 200);
		circle.m_velocity.y = (float)(rand() % 400 - 200);
		balls.push_back(circle);
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}



void BallCollisionApp::draw() {


	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	//draws all user generated circles
	for (int i = 0; i < balls.size(); ++i)
	{
		balls[i].draw(m_2dRenderer);//draws Circle with all its children
	}
	starterCircle.draw(m_2dRenderer); //draws starterCircle with all its children 

	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "M1 TO CREATE CIRCLES AT MOUSE POSITION", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}