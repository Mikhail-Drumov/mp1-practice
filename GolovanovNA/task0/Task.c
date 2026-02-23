#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, r1, x2, y2, r2, d;
	scanf_s("%f%f%f%f%f%f", &x1, &y1, &r1, &x2, &y2, &r2);
	if (r1 <= 0 || r2 <= 0) {
		printf("bad input");
		return 0;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2) {
		printf("same");
		return 0;
	}
	if (x1 == x2 && y1 == y2) {
		printf("oniconcentriceskie");
		return 0;
	}
	d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 + r2 < d) {
		printf("ne peresek. snaruzh");
		return 0;
	}
	if (r1 + r2 == d) {
		printf("1 peres. snaruzh");
		return 0;
	}
	if (d < fabs(r1 - r2)) {
		printf("ne peres. vnutri");
		return 0;
	}
	if (d == fabs(r1 - r2)) {
		printf("1 peres. vnutri");
		return 0;
	}
	printf("2 peres");
	return 0;
}
