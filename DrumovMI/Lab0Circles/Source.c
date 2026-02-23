#include <stdio.h>
#include <locale.h>
#include <math.h>

#define EPS (1e-9f)
#define LINE 512

/* TESTS:
 1) IN: 0 0 0 0 -1 -1
    IN: 1 -2 3 -4 0 0
    IN: 123 323 29 8 0 -1
   EXP: Радиус должен быть положительным
 2) IN: 1 2 1 2 3 3
    IN: 2 2 2 2 1 1
	IN: 3 -1 3 -1 10 10
   EXP: Окружности совпадают
 3) IN: 0 0 100 100 5 5
    IN: 0 0 100 0 50 49.9
	IN: -10 -10 10 10 10 10
	IN: 0 0 0.1 0 0.001 0.001
   EXP: Окружности не пересекаются
 4) IN: 0 0 10 0 5 5
    IN: 0 0 2 0 1 1
	IN: -2.5 0 2.5 0 2.5 2.5
    IN: 0 0 1 1 0.70710678118 0.70710678118
   EXP: Окружности касаются внешне
 5) IN: 0 0 0.5 0 1 0.5
    IN: 0 0 0.5 0.5 1.4142135623 0.70710678118
	IN: 0 0 0 2 4 2
   EXP: Окружности касаются внутренне
 6) IN: 1 1 2 2 5 5
    IN: -10 2 -10 5 10 10
	IN: -2 -2 2 2 100 100
   EXP: Окружности пересекаются
 7) IN: 0 0 0 0 5 6
    IN: 10 10 2 2 100 1
	IN: -100 -100 100 100 10000000 1
   EXP: Одна окружность находится внутри другой
*/


int main() {
	float x0, y0, x1, y1, r0, r1;
	setlocale(LC_ALL, "rus");
	setlocale(LC_NUMERIC, "C");

	printf("Введите x0, y0, x1, y1, r1, r2:\n");

	char line[LINE];
	fgets(line, LINE, stdin);
	sscanf_s(line, "%f %f %f %f %f %f", &x0, &y0, &x1, &y1, &r0, &r1);

	if (r0 <= 0 || r1 <= 0) {
		printf("Радиус должен быть положительным");
		return 1;
	}

	// to make r0 <= r1
	if (r0 > r1) {
		float t = r0;
		r0 = r1;
		r1 = t;
	}

	float d = sqrtf((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));

	if (x0 == x1 && y0 == y1 && r0 == r1) {
		printf("Окружности совпадают");
	}
	else if (d > r0 + r1) {
		printf("Окружности не пересекаются");
	}
	else if (fabsf(d - (r0 + r1)) < EPS) {
		printf("Окружности касаются внешне");
	}
	else if (fabsf(d - (r1 - r0)) < EPS) {
		printf("Окружности касаются внутренне");
	}
	else if (d + r0 > r1) {
		printf("Окружности пересекаются");
	}
	else if (d + r0 < r1) {
		printf("Одна окружность находится внутри другой");
	}

	return 0;
}