#ifndef _COLOR_H_
#define _COLOR_H_

class Color
{
private:
public:
	Color();
	Color(float r, float g, float b);
	float r, g, b;

	friend Color operator+(const Color& A, const Color& B);
	friend Color operator-(const Color& A, const Color& B);
	friend Color operator*(const Color& v, float constant);
	friend Color operator*(float constant, const Color& v);
	friend Color operator*(const Color& A, const Color& B);
};

#endif