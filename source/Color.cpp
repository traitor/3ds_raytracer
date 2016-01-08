#include "Color.h"

Color::Color()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::Color(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

Color operator+(const Color& A, const Color& B)
{
	Color V;
	V.r = A.r + B.r;
	V.g = A.g + B.g;
	V.b = A.b + B.b;
	return V;
}

Color operator-(const Color& A, const Color& B)
{
	Color V;
	V.r = A.r - B.r;
	V.g = A.g - B.g;
	V.b = A.b - B.b;
	return V;
}

Color operator*(float constant, const Color& v)
{
	Color V;
	V.r = v.r * constant;
	V.g = v.g * constant;
	V.b = v.b * constant;
	return V;
}

Color operator*(const Color& v, float constant)
{
	Color V;
	V.r = v.r * constant;
	V.g = v.g * constant;
	V.b = v.b * constant;
	return V;
}

Color operator*(const Color& A, const Color& B)
{
	Color V;
	V.r = A.r * B.r;
	V.g = A.g * B.g;
	V.b = A.b * B.b;
	return V;
}