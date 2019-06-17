#include "Ray.h"
#include <iostream>


Ray::Ray()
{
}


Ray::~Ray()
{
}

Vector2 Ray::closestPoint(Vector2& point)
{
	auto p = point - origin;

	float t = clamp(p.dot(direction), 0, length);

	return origin + direction * t;

}

bool Ray::intersects(Circle circle, Vector2* i = nullptr, Vector2* R = nullptr)
{
	auto L = circle.m_center - origin;
	float t = L.dot(direction);
	float dd = L.dot(L) - t;

	t -= sqrt(circle.m_radius - dd);
	if (t >= 0 && t <= length)
	{
		if (i != nullptr)
		{
			*i = origin + direction * t;
			std::cout << "works" << std::endl;
		}
		
		if (R != nullptr)
		{
			auto N = ((origin + direction * t) - circle.m_center);
			N /= circle.m_radius;

			auto P = direction * (length - t);
			float p = P.dot(N);

			*R = N * -2 * p + P;
		}
		
		return true;
	}
	return false;
}