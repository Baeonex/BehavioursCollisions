#include "Plane.h"



Plane::Plane()
{
}


Plane::~Plane()
{
}

Plane::Plane(Vector2& p1, Vector2& p2)
{
	auto v = p2 - p1;
	v.normalise();

	m_normal.x = -v.y;
	m_normal.y = v.x;

	m_d = -p1.dot(m_normal);

}
float Plane::distanceTo(const Vector2& p)
{
	return p.dot(m_normal) + m_d;
}
Vector2 Plane::closestPoint(Vector2 p)
{
	return p - m_normal * distanceTo(p);
}
ePlaneResult Plane::testSide(const Vector2& p)
{
	float t = p.dot(m_normal) + m_d;

	if (t < 0)
		return ePlaneResult::BACK;
	else if (t > 0)
		return ePlaneResult::FRONT;
	return ePlaneResult::INTERSECTS;
}
void Plane::collRes(Circle& circle)
{
	Vector2 reflected;
	reflected = 2 * m_normal * (m_normal.dot(circle.m_velocity));
	circle.m_velocity -= reflected;
}
ePlaneResult Plane::testSide(const Circle& circle)
{
	float t = distanceTo(circle.m_center);
	if (t > circle.m_radius)
		return ePlaneResult::FRONT;
	else if (t < -circle.m_radius)
		return ePlaneResult::BACK;
	else
		return ePlaneResult::INTERSECTS;
}