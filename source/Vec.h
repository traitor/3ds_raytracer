#ifndef _VEC_H_
#define _VEC_H_

class Vector
{
private:
public:
	Vector();
	Vector(float x, float y, float z);
	float x, y, z;
	void Normalize();

	static float Dot(Vector A, Vector B);
	/*static Vector Cross(Vector A, Vector B);*/

	friend Vector operator+(const Vector& A, const Vector& B);
	friend Vector operator-(const Vector& A, const Vector& B);
	friend Vector operator*(const Vector& v, float constant);
	friend Vector operator*(float constant, const Vector& v);
};

#endif