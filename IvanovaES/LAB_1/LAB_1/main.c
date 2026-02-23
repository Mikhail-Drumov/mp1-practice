#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float h, w, d;
	float p_dsp = 735.f;
	float p_dvp = 800.f;
	float p_der = 700.f;
	float tol_5 = 0.005f;
	float tol_15 = 0.015f;
	float tol_10 = 0.01f;

	setlocale(LC_ALL, "RUS");
	
	do {
		scanf_s("%f %f %f", &h, &w, &d);
	} while ((h > 220.f || h < 180.f) || (w > 120.f || w < 80.f) || (d > 90.f || d < 50.f));

	int kol_pol;
	if (fmod(h, 40) == 0) {
		kol_pol = (int)((h / 40) - 1);
	}
	else {
		kol_pol = (int)floor(h / 40.f);
	}

	h = h / 100.0f;
	w = w / 100.0f;
	d = d / 100.0f;
	
	float V_zs = h * w * tol_5;
	float V_bok = 2.0f * (h * d * tol_15);
	float V_kr = 2.0f * (w * d * tol_15);
	float V_dv = h * w * tol_10;
	float V_pol = kol_pol * ((w - 2.f * tol_15) * d * tol_15);
    
	float massa = (V_zs * p_dvp) + (V_bok * p_dsp) + (V_kr * p_dsp) + (V_dv * p_der) + (V_pol * p_dsp);

	printf("Масса шкафа = %f", massa);

	return 0;
}