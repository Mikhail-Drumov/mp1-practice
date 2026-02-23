#include <stdio.h>
#include <math.h>


int main() {
	float x1, y1, x2, y2, radius1, radius2, distance;
	scanf_s("%f %f %f", &x1, &y1, &radius1);
	scanf_s("%f %f %f", &x2, &y2, &radius2);
	// Корректность ввода
	if (radius1 <= 0 || radius2 <= 0) {
		printf("Okruzhnost' ne mozhet imet otrizatel'nyi ili nulevoi radius");
		return 1;
	}
	distance = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (x1 == x2 && y1 == y2 && radius1 == radius2) {
		printf("Okruzhnosti sovpadayut");
		return 0;
	}
	if (distance < fabs(radius1 - radius2)) {
		printf("Okruzhnost polnost'yu lezhit v drugoi");
		return 0;
		//0 0 5 and 1 0 1
	}
	if (distance == fabs(radius1 - radius2)) {
		printf("Okruzhnosti vnutrenne kasayutsya");
		return 0;
		// 0 0 5 and 2 0 3
	}
	if (distance == radius1 + radius2) {
		printf("Okruzhnosti kasayutsya vneshne");
		return 0;
		// 0 0 5 and 8 0 3
	}
	if ( (distance < radius1 + radius2) ||  (distance > fabs(radius1 - radius2)) ) {
		printf("Okruzhnosti peresekaytsya");
		return 0;
		// 0 0 5 and 3 0 4
		// 0 0 5 and 4 4 5
	}
	if (distance > radius1 + radius2) {
		printf("Okruzhnosti ne peresekayutsya");
		return 0;
		// 0 0 5 and 6 0 3
	}
	return 0;
}