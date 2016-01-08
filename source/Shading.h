#ifndef _SHADING_H_
#define _SHADING_H_

#include "Color.h"
#include "Vec.h"
#include "Light.h"
#include "Ray.h"

using namespace std;

class Shading
{
public:
	static Color GetPhong(Light* light, Ray ray, Vector Q, Vector eye, Object* object);
};

#endif