#include "Shading.h"
#include <cmath>
#include <3ds.h>
#include <stdio.h>
Color Shading::GetPhong(Light* light, Ray ray, Vector Q, Vector eye, Object* object)
{
	Color color;
    color.r = 0;
    color.g = 0;
    color.b = 0;

    //Generate necessary vectors
    Vector N = object->GetNormal(Q);
    Vector L = light->GetOrigin() - Q;
    L.Normalize();
    /*Vector toeye = eye - Q;
    toeye.Normalize();*/

    //Calculate the reflection vector
    //Ray reflection = Ray::GetReflectedRay(ray, Q, N);

    float diffuse = Vector::Dot(N, L);

    if (diffuse > 0.f) //Only shade if positive
    {
        //Add diffuse term to color
        color.r = diffuse * object->GetDiffuse().r * light->GetDiffuse().r;
        color.g = diffuse * object->GetDiffuse().g * light->GetDiffuse().g;
        color.b = diffuse * object->GetDiffuse().b * light->GetDiffuse().b;
    }

    //Calculate our specular term
    /*float specular = Vector::Dot(reflection.GetDirection(), toeye);
    if (specular < 0.f)
    {
        specular = pow(specular, 15); //TODO: shineness);
        //Add specular term to color
        color.r += specular * object->GetSpecular().r * light->GetSpecular().r;
        color.g += specular * object->GetSpecular().g * light->GetSpecular().g;
        color.b += specular * object->GetSpecular().b * light->GetSpecular().b;
    }*/

    return color;
}