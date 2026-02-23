#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, dist;
	printf("Enter coordinates and radius of 1st circle:\n");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Enter coordinates and radius of 2nd circle:\n");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	if ((r1 < 0) || (r2 < 0)) {
		printf("Radiuses must be non-negative");
		return 1;
	}


	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
		printf("Circles are the same");
		return 0;
	}


	dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


	if ((r1 + r2) < dist) {
		printf("Circles do not intersect");
		return 0;
	}


	if (abs(r1 - r2) == dist) {
		printf("Internal tangency of circles");
		return 0;
	}


	if ((r1 + r2) == dist) {
		printf("External tangency of circles");
		return 0;
	}


	if (dist < abs(r1 - r2)) {
		printf("One circle is inside another");
		return 0;
	}


	printf("Circles intersect each other");
	return 0;
}