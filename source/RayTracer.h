#ifndef _RAYTRACE_H_
#define _RAYTRACE_H_

#include <vector>
#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include "Object.h"
#include "Light.h"

using namespace std;

class RayTracer
{
private:
	vector<Object*> objects;
	Light* light;
	int width, height;
	Vector eye;
	float z_plane;
public:
	RayTracer(int width, int height);
	void Setup();
	Color TracePixel(int x, int y);
};

#endif