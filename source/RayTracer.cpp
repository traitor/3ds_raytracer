#include "RayTracer.h"
#include "Sphere.h"
#include "Shading.h"

RayTracer::RayTracer(int width, int height)
{
	this->width = width;
	this->height = height;
}

void RayTracer::Setup()
{
	objects.resize(3);

	Sphere* sphere = new Sphere(Vector(1.5f, -0.2f, -3.2f), 1.23f);
	sphere->SetAmbient(Color(0.7, 0.7, 0.7));
	sphere->SetDiffuse(Color(0.1, 0.5, 0.8));
	sphere->SetSpecular(Color(1.0, 1.0, 1.0));
	objects[0] = sphere;

	sphere = new Sphere(Vector(-1.5f, 0.f, -3.5f), 1.5f);
	sphere->SetAmbient(Color(0.6, 0.6, 0.6));
	sphere->SetDiffuse(Color(1.0, 0.0, 0.25));
	sphere->SetSpecular(Color(1.0, 1.0, 1.0));
	objects[1] = sphere;

	sphere = new Sphere(Vector(-0.35f, 1.75f, -2.25f), 0.5f);
	sphere->SetAmbient(Color(0.2, 0.2, 0.2));
	sphere->SetDiffuse(Color(0.0, 1.0, 0.25));
	sphere->SetSpecular(Color(0.0, 1.0, 0.0));
	objects[2] = sphere;

	light = new Light();
	light->SetAmbient(Color(0.1, 0.1, 0.1));
    light->SetDiffuse(Color(1.0, 1.0, 1.0));
    light->SetSpecular(Color(1.0, 1.0, 1.0));
    light->SetOrigin(Vector(-2, 5, 1));

	eye.x = 0;
	eye.y = 0;
	eye.z = 0;

	z_plane = -1.5f;
}

Color RayTracer::TracePixel(int x, int y)
{
	Color C;
	//background color
	C.r = 0.5;
	C.g = 0.05;
	C.b = 0.8;

  	float image_width = 5.0f;
  	float image_height = (float(320) / float(400)) * image_width;
  	float x_grid_size = image_width / float(400);
	float y_grid_size = image_height / float(320);

	float x_start = -0.5 * image_width;
    float y_start = -0.5 * image_height;
    Vector start;
    start.x = x_start + (0.5 + x) * x_grid_size;
    start.y = y_start + (0.5 + y) * y_grid_size;
    start.y *= -1; //?eh?
    start.z = z_plane;

    Ray ray(eye, start - eye);

    Object* closest = NULL;
    float distance = 0.f;
    
	for (vector<Object*>::iterator i = objects.begin(); i != objects.end(); ++i)
	{
		Object* o = *i;
		float d = o->CheckCollision(ray);

		if (d > 0.f && (closest == NULL || d < distance))
		{
			closest = o;
			distance = d;
		}
	}

	if (closest != NULL)
	{
		Vector intersection;
		intersection.x = eye.x + distance * ray.GetDirection().x;
		intersection.y = eye.y + distance * ray.GetDirection().y;
		intersection.z = eye.z + distance * ray.GetDirection().z;

		Color phong = Shading::GetPhong(light, ray, intersection, eye, closest);
		C = closest->GetAmbient() * light->GetAmbient();
		C = C + phong;
	}

	return C;
}