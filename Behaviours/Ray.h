#pragma once
#include "MathLib4.h"
#include <float.h>
#include <math.h>
#include "Circle.h"
#include "Plane.h"
class Ray
{
public:
	Ray();
	Ray(const Vector2& start, const Vector2& dir, float l = INFINITY) : origin(start), direction(dir), length(l) {}
	~Ray();
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
	float clamp(float t, float a, float b) {
		return max(a, min(b, t));
	}
	Vector2 clamp(const Vector2& t, const Vector2& a, const Vector2& b) {
		return max(a, max(b, t));
	}
	bool intersects(Circle circle, Vector2* i, Vector2* R);
	bool intersects(Plane plane, Vector2* I = nullptr) {
		// project ray direction onto plane normal
		// this should give us a value between -1 and 1
		float t = direction.dot(plane.m_normal);
		// must face the plane
		if (t > 0)
			return false;
		// get distance of ray origin to the plane
		float d = origin.dot(plane.m_normal) + plane.m_d;
		// check if ray is parallel with the plane
		// no intersection if parallel and not touching
		if (t == 0 &&
			d != 0)
			return false;
		// calculate distance along ray to plane
		t = d == 0 ? 0 : -(d / t);
		// intersects if within range
		if (t >= 0 &&
			t <= length) {
			// store intersection point if requested
			if (I != nullptr)
			{
				*I = origin + direction * t;
				intersectingPoint = *I;
			}
			return true;
		}
		// default no intersection
		return false;
	}
	Vector2 intersectingPoint;
	Vector2 closestPoint(Vector2& point);
	Vector2 origin;
	Vector2 direction;
	float length = 1400;
};

