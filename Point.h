#pragma once
#ifndef POINT_H
#define POINT_H
#include "Sphere.h"
#include <vector>
using namespace std;

struct Point {
	float x = 0;
	float y = 0;
	float z = 0;

	Point(){}
	Point(float x, float y, float z);
	bool inSphere(vector<Sphere>& spheres);

	private:
	float getDistance(Point& other);
};

#endif // !POINT_H

