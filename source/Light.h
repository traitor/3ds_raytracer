#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "Object.h"
#include "Ray.h"

class Light : public Object
{
public:
	//We never use this for collisionsGetNormal(Vector point)
	float CheckCollision(Ray ray) { return -1.0f; }
	Vector GetNormal(Vector point) { Vector normal; return normal; }
};

#endif