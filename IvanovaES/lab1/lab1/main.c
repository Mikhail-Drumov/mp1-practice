#include <locale.h>
#include <stdio.h>
#include <math.h>

int main() {
	float r1, r2, x1, y1, x2, y2, rast;
	setlocale(LC_ALL, "RUS");
	scanf_s("%f %f %f %f %f %f", &r1, &r2, &x1, &y1, &x2, &y2);
	if (r1 <= 0 | r2 <= 0)
	{
		printf("Радиусы не могут быть отрицательными");
		return 1;
	}
	rast = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (rast > (r1 + r2))
	{
		printf("Окружности не имеют общих точек");
		return 0;
	}
	if ((rast < (r1 + r2)) && rast != 0 && rast != fabs(r1 - r2))
	{
		printf("Окружности имеют две общие точки");
		return 0;
	}
	if (rast == 0 && (r1 == r2))
	{
		printf("Окружности совпадают");
		return 0;
	}
	if (rast == fabs(r1 - r2) && rast != 0)
	{
		printf("Окружности касаются внутренним образом");
		return 0;
	}
	printf("Окружности касаются внешним образом");
	return 0;
}