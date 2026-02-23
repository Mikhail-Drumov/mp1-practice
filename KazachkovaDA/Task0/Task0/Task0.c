//2.7 -2.8 3.9 2.8 1 -0.6 - Okruzhnosti ne imeut obschih tochek
//2.7 -2.8 3.9 0.6 -3.1 3 - Odna okruzhnost lezhit vnutri drugoi i oni ne imeut obschih tochek
//4 -2 2 2 -2 4 - Okruzhnosti kasautsya vnutrennim obrazom
//2.3 -5.5 -4.8 2 -2.7 -3.1 - Okruzhnosti peresekautsya v dvuh tochkah
//3 -8 -4 1 -8 0 - Okruzhnosti kasautsya
#include <stdio.h>
#include <math.h>
int main() {
	float r1, r2, x1, x2, y1, y2, d;

	printf_s("Radius pervoi okruzhnosti = ");
	scanf_s("%f", &r1);

	printf_s("Koordinata 'x' centra pervoi okruzhnosti = ");
	scanf_s("%f", &x1);

	printf_s("Koordinaya 'y' centra pervoi okruzhnosti = ");
	scanf_s("%f", &y1);
	
	printf_s("Radius vtoroi okruzhnosti = ");
	scanf_s("%f", &r2);

	printf_s("Koordinata 'x' centra vtoroi okruzhnosti = ");
	scanf_s("%f", &x2);

	printf_s("Koordinata 'y' centra vtoroi okruzhnosti = ");
	scanf_s("%f", &y2);

	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (r1 <= 0 || r2 <= 0)
	{
		printf_s("The radius must be >0");
		return 1;
	}

	if (d == abs(r1 - r2))
	{
		printf_s("Okruzhnosti kasautsya vnutrennim obrazom");
		return 0;
	}

	if (d == r1 + r2)
	{
		printf_s("Okruzhnosti kasautsya");
		return 0;
	}
	
	if ((abs(r1 - r2) < d) && ((r1 + r2) > d))
	{
		printf_s("Okruzhnosti peresekautsya v dvuh tochkah");
		return 0;
	}
	
	if (d < abs(r1 - r2))
	{
		printf_s("Odna okruzhnost lezhit vnutri drugoi i oni ne imeut obschih tochek");
		return 0;
	}

	printf_s("Okruzhnosti ne imeut obschih tochek");
	return 0;

}