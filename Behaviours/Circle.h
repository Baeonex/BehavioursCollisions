#pragma once
#include "MathLib4.h"
#include <float.h>
#include <vector>
#include "SceneObject.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <assert.h>

//class circle, used to create circles that is used in the app to do collisions
class Circle : public SceneObject
{
public:
	Circle();
	//Circle(const Vector2& p, float r), intializes the circle's variables with the parameters
	//input:const Vector2& p, the circles center's position 
	//		float r, the radius of the circle
	Circle(const Vector2& p, float r) : m_center(p), m_radius(r) {}
	//Circle(const char* fileName), loads the a texture of a circle this is used to load the outline cirlce image(used as children)
	//input:const char* fileName, the file path of the texture
	Circle(const char* fileName) { load(fileName); }
	~Circle();
	//bool load(const char* fileName), used by a constructor to actually load the texture 
	//input:const char* fileName, the file path of the texture
	bool load(const char* fileName);
	//
	float min(float a, float b) { return  a < b ? a : b; }
	float max(float a, float b) { return a > b ? a : b; }
	Vector2 min(const Vector2& a, const Vector2& b)
	{
		return { min(a.x,b.x), min(a.y, b.y) };
	}
	Vector2 max(const Vector2& a, const Vector2& b)
	{
		return { max(a.x,b.x), max(a.y, b.y) };
	}
	//void conversionVector(), used to convert the global transform matrix to the centers vector
	void conversionVector()
	{
		m_center.x = m_globalTransform.data[2][0];
		m_center.y = m_globalTransform.data[2][1];
	}
	//void conversionMatrix(), used to convert the the centers vector to the local transformation
	//this is used when the position of a parent has changed 
	void conversionMatrix()
	{
		m_localTransform.data[2][0] = m_center.x;
		m_localTransform.data[2][1] = m_center.y;
		updateTransform();//updates the new position which also updates the children's position
	}
	//void childMoves(Circle& other), when the child object collides with a object make it, it's parent
	//input:Circle& other, the new parent object
	void childMoves(Circle& other);
	//virtual void updateTransform(), an inherited function that is used to update the transfrom matrices
	virtual void updateTransform();
	//virtual void onDraw(aie::Renderer2D* renderer), a inherited function that is used to draw the texture
	virtual void onDraw(aie::Renderer2D* renderer);
	Vector2 m_center; //the position of the center of the circle
	Vector2 m_velocity;//the direction the circle is moveing overtime
	float m_radius;//the radius of the circle
	void fit(const Vector2* points, unsigned int count);
	void fit(const std::vector<Vector2>& points);
	//bool overlaps(Vector2 p), only checks if the point overlaps with this circle
	//input:Vector2 p, the point to be checked
	//output: if the distance from this circles center to point is less than or equal to the radius
	bool overlaps(Vector2 p);
	//bool overlaps(Circle& other), checks if the this circle overlaps with the circle defined in the parameters, this also moves both circles
	//input:Circle& other, the circle which is being tested if it overlaps with this circle
	//output:if the distance from this circles center to the other circles center is less than or equal to both radius's added together
	bool overlaps(Circle& other);
	//void circleMove(Vector2 move, Circle& other), moves both circles with the new vector that was caluclated in the 
	//bool overlaps(Circle& other) function
	//input:Vector2 move, the velocity component which is perpendicular to the tangent vector which is tangent to the point of collision 
	//		Circle& other, the other circle which is also moving
	void circleMove(Vector2 move, Circle& other);
	//Vector2 closestPoint(Vector2 p) const, returns the point which is closest to the parameter vector which is inside the radius
	//input:Vector2 p, the reference point
	//output: a vector2 which is a point inside the circle that is closest to the parameter vector
	Vector2 closestPoint(Vector2 p) const;
protected:
	aie::Texture* m_texture = nullptr; //used to store a texture
};

