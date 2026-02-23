#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

	setlocale(LC_ALL, "");
	float x1, y1, r1, x2, y2, r2;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

	if (r1 <= 0 || r2 <= 0) {
		printf("некорректные данные");
		return 0;
	}

	if (r1 == r2 && x1 == x2 && y1 == y2) {
		printf("окружности совпадают");
		return 0;
	}

	if (x1 == x2 && y1 == y2 && r1 != r2) {
		printf("центры совпадают");
		return 0;
	}

	float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ( r1>(d+r2)) {
		printf("одна внутри другой");
		return 0;
	}
	if ( r2>(d+r1)) {
		printf("одна внутри другой");
		return 0;
	}

	if (r2==(d+r1)) {
		printf("внутреннее касание");
		return 0;
	}
	if (r1 ==(d+r2)) {
		printf("внутреннее касание");
		return 0;
	}

	if (d == (r1 + r2)) {
		printf("внешнее касание");
		return 0;
	}

	if (d > (r1 + r2)) {
		printf("общих точек нет");
		return 0;
	}
		printf("окружности пересекаюся");
		return 0;
}