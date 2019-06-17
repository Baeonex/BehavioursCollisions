#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Circle.h"
#include "Plane.h"
#include "MathLib4.h"

class BehavioursApp : public aie::Application {
public:

	BehavioursApp();
	virtual ~BehavioursApp();

	virtual bool startup();
	virtual void shutdown();
	void borderLengths();
	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Circle alpha; //the circle that the beta will follow Flee behaviour
	Circle beta; //seeks the alpha circle Seek behaiour
	//borders of the screen
	Plane borderTop;
	Plane borderBottom;
	Plane borderLeft;
	Plane borderRight;
	int height, width; //width of window

};