#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	float x1, y1, r1, x2, y2, r2;
	setlocale(LC_ALL, "Rus");
	printf("¬ведите данные в формате: x1 y1 r1 x2 y2 r2");
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	float rast = sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2));
	if (r1 <= 0 || r2 <= 0)
	{
		printf("Ќекорректные данные");
		return 0;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("ќкружности совпадают");
		return 0;
	}
	if (rast > r1 + r2)
	{
		printf("ќкружности не пересекаютс€ и не лежат друг в друге");
		return 0;
	}
	if (rast == r1 + r2)
	{
		printf("ќкружности внешним образом касаютс€ в одной точке");
		return 0;
	}
	if (rast + r1 < r2)
	{
		printf("ѕерва€ окружность находитс€ внутри второй и они не касаютс€ друг друга");
		return 0;
	}
	if (rast + r2 < r1)
	{
		printf("¬тора€ окружность находитс€ внутри первой и они не касаютс€ друг друга");
		return 0;
	}
	if (rast + r1 == r2)
	{
		printf("ѕерва€ окружность находитс€ внутри второй и они касаютс€ друг друга в одной точке");
		return 0;
	}
	if (rast + r2 == r1)
	{
		printf("¬тора€ окружность находитс€ внутри первой и они касаютс€ друг друга в одной точке");
		return 0;
	}
	printf("ќкружности пересекаютс€ в двух точках");
	return 0;

}