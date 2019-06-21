#pragma once
#include "MathLib4.h"
#include "Circle.h"
//enum ePlaneResult : int, used to check if object of reference is behind, front or intercects with the plane
enum ePlaneResult : int {
	FRONT = 1,
	BACK = -1,
	INTERSECTS = 0
};
//class plane, a plane which is used to create borders in the app
class Plane
{
public:
	Plane();
	//Plane(float x,float y, float d), initializes the planes variables with floats
	//input:float x,float y, floats that initializes the normal of the plane
	//		float d, scalar offset
	Plane(float x,float y, float d) : m_normal(x,y), m_d(d) {}
	//Plane(float x,float y, float d), initializes the planes variables with a vector
	//input:const Vector2& n, a vector that initializes the normal of the plane
	//		float d, scalar offset
	Plane(const Vector2& n, float d) : m_normal(n), m_d(d) {}
	//Plane(Vector2& p1, Vector2& p2), creates a plane using 2 points 
	//input: Vector2& p1, Vector2& p2, thw two points that r used to create the plane
	Plane(Vector2& p1, Vector2& p2);
	//float distanceTo(const Vector2& p), calculates the distance from the planes normal to the parameters point
	//input:const Vector2& p, the reference point to calculate the distance from
	//output:a float value wich is the distance planes normal to the parameters point
	float distanceTo(const Vector2& p);
	//Vector2 closestPoint(Vector2& p), finds the point on the plane which is closest to the parameter point
	//input:Vector2& p, the reference point
	//output:a point on the plane which is closest to the reference point
	Vector2 closestPoint(Vector2 p);
	//ePlaneResult testSide(const Vector2& p), checks the side the point is on in reference to the plane
	//input:const Vector2& p, the point that is being checked what sied it is on 
	//output: the enum ePlaneResult, if it is back behind or intersecting on the plane 
	ePlaneResult testSide(const Vector2& p);
	//void collRes(Circle& circle), does the collision resolution on the parameters circle
	//input:Circle& circle, the circle which is bouncing off the plane
	void collRes(Circle& circle);
	//ePlaneResult testSide(const Vector2& p), checks the side the circle is on in reference to the plane
	//input:const Circle& circle, the circle that is being checked what sied it is on 
	//output:the enum ePlaneResult, if it is back behind or intersecting on the plane 
	ePlaneResult testSide(const Circle& circle);
	~Plane();
	Vector2 m_normal; //the planes normal
	float m_d; //the planes scalar offset

};

