#include "Object.h"

Vector Object::GetOrigin()
{
	return this->origin;
}

Color Object::GetDiffuse()
{
	return this->diffuse;
}

Color Object::GetSpecular()
{
	return this->specular;
}

void Object::SetOrigin(Vector origin)
{
	this->origin = origin;
}

void Object::SetDiffuse(Color diffuse)
{
	this->diffuse = diffuse;
}

void Object::SetSpecular(Color specular)
{
	this->specular = specular;
}

Color Object::GetAmbient()
{
	return ambient;
}

float Object::GetShineness()
{
	return shineness;
}

float Object::GetReflectance()
{
	return reflectance;
}

void Object::SetAmbient(Color ambient)
{
	this->ambient = ambient;
}

void Object::SetShineness(float shineness)
{
	this->shineness = shineness;
}

void Object::SetReflectance(float reflectance)
{
	this->reflectance = reflectance;
}
