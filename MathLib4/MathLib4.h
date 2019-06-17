#pragma once
// MathLibrary.h - Contains declarations of math functions

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif


class MATHLIBRARY_API Vector2
{
public:
	union {
		struct {
			float x, y; //the vector values
		};
		float data[2];//an array that stores the 2d vectors values
	};
	//float& operator[](int index), overloads the subscript so users are able to access each element directly
	//input: int index, the element number
	//output: data[index] the target elements value
	float& operator [](int index);
	//Vector2(float a, float b) a constructor that enables intialization of the elements 
	//input: float a, float b, values that go into this vector
	Vector2(float a, float b);
	//Vector2() sets the values of the vector if not intialized
	Vector2();
	//Vector2 operator + (const Vector2& other) const, adds two 2D vectors together
	//input: const Vector2& other, the 2D vector which is going to be added to this vector
	//output: the result of the vector addittion
	Vector2 operator + (const Vector2& other) const;
	Vector2& operator -= (const Vector2& other);
	//Vector2 operator - (const Vector2& other), subtracts two 2D vectors
	//input: const Vector2& other, the other 2D vector which is going to be subtracted with this vector
	//output: the result of the vector subtraction
	Vector2 operator - (const Vector2 other);
	//friend Vector2 MATHLIBRARY_API operator * (float scalar, Vector2& v), a friend function that is used to pre scale a 2D vector
	//intput: float scalar, Vector2& v, the scalar and vector that is to be multiplied together
	//output: result of the multiplication a scaled vector
	friend Vector2 MATHLIBRARY_API operator * (float scalar, Vector2& v);
	//Vector2& operator = (const Vector2& other), makes this vector equal to parameters vector(other)
	//input: const Vector2& other, the vector that is being equalled to 
	//outut: a vector with the same values as the parameter vector
	Vector2& operator = (const Vector2& other);
	Vector2& operator /= (float scalar);
	//Vector2 operator * (float scalar) const, scales a 2d vector
	//input: float scalar, the scaling value to scale the vector
	//output: a scaled vector
	Vector2 operator * (float scalar) const;
	//operator float*(), a conversion function
	//output: returns the data array which contains the values of the vector
	operator float*() { return data; }
	operator const float*() { return data; }
	//float magnitude() const, finds the magnitude of the vector by using this formula sqrt(a*a + b*b)   (pythagoras theorem)
	//output: the magnitude of the vector
	float magnitude() const;
	//float distance(const Vector2& other) const, finds the distance between two vectors by subtracting both vectors and using the same pythagoras formula
	float distance(const Vector2& other) const;
	Vector2 normalise(Vector2& v) const;
	//Vector2 normalise(), calculates the normal for the vector
	//output: a normalised vector
	Vector2 normalise();
	//float dot(Vector2& other) const, finds the angle between two vectors
	//input: Vector2& other, the vector that is being compared to 
	//output: the angle between the two vectors
	float dot(Vector2& other) const;
};



//class Vector3 a 3d vector which has the same functions as vector2 the only difference is that it has another value which corresponds to the extra dimension
class MATHLIBRARY_API Vector3
{
public:
	union {
		struct {
			float x, y;
			union {
				float z, w;//the w variable is used for translation
			};
		};
		struct {
			float r, g, b;
		};
		float data[3];
	};
	float& operator [](int index);
	Vector3(float a, float b, float c);
	Vector3();
	Vector3 operator + (const Vector3& other) const;
	friend Vector3 MATHLIBRARY_API operator * (float scalar, Vector3& v);
	Vector3& operator -= (const Vector3& other);
	Vector3& operator - (const Vector3& other);
	Vector3& operator = (const Vector3& other);
	Vector3& operator /= (float scalar);
	Vector3 operator * (float scalar) const;
	operator float*() { return data; }
	operator const float*() { return data; }
	float magnitude() const;
	float distance(const Vector3& other) const;
	Vector3 normalise(Vector3& v) const;
	Vector3 normalise();
	float dot(Vector3& other) const;
	//Vector3 cross(Vector3& other) const, creates a new vector which is perpendicular to both vectors
	//input: Vector3& other, the other vector that is used to find the new vector
	//outpu: the new vector that is perpendicular to both vectors
	Vector3 cross(Vector3& other) const;
};

