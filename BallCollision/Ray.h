#pragma once
#include "MathLib4.h"
#include <float.h>
#include <math.h>
#include "Circle.h"
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
	Vector2 closestPoint(Vector2& point);
	Vector2 origin = {1, 720};
	Vector2 direction = {1, 0};
	float length = 1400;
};

