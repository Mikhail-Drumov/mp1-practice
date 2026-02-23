#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	double x1, y1, r1;
	double x2, y2, r2;
	double distance;
	setlocale(LC_ALL, "RU");

	printf("Введите координаты x1 и y1 и радиус r1: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);

	printf("Введите координаты x2 и y2 и радиус r2: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);

	if (r1 < 0 || r2 < 0) {
		printf("Радиусы должны быть положительными");
		return 1;
	}//0 0 -1; 0 0 1

	distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	if (distance > r1 + r2) {
		printf("Окружности не пересекаются\n");
	}//0 0 1; 200 0 1
	else if (distance < fabs(r1 - r2)) {
		printf("Одна окружность внутри другой\n");
	}//0 0 10; 0 0 5
	else if (distance == 0 && r1 == r2) {
		printf("Окружности совпадают\n");
	}//0 0 1; 0 0 1

	else if (distance == r1 + r2 || distance == fabs(r1 - r2)) {
		printf("Окружности имеют одну точку касания\n");
	}//0 0 3; 2 0 1

	else {
		printf("Окружности пересекаются\n");
	}//0 0 3; 2 2 3
	return 0;
}