// MathLib4.cpp : Defines the exported functions for the DLL application.
//
// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "stdafx.h" // use pch.h in Visual Studio 2019
#include <utility>
#include <limits.h>
#include "MathLib4.h"
#include <cmath>

///////////
//Vector2//
///////////

Vector2::Vector2(float a, float b)
{
	x = a;
	y = b;
}
Vector2::Vector2()
{
	x = 0;
	y = 0;
}
float& Vector2::operator [] (int index)
{
	return data[index];
}

Vector2 Vector2::operator + (const Vector2& other) const
{
	return { x + other.x, y + other.y };
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator - (const Vector2 other)
{

	return { x - other.x, y - other.y };
}
Vector2 Vector2::operator * (float scalar) const
{
	return { x * scalar, y * scalar };
}
Vector2 operator * (float scalar, Vector2& v)
{
	return { v.x * scalar, v.y *scalar };
}
Vector2& Vector2::operator /= (float scalar)
{
	x /= scalar; y /= scalar;
	return *this;
}
Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x; y = other.y;
	return *this;
}

float Vector2::magnitude() const
{
	return sqrt(x*x + y * y);
}

float Vector2::distance(const Vector2& other) const
{
	float diffX = x - other.x;
	float diffY = y - other.y;
	return sqrt(diffX * diffX + diffY * diffY);
}

Vector2 Vector2::normalise(Vector2& v) const
{
	float mag = sqrt(v.x * v.x + v.y * v.y);
	return { v.x /= mag, v.y /= mag};
}
Vector2 Vector2::normalise()
{
	float mag = sqrt(x * x + y * y);
	return { x /= mag, y /= mag };
}
float Vector2::dot(Vector2& other) const
{
	return x * other.x + y * other.y;
}

///////////
//Vector3//
///////////

float& Vector3::operator [] (int index)
{
	return data[index];
}

Vector3 Vector3::operator + (const Vector3& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

Vector3& Vector3::operator -= (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}
Vector3& Vector3::operator - (const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar };
}
Vector3& Vector3::operator /= (float scalar)
{
	x /= scalar; y /= scalar; z /= scalar;
	return *this;
}

Vector3& Vector3::operator = (const Vector3& other)
{
	x = other.x; y = other.y; z = other.z;
	return *this;
}


Vector3 operator * (float scalar, Vector3& v)
{
	return { v.x * scalar, v.y *scalar, v.z * scalar };
}

Vector3::Vector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

float Vector3::magnitude() const
{
	return sqrt(x*x + y * y + z * z);
}

