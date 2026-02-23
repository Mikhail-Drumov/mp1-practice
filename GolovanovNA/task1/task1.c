#include <stdio.h>
#include <math.h>
#define dvp 0.735F
#define dsp 0.8F
#define drv 0.7F

int main() {
	float h, w, d, sten, bok, krsh, dw, plk;
	scanf_s("%f%f%f", &h, &w, &d);
	sten = h * w * 0.5F * dvp;
	bok = 2.0F * h * d * 1.5F * dsp;
	krsh = (2.0F * w * d * 1.5F *dsp);
	dw = (h * w * drv);
	plk = 1.5F * (w - 3.0F) * d * (h / 40.0F - 1) * dsp;
	printf("%f", (sten + bok + krsh + dw + plk) / 1000.0F);
	return 0;
}