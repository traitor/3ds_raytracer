#include "Ray.h"
#include "Vec.h"

Ray::Ray()
{

}

Ray::Ray(Vector origin, Vector direction)
{
	this->origin = origin;
	this->direction = direction;
}

Ray Ray::GetRefractedRay(Ray V, Vector Q, Vector N)
{
/* todo */
}

Ray Ray::GetReflectedRay(Ray V, Vector Q, Vector N)
{
	Ray reflection;
	reflection.SetOrigin(Q);
	Vector T = V.GetDirection() + (2 * Vector::Dot(V.GetDirection(), N) * N);
	reflection.SetDirection(T);

	return reflection;
}

Vector Ray::GetOrigin()
{
	return this->origin;
}

Vector Ray::GetDirection()
{
	return this->direction;
}

void Ray::SetOrigin(Vector O)
{
	this->origin = O;
}

void Ray::SetDirection(Vector D)
{
	this->direction = D;
}