float Vector3::distance(const Vector3& other) const
{
	float diffX = x - other.x; 
	float diffY = y - other.y; 
	float diffZ = z - other.z; 
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

Vector3 Vector3::normalise(Vector3& v) const 
{
	float mag = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return { v.x /= mag, v.y /= mag, v.z /= mag };
}
Vector3 Vector3::normalise()
{
	float mag = sqrt(x * x + y * y + z * z);
	return { x /= mag, y /= mag, z /= mag };
}
float Vector3::dot(Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}
Vector3 Vector3::cross(Vector3& other) const
{
	
	return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
}

///////////
//Vector4//
///////////

Vector4::Vector4(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

float& Vector4::operator [] (int index)
{
	return data[index];
}

Vector4 Vector4::operator + (const Vector4& other) const
{
	return { x + other.x, y + other.y, z + other.z, w + other.w };
}

Vector4& Vector4::operator -= (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::operator - (const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4 Vector4::operator * (float scalar) const
{
	return { x * scalar, y * scalar, z * scalar, w * scalar };
}
Vector4 operator * (float scalar, Vector4& v)
{
	return { v.x * scalar, v.y *scalar, v.z * scalar, v.w * scalar };
}

Vector4& Vector4::operator /= (float scalar)
{
	x /= scalar; y /= scalar; z /= scalar; w /= scalar;
	return *this;
}

Vector4& Vector4::operator = (const Vector4& other)
{
	x = other.x; y = other.y; z = other.z; w = other.w;
	return *this;
}

float Vector4::magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::distance(const Vector4& other) const
{
	float diffX = x - other.x;
	float diffY = y - other.y;
	float diffZ = z - other.z;
	float diffW = w - other.w;
	return sqrt(diffX * diffX + diffY * diffY + diffZ * diffZ + diffW * diffW);
}

Vector4 Vector4::normalise(Vector4& v) const
{
	float mag = sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	return { v.x /= mag, v.y /= mag, v.z /= mag, v.z /= mag };
}
Vector4 Vector4::normalise() 
{
	float mag = sqrt(x * x + y * y + z * z + w * w);
	return { x /= mag, y /= mag, z /= mag, w /= mag };
}

float Vector4::dot(Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}
Vector4 Vector4::cross(Vector4& other) const
{
	return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0 };
}

///////////
//Matrix3//
///////////

Matrix3::Matrix3()
{
	xAxis = { 1,0,0 };
	yAxis = { 0,1,0 };
	zAxis = { 0,0,1 };
}

Matrix3::Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	xAxis = { a,b,c };
	yAxis = { d,e,f };
	zAxis = { g,h,i };
}

void Matrix3::setScaled(float x, float y, float z)
{
	xAxis = { x,0,0 };
	yAxis = { 0,y,0 };
	zAxis = { 0,0,z };
}
void Matrix3::setScaled(Vector3& v)
{
	xAxis = { v.x,0,0 };
	yAxis = { 0,v.y,0 };
	zAxis = { 0,0,v.z };
}
void Matrix3::scale(float x, float y, float z)
{
	Matrix3 m;
	m.setScaled(x, y, z);
	*this = (*this * m);
}
void Matrix3::scale(Vector3& v)
{
	Matrix3 m;
	m.setScaled(v.x, v.y, v.z);
	*this = (*this * m);
}

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
			result.data[c][r] = data[0][r] * other.data[c][0] + data[1][r] * other.data[c][1] + data[2][r] * other.data[c][2];
	}
	return result;
}

Vector3 Matrix3::operator * (Vector3& v) const
{
	Vector3 result;
	
	result[0] = data[0][0] * v[0] + data[1][0] * v[1] + data[2][0] * v[2];
	result[1] = data[0][1] * v[0] + data[1][1] * v[1] + data[2][1] * v[2];
	result[2] = data[0][2] * v[0] + data[1][2] * v[1] + data[2][2] * v[2];
	
	return result;
}

Matrix3 Matrix3::operator = (const Matrix3& other) 
{ 
	xAxis = other.xAxis;
	yAxis = other.yAxis;
	zAxis = other.zAxis;
	return *this;
}


Matrix3 Matrix3::transposed() const
{
	Matrix3 result;

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c, 3; ++c)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

void Matrix3::setRotateX(float radians)
{
	xAxis = { 1,0,0 };
	yAxis = { 0, cosf(radians), sinf(radians) };
	zAxis = { 0, -sinf(radians), cosf(radians) };
}

void Matrix3::rotateX(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = m;
}


void Matrix3::setRotateY(float radians)
{

	xAxis = { cosf(radians),0,-sinf(radians) };
	yAxis = { 0, 1, 0 };
	zAxis = { sinf(radians), 0, cosf(radians) };
}

void Matrix3::rotateY(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = (*this * m);
}


void Matrix3::setRotateZ(float radians)
{
	xAxis = {cosf(radians), sinf(radians),0};
	yAxis = {-sinf(radians), cosf(radians),0};
	zAxis = { 0,0,1 };
}

void Matrix3::rotateZ(float radians)
{
	Matrix3 m;
	m.setRotateX(radians);
	*this = (*this * m);
}
void Matrix3::setEUler(float pitch, float yaw, float roll)
{
	Matrix3 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	*this = (z*y*x);
}
void Matrix3::translate(float x, float y)
{
	zAxis = zAxis + Vector3(x, y, 0);
}

///////////
//Matrix4//
///////////

