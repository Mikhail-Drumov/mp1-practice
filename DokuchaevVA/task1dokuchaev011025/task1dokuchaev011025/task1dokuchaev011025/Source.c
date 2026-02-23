#include <stdio.h>
#include <locale.h>
int main() {
	float h, w, d, massa1, massa2, massa3, massa4, massa5, massa, n;
	float der = 700.f, dsp = 800.f, dvp = 735.f, tder = 10.f, tdsp = 15.f, tdvp = 5.f;
	setlocale(LC_ALL, "Rus");

	do
	{
		printf_s("Введите значение высота шкафа H (в см, 180-220)\n");
		scanf_s("%f", &h);
	} while ((h < 180.f) || (h > 220.f));
	h = h * 10.f;

	do
	{
		printf_s("Введите значение ширины шкафа W (в см, 80-120)\n");
		scanf_s("%f", &w);
	} while ((w < 80.f) || (w > 120.f));
	w = w * 10.f;	

	do
	{
		printf_s("Введите значение глубины шкафа D (в см, 50-90)\n");
		scanf_s("%f", &d);
	} while ((w < 80.f) || (d > 90.f));
	d = d * 10.f;

	n = ((h / 10.f)/40)-1;
	n=(int)n;

	massa1 = (h+30) * tdvp * w * dvp / 1000000000.0f; //масса задней стенки
	massa2 = h * tdsp * d * dsp / 1000000000.0f * 2.f;//боковые стенки
	massa3 = w * d * dsp * tdsp / 1000000000.0f * 2.f;// дно и потолок
	massa4 = w * (h+30) * tder * der / 1000000000.0f;// двери
	massa5 = (w - 2.f*tdsp) * d * dsp * tdsp * n / 1000000000.0f;
	massa = massa1 + massa2 + massa3 + massa4 + massa5;
	printf("Общая масса = %.1f кг\n\n\n", massa);
	printf("Масска задней стенки = %.1f кг\n", massa1);
	printf("Масса боковых стенок = %.1f кг\n", massa2);
	printf("Масса дна и потолка = %.1f кг\n", massa3);
	printf("Масса дверей = %.1f кг\n", massa4);
	printf("Масса полок и их количество= %.1f кг, %.0f\n", massa5, n);
	return 0;
}