// class Vector4 a 4d vector which has the same functions as vector2 the only difference is that it has extra values which corresponds to the extra dimensions
class MATHLIBRARY_API Vector4
{
public:
	union {
		struct {
			float x, y, z, w;
		};
		float data[4];
	};
	float& operator [](int index);
	Vector4(float a, float b, float c, float d);
	Vector4();
	Vector4 operator + (const Vector4& other) const;
	Vector4& operator -= (const Vector4& other);
	Vector4& operator - (const Vector4& other);
	Vector4& operator = (const Vector4& other);
	Vector4& operator /= (float scalar);
	Vector4 operator * (float scalar) const;
	friend Vector4 operator * (float scalar, Vector4& v);
	operator float*() { return data; }
	operator const float*() { return data; }
	float magnitude() const;
	float distance(const Vector4& other) const;
	Vector4 normalise(Vector4& v) const;
	Vector4 normalise();
	float dot(Vector4& other) const;
	Vector4 cross(Vector4& other) const;
};

class MATHLIBRARY_API Matrix3
{
public:
	union {
		struct {
			Vector3 xAxis;
			Vector3 yAxis;
			union {
				Vector3 zAxis;
				Vector3 translation;
			};
		};
		Vector3 axis[3];
		float data[3][3];
	};
	//Matrix3(), makes a default matrix
	Matrix3();
	//Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i), initializes the matrix with parameter values
	//input: float a-i, the values that is used to intialize the elements of the matrix
	Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
	//Vector3& operator [] (int index), overloads the subscript so users are able to access each element directly
	//input: int index, the element position
	//output: the target elements value
	Vector3& operator [] (int index) {return axis[index];}
	const Vector3& operator [] (int index) const {return axis[index];}
	operator float*() { return *data; }
	operator const float*() { return *data; }
	Matrix3 identity() { return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1); }
	//Matrix3 operator * (const Matrix3& other) const, multiplies another matrix with thhis matrix
	//input: const Matrix3& other, the matrix that is being multiplied with this matrix
	//output: the result of the matrix multiplication
	Matrix3 operator * (const Matrix3& other) const;
	//Matrix3 transposed() const, tranposes the matrix
	//output: a transposed matrix
	Matrix3 transposed() const;
	//Vector3 operator * (Vector3& v) const, multiplies this matrix by a vector
	//input: Vector3& v, the vector that is being multiplied with this matrix
	Vector3 operator * (Vector3& v) const;
	//Matrix3 operator = (const Matrix3& other), makes the variables of this matrix equal to another matrix
	//input: const Matrix3& other, the other matrix that is used
	//output: a copy of the other matrix 
	Matrix3 operator = (const Matrix3& other);
	//void setScaled(float x, float y, float z), creates a matrix that is used to scale this matrix
	//input: float x, float y, float z, the values used to put inside the scaling matrix
	//output: a scale matrix
	void setScaled(float x, float y, float z);
	//void setScaled(Vector& v), creates a matrix that is used to scale this matrix but uses a vector instead of floats
	void setScaled(Vector3& v);
	//void scale(float x, float y, float z), creates the scaling matrix and also uses the setScaled function to input the scale values and also scales this matrix
	//input: float x, float y, float z, the values used to put inside the scaling matrix
	void scale(float x, float y, float z);
	void scale(Vector3& v);
	//void setRotateX(float radians), used to set the rotation matrix for the x rotation
	//input: float radians, the variable that is used to create to intialize the rotation matrix
	void setRotateX(float radians);
	//void rotateX(float radians), creates the rotation matrix and also uses the setRotateX function to intialize the rotation matrix and also rotates this matrix 
	void rotateX(float radians);
	void setRotateY(float radians);
	void rotateY(float radians);
	void setRotateZ(float radians);
	void rotateZ(float radians);
	void setEUler(float pitch, float yaw, float roll);
	void translate(float x, float y);
};
//a 4 by 4 matrix which has the same functions and variables as the class matrix3 but it has an extra variables, this is used in translating 3d objects
class MATHLIBRARY_API Matrix4
{
public:
	union {
		struct {
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 Translation;
		};
		Vector4 axis[4];
		float data[4][4];
	};
	Matrix4();
	Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	Vector4& operator [] (int index) {return axis[index];}
	const Vector4& operator [] (int index) const {return axis[index];}
	Matrix4 operator * (const Matrix4& other) const;
	Matrix4 transposed() const;
	Vector4 operator * (Vector4& v) const;
	operator float*() { return *data; }
	operator const float*() { return *data; }
	Matrix4 operator = (const Matrix4& other);
	void translate(float x, float y, float z);
	void setScaled(float x, float y, float z);
	void setScaled(Vector4 v);
	void scale(float x, float y, float z);
	void scale(Vector4& v);
	void setRotateX(float radians);
	void rotateX(float radians);
	void setRotateY(float radians);
	void rotateY(float radians);
	void setRotateZ(float radians);
	void rotateZ(float radians);
	void setEUler(float pitch, float yaw, float roll);
};