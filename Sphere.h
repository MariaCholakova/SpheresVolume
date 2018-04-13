#pragma once
#ifndef SPHERE_H
#define SPHERE_H

struct Sphere {
	float x = 0;
	float y = 0;
	float z = 0;
	float r = 0;

	Sphere(){}
	Sphere(float x, float y, float z, float r) : x{ x }, y{ y }, z{ z }, r{ r } {};
};

#endif // !SPHERE_H

