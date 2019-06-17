#pragma once
#include "MathLib4.h"
#include <cstdlib>
#include <vector>
#include <float.h>
class Box
{
public:
	Box();
	Box(const Vector2& min, const Vector2& max) : Min(min), Max(max) {}
	~Box();
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
		return max(a, min(b, t));
	}
	Vector2 Min, Max;

	Vector2 center() const {
		return (Min + Max) * 0.5f;
	}
	Vector2 extents() const {
		return { abs(Max.x - Min.x) * 0.5f, abs(Max.y - Min.y) * 0.5f };
	}

	std::vector<Vector2> corners() const {
		std::vector<Vector2> corners(4);
		corners[0] = Min;
		corners[1] = { Min.x, Max.y };
		corners[2] = Max;
		corners[3] = { Max.x, Min.y };
		return corners;
	}

	void fit(const Vector2* points, unsigned int count) {
		Min = { FLT_MAX, FLT_MAX };
		Max = { FLT_MIN, FLT_MIN };
		for (unsigned int i = 0;
			i < count;
			++i, ++points) {
			Min = min(Min, *points);
			Max = max(Max, *points);
		}
	}	void fit(const std::vector<Vector2>& points) {
		Min = { FLT_MAX, FLT_MAX };
		Max = { FLT_MIN, FLT_MIN };
		// find min and max of the points
		for (auto& p : points) {
			Min = min(Min, p);
			Max = max(Max, p);
		}
	}	bool overlaps(const Vector2& p) const {

		return !(p.x < Min.x || p.y < Min.y ||
			p.x > Max.x || p.y > Max.y);
	}
	bool overlaps(const Box& other) const {
		return !(Max.x < other.Min.x || Max.y < other.Min.y ||
			Min.x > other.Max.x || Min.y > other.Max.y);
	}

	Vector2 closestPoint(const Vector2& p) {
		return clamp(p, Min, Max);
	}
};

