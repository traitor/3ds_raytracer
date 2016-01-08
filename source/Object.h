#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Vec.h"
#include "Color.h"
#include "Ray.h"

class Object
{
protected:
	Vector origin;

	Color ambient;
	Color diffuse;
	Color specular;
	float shineness;
	float reflectance;
public:
	virtual ~Object() { }
	virtual float CheckCollision(Ray ray) =0;
	virtual Vector GetNormal(Vector point) =0;

	Vector GetOrigin();
	Color GetAmbient();
	Color GetDiffuse();
	Color GetSpecular();
	float GetShineness();
	float GetReflectance();
	void SetOrigin(Vector origin);
	void SetAmbient(Color ambient);
	void SetDiffuse(Color diffuse);
	void SetSpecular(Color specular);
	void SetShineness(float shineness);
	void SetReflectance(float reflectance);
};

#endif