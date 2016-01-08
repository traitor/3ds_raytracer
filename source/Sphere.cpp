#include "Sphere.h"
#include <cmath>

Sphere::Sphere(Vector origin, float radius)
{
	this->origin = origin;
	this->radius = radius;
}

float Sphere::CheckCollision(Ray ray)
{
	Vector q = ray.GetOrigin();
	Vector v = ray.GetDirection();
	float A = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
    float Bx = v.x * (q.x - origin.x);
    float By = v.y * (q.y - origin.y);
    float Bz = v.z * (q.z - origin.z);
    float B = 2 * (Bx + By + Bz);
    float C = pow(q.x - origin.x, 2) + pow(q.y - origin.y, 2) + pow(q.z - origin.z, 2) - pow(radius, 2);

    //Determines if we have a 'hit'
    float discriminant = pow(B, 2) - (4 * A * C);

    if (discriminant >= 0.f)
    {
        //Calculate our t values
        float root = sqrt(discriminant);
        float t1 = (-B + root) / (2 * A);
        float t2 = (-B - root) / (2 * A);
        float d = t1;
        if (t1 > t2 && t2 > 0) //Make sure we don't take a negative 
            d = t2; //Choose the smaller (closer) of the 2 values.

        if (d >= 0) //We want a positive distance from the starting vector
        {
            return d;
        }
    }

    return -1.0f;
}

Vector Sphere::GetNormal(Vector point)
{
    Vector normal = point - origin;
    normal.Normalize();

    return normal;
}