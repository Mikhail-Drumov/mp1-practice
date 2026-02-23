#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float raznost_radiusov, R_center, centrX1, centrX2, centrY1, centrY2, r1, r2;
	setlocale(LC_ALL, "Russian");
	printf("Центр1 (x y), Центр2 (x y), радиус1, радиус2\n");
	scanf_s("%f %f %f %f %f %f", &centrX1, &centrY1, &centrX2, &centrY2, &r1, &r2);
	R_center = sqrtf((centrX2 - centrX1) * (centrX2 - centrX1) + (centrY2 - centrY1) * (centrY2 - centrY1));
	if (r1 > r2)
		raznost_radiusov = r1 - r2;
	else
		raznost_radiusov = r2 - r1;
	if (R_center == 0 && r1 == r2)
		printf("Окружности совпадают\n");
	else if (R_center > r1 + r2)
		printf("Окружности не пересекаются\n");
	else if (R_center == r1 + r2)
		printf("Окружности касаются в 1-ой точке\n");
	else if (R_center > raznost_radiusov && R_center < r1 + r2)
		printf("Окружности пересекаются в двух точках\n");
	else if (R_center == raznost_radiusov && R_center > 0)
		printf("Одна окружность находится внутри другой и касаются изнутри\n");
	else if (R_center < raznost_radiusov)
		printf("Одна окружность находится внутри другой и не касаются изнутри\n");
	return 0;
}