#include <stdio.h>
#include <locale.h>
int main()
{
	float m, wPol, w, h, tDvp = 0.5f, tDsp = 1.5f, tDer = 1.0f, d; //в см
	float pDer = 0.7f, pDsp = 0.8f, pDvp = 0.735f; //в г/см3
	int cPol;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("¬ведите высоту(180-220см), ширину(80-120см), глубину(50-90см): ");
		scanf_s("%f %f %f", &h, &w, &d);
	} while ((h < 180.f || h > 220.f) || (w < 80.f || w > 120.f) || (d < 50.f || d > 90.f));
	if (((int)h % 40) == 0)
	{
		cPol = (h / 40) - 1;
	}
	else
	{
		cPol = h / 40;
		cPol = (int)cPol;
	}
	wPol = w - 2.f * tDsp;
	m = (pDvp * (h * w * tDvp)) + (pDsp * h * d * tDsp * 2.f) + (pDsp * (w-2.f*tDsp) * d * tDsp * 2.f) + (pDer * h * w * tDer) + (pDsp * d * wPol * tDsp * cPol);
	//   задн€€ стенка              боковины                       крышки                                двери                        полки
	printf("ћасса шкафа = %f кг", m/1000.f);
	return 0;
}