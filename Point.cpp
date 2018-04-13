#include "stdafx.h"
#include "Point.h"

Point::Point(float x, float y, float z) : x{x}, y{y}, z{z} {}

float Point::getDistance(Point& other) {
	return sqrt(pow(this->x - other.x, 2) +
		        pow(this->y - other.y, 2) + 
		        pow(this->z - other.z, 2));
}

bool Point::inSphere(vector<Sphere>& spheres) {
	int n = spheres.size();
	for (int i = 0; i < n; i++) {
		Point center(spheres[i].x, spheres[i].y, spheres[i].z);
		float distance = this->getDistance(center);
		if (distance < spheres[i].r) {
			return true;
		}
	}
	return false;
}