#include "Vec.h"
#include <cmath>

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector::Normalize()
{
	float length = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	this->x /= length;
	this->y /= length;
	this->z /= length;
}

float Vector::Dot(Vector A, Vector B)
{
	float result = 0.f;
	result += A.x * B.x;
	result += A.y * B.y;
	result += A.z * B.z;
	return result;
}

/*Vector Vector::Cross(Vector A, Vector B)
{

}*/

Vector operator+(const Vector& A, const Vector& B)
{
	Vector V;
	V.x = A.x + B.x;
	V.y = A.y + B.y;
	V.z = A.z + B.z;
	return V;
}

Vector operator-(const Vector& A, const Vector& B)
{
	Vector V;
	V.x = A.x - B.x;
	V.y = A.y - B.y;
	V.z = A.z - B.z;
	return V;
}

Vector operator*(float constant, const Vector& v)
{
	Vector V;
	V.x = v.x * constant;
	V.y = v.y * constant;
	V.z = v.z * constant;
	return V;
}

Vector operator*(const Vector& v, float constant)
{
	Vector V;
	V.x = v.x * constant;
	V.y = v.y * constant;
	V.z = v.z * constant;
	return V;
}