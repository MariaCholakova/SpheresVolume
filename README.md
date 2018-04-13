# SpheresVolume
Monte Carlo algorithm for finding the volume of complex geometry

Task:
Imagine a set of points in 3D space, each creating a sphere-shaped energy field centered on the point and having a certain radius.
We assume that the field is constant everywhere (i.e. with an intensity of 0 or 1). The field does not accumulate energy -
if a point is located in more than one sphere (the spheres can intersect), the intensity at this point is again 1.
Your task is to calculate the volume of the space that has an intensity equal to 1.
The input data is read from the energy.inp file. The first row contains an integer N - the number of points.
There are N lines, each describing one point in the following format:
4 real numbers - the coordinates of the given point and the radius of the field it creates.
You must output a single number to the standard output - the sum of the energy field, rounded to 3 digits after the comma.

