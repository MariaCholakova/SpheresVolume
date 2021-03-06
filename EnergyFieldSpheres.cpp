
// EnergyFieldSpheres.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Point.h"
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

bool isValidSymbol(char c) {
	return c >= '0' && c <= '9' || c == '.' || c == ',';
}

bool readFromFile(const char* filename, vector<Sphere>& spheres) {
	ifstream rfile(filename);
	char line[100]; 
	if (rfile.is_open()) {
		rfile.getline(line, 100);
		while (rfile.getline(line, 100)) {
			
			float val[4] = { 0.0, 0.0, 0.0, 0.0 };
			bool neg = false;
			int i = 0;
			int v = 0;		
			while (v < 4) {
				if (line[i] == '-') {
					neg = true;
					i++;
				}
				int point = 0;
				val[v] += line[i++] - '0';
				while (isValidSymbol(line[i])) {
					if (line[i] == '.' || line[i] == ',') {
						point = i;
						i++;
						continue;
					}
					val[v] *= 10;
					val[v] += line[i] - '0';
					i++;
				}
				val[v] /=   pow(10, i - point - 1);
				if (neg) {
					val[v] = -val[v];
				}
				v++; i++;
			}
			Sphere s(val[0], val[1], val[2], val[3]);
			spheres.push_back(s);
		}
		rfile.close();
		return true;
	}
	else {
		printf("Could not open file!\n");
		return false;
	}
}


float* getConstraints(vector<Sphere>& spheres) {
	float minX = spheres[0].x - spheres[0].r;
	float maxX = spheres[0].x + spheres[0].r;
	float minY = spheres[0].y - spheres[0].r;
	float maxY = spheres[0].y + spheres[0].r;
	float minZ = spheres[0].z - spheres[0].r;
	float maxZ = spheres[0].z + spheres[0].r;
	int n = spheres.size();
	for (int i = 1; i < n; i++) {
		if (spheres[i].x - spheres[i].r < minX)
			minX = spheres[i].x - spheres[i].r;
		if (spheres[i].x + spheres[i].r > maxX)
			maxX = spheres[i].x + spheres[i].r;
		if (spheres[i].y - spheres[i].r < minY)
			minY = spheres[i].y - spheres[i].r;
		if (spheres[i].y + spheres[i].r > maxY)
			maxY = spheres[i].y + spheres[i].r;
		if (spheres[i].z - spheres[i].r < minZ)
			minZ = spheres[i].z - spheres[i].r;
		if (spheres[i].z + spheres[i].r > maxZ)
			maxZ = spheres[i].z + spheres[i].r;
	}
	float constraints[6] = { minX, maxX, minY, maxY, minZ, maxZ };
	return constraints;
}

const int POINTS = 1000000;
const float M= 100.0;
float getVolume(vector<Sphere>& spheres) {
	float pointsInSpheres = 0;
	float* constraints = getConstraints(spheres);
	int minX = constraints[0] * M;
	int maxX = constraints[1] * M;
	int minY = constraints[2] * M;
	int maxY = constraints[3] * M;
	int minZ = constraints[4] * M;
	int maxZ = constraints[5] * M;

	srand(time(NULL)); 
	for (int i = 0; i < POINTS; i++) {
		float randX = rand() % maxX + minX;
		randX = randX / M;
		float randY = rand() % maxY + minY;
		randY = randY / M;
		float randZ = rand() % maxZ + minZ;
		randZ = randZ / M;
		Point p(randX, randY, randZ);
		if (p.inSphere(spheres)) {
			pointsInSpheres++;
		}
	}
	return pointsInSpheres/POINTS;
}



int main()
{
	/*Sphere s1(2, 2, 2, 2);
	Sphere s2(4, 3, 3, 1);
	vector<Sphere> vs;
	vs.push_back(s1);
	vs.push_back(s2);
	float v = getVolume(vs);
	printf("volume = %.3f\n", v);*/

	vector<Sphere> vs;
	if (readFromFile("energy.inp", vs)) {
		float v = getVolume(vs);
		printf("volume = %.3f\n", v);
	}
	
    return 0;
}

