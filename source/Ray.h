#ifndef _RAY_H_
#define _RAY_H_

#include "Vec.h"

class Ray
{
private:
	Vector origin;
	Vector direction;
public:
	Ray();
	Ray(Vector origin, Vector direction);
	Vector GetOrigin();
	Vector GetDirection();
	void SetOrigin(Vector O);
	void SetDirection(Vector D);

	static Ray GetRefractedRay(Ray V, Vector Q, Vector N);
	static Ray GetReflectedRay(Ray V, Vector Q, Vector N);
};

#endif