Matrix4::Matrix4()
{
	xAxis = { 1,0,0,0 };
	yAxis = { 0,1,0,0 };
	zAxis = { 0,0,1,0 };
	Translation = { 0,0,0,1 };
}
Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
{
	xAxis = { a,b,c,d };
	yAxis = { e,f,g,h };
	zAxis = { i,j,k,l};
	Translation = { m,n,o,p };
}
void Matrix4::setScaled(float x, float y, float z)
{
	xAxis = { x,0,0,0 };
	yAxis = { 0,y,0,0 };
	zAxis = { 0,0,z,0 };
	Translation = { 0,0,0,1 };
}
void Matrix4::setScaled(Vector4 v)
{
	xAxis = { v.x,0,0,0 };
	yAxis = { 0,v.y,0,0 };
	zAxis = { 0,0,v.z,0 };
	Translation = { 0,0,0,1 };
}
void Matrix4::scale(float x, float y, float z)
{
	Matrix4 m;
	m.setScaled(x, y, z);
	*this = (*this * m);
}
void Matrix4::scale(Vector4& v)
{
	Matrix4 m;
	m.setScaled(v.x, v.y, v.z);
	*this = (*this * m);
}

Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
			result.data[c][r] = data[0][r] * other.data[c][0] + data[1][r] * other.data[c][1] + data[2][r] * other.data[c][2] + data[3][r] * result.data[c][3];
	}
	return result;
}

Vector4 Matrix4::operator * (Vector4& v) const
{
	Vector4 result;
	result[0] = data[0][0] * v[0] + data[1][0] * v[1] + data[2][0] * v[2] + data[3][0] * v[3];
	result[1] = data[0][1] * v[0] + data[1][1] * v[1] + data[2][1] * v[2] + data[3][1] * v[3];
	result[2] = data[0][2] * v[0] + data[1][2] * v[1] + data[2][2] * v[2] + data[3][2] * v[3];
	result[3] = data[0][3] * v[0] + data[1][3] * v[1] + data[2][3] * v[2] + data[3][3] * v[3];

	return result;
}
Matrix4 Matrix4::operator = (const Matrix4& other)
{
	xAxis = other.xAxis;
	yAxis = other.yAxis;
	zAxis = other.zAxis;
	Translation = other.Translation;
	return *this;
}


Matrix4 Matrix4::transposed() const
{
	Matrix4 result;

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c, 3; ++c)
		{
			result.data[r][c] = data[c][r];
		}
	}
	return result;
}

void Matrix4::setRotateX(float radians)
{
	xAxis = { 1,0,0,0};
	yAxis = { 0, cosf(radians), sinf(radians), 0 };
	zAxis = { 0, -sinf(radians), cosf(radians), 0 };
	Translation = { 0,0,0,1 };
}

void Matrix4::rotateX(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = (*this * m);
}


void Matrix4::setRotateY(float radians)
{

	xAxis = { cosf(radians),0, -sinf(radians), 0 };
	yAxis = { 0, 1, 0, 0 };
	zAxis = { sinf(radians), 0, cosf(radians), 0 };
	Translation = { 0,0,0,1 };
}

void Matrix4::rotateY(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = (*this * m);
}


void Matrix4::setRotateZ(float radians)
{
	xAxis = {cosf(radians), sinf(radians), 0, 0};
	yAxis = {-sinf(radians), cosf(radians), 0, 0};
	zAxis = { 0,0,1,0 };
	Translation = { 0,0,0,1 };
}

void Matrix4::rotateZ(float radians)
{
	Matrix4 m;
	m.setRotateX(radians);
	*this = (*this * m);
}
void Matrix4::setEUler(float pitch, float yaw, float roll)
{
	Matrix4 x, y, z;
	x.setRotateX(pitch);
	y.setRotateY(yaw);
	z.setRotateZ(roll);

	*this = (z*y*x);
}

void Matrix4::translate(float x, float y, float z)
{
	Vector4 v;
	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	Translation = v;
}

