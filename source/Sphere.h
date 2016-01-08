#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Object.h"

class Sphere : public Object
{
private:
	float radius;
public:
	Sphere(Vector origin, float radius);
	float CheckCollision(Ray ray);
	Vector GetNormal(Vector point);
};

#endif