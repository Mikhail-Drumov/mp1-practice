#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	float r1,r2,x1,x2,y1,y2,rast;
	setlocale(LC_ALL, "Russian");

	printf("Введите радиус первой окружности:");
	scanf_s("%f", &r1);
	printf("Введите радиус второй окружности:");
	scanf_s("%f", &r2);
	printf("Введите координаты первой окружности:");
	scanf_s("%f %f", &x1,&y1);
	printf("Введите координаты второй окружности:");
	scanf_s("%f %f", &x2,&y2);
	if ((r1 <= 0) || (r2<=0)){
		printf("некорректные данные");
		return 0;
	}
	rast = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	
	if (rast > r1 + r2) {
		printf("окружности расположены внешним образом и не касаются");
		return 0;
	}
	if (rast == r1 + r2) {
		printf("окружности касаются внешним образом");
		return 0;
	}
	if ((rast > fabsf(r1 - r2)) && (rast < r1 + r2)) {
		printf("окружности пересекаются в 2 точках");
		return 0;
	}
	if ((rast == 0.0) && (r1 == r2)) {
		printf("окружности совпадают(одна окружность)");
		return 0;
	}
	if (rast == fabsf(r1 - r2)) {
		printf("касаются внутренним образом");
		return 0;
	}
	if ((rast < fabsf(r1 - r2))&&(rast!=0.0)) {
		printf("окружности расположены внутренним образом и не касаются(центры не совпадают)");
		return 0;
	}
	printf("окружности расположены внутренним образом и не касаются(центры совпадают)");

	
	return 0;
}