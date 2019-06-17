#include "Circle.h"
#include <algorithm>
#include <iostream>

Circle::Circle()
{
}


Circle::~Circle()
{
}

void Circle::fit(const Vector2* points, unsigned int count)
{
	Vector2 Min = { FLT_MAX, FLT_MAX };
	Vector2 Max = { FLT_MIN, FLT_MIN };

	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		Min = min(Min, *points);
		Max = max(Max, *points);
	}

	m_center = (Min + Max) * 0.5f;
	m_radius = m_center.distance(Max);
}

void Circle::fit(const std::vector<Vector2>& points)
{
	Vector2 Min = { FLT_MAX,FLT_MAX };
	Vector2 Max = { FLT_MIN, FLT_MIN };

	for (auto& p : points)
	{
		Min = min(Min, p);
		Max = max(Max, p);
	}

	m_center = (Min + Max) * 0.5f;
	m_radius = m_center.distance(Max);
}
bool Circle::overlaps(Vector2 p) 
{
	Vector2 toPoint = p - m_center;
	return toPoint.magnitude() <= (m_radius);
}
bool Circle::overlaps(Circle& other)
{
	Vector2 diff = m_center - other.m_center;
	float r = m_radius + other.m_radius;

	if (diff.magnitude() <= (r))
	{

		if (m_parent != nullptr)
		{
			if (other.childCount() == 0)
			{
				childMoves(other);
			}
		}
		else
		{
			Vector2 tangentVector;
			//a vector perpendicular to (x,y)
			tangentVector.y = -(other.m_center.x - m_center.x);
			tangentVector.x = (other.m_center.y - m_center.y);
			tangentVector.normalise();
			Vector2 relativeVelocity = Vector2(m_velocity.x - other.m_velocity.x, m_velocity.y - other.m_velocity.y);
			float length = relativeVelocity.dot(tangentVector);
			Vector2 velocityComponent;
			velocityComponent = tangentVector * length;
			Vector2 velocityComponentPerpToTangent = relativeVelocity - velocityComponent;
			circleMove(velocityComponentPerpToTangent, other);
		}
	}
	return diff.magnitude() <= (r);
}

void Circle::childMoves(Circle& other)
{
	m_parent->removeChild(this);
	other.addChild(this);
	other.conversionMatrix();

}
void Circle::circleMove(Vector2 move, Circle& other)
{
	m_velocity.x -= move.x;
	m_velocity.y -= move.y;
	other.m_velocity.x += move.x;
	other.m_velocity.y += move.y;
}
Vector2 Circle::closestPoint(Vector2 p) const
{
	Vector2 toPoint = p - m_center;

	if (toPoint.magnitude() > m_radius)
	{
		toPoint = toPoint.normalise() * m_radius;
	}

	return m_center + toPoint;
}

void Circle::onDraw(aie::Renderer2D* renderer)
{
	if (m_texture != nullptr)
		renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
	else
		renderer->drawCircle(m_center.x, m_center.y, m_radius);
}
bool Circle::load(const char* fileName)
{
	delete m_texture; 
	m_texture = nullptr; 
	m_texture = new aie::Texture(fileName);
	return m_texture != nullptr;
}


void Circle::updateTransform()
{
	if (m_parent != nullptr)
	{
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
		conversionVector();
	}
	else
	{
		m_globalTransform = m_localTransform;
		conversionVector();
	}
	for (auto child : m_children)
		child->updateTransform();
}
