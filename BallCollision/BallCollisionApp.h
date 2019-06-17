#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "MathLib4.h"
#include "Circle.h"
#include <iostream>
#include <vector>
#include "Plane.h"
//class BallCollisionApp class that displays graphics for the program
class BallCollisionApp : public aie::Application {
public:

	BallCollisionApp();
	virtual ~BallCollisionApp();

	virtual bool startup();
	virtual void shutdown();
	//void borderLengths sets up planes that are positioned in the borders of the window
	void borderLengths();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer; // used to draw onto the window
	aie::Font*			m_font; //used to draw text onto the window
	Circle circle; //used for the user to spawn more circles in the desired location
	Circle starterCircle; //the first circle which has a hierarchy of textures on it at the begining of the program
	Circle outline; //the first texture which is childed to the starterCircle
	Circle outline2;//the second texture which is chiled to the starterCircle
	Plane borderLeft;//a plane that is positioned at the left of the window to keep the circles inside the window
	Plane borderRight;//a plane that is positioned at the right of the window to keep the circles inside the window
	Plane borderTop;//a plane that is positioned at the top of the window to keep the circles inside the window
	Plane borderBottom;//a plane that is positioned at the bottom of the window to keep the circles inside the window
	int height; //stores the height of the window at current time
	int width; // stores the width of the window at current time
	std::vector<Circle> balls; // stores the new circles that the user has created
};