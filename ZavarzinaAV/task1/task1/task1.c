#include<stdio.h>
#include<math.h>
#include<locale.h>

int main() {
	setlocale(LC_ALL, "");
	float h_cm, w_cm, d_cm;//см

	float th_dvp = 0.005f;//мм в м
	float th_dsp = 0.015f;
	float th_wood = 0.01f;

	float p_dvp = 735.0f;  //кг/м^3
	float p_dsp = 800.0f;
	float p_wood = 700.0f;

	printf("¬ведите высоту h: ");
	scanf_s("%f", &h_cm);
	printf("¬ведите ширину w: ");
	scanf_s("%f", &w_cm);
	printf("¬ведите глубину d: ");
	scanf_s("%f", &d_cm);

	if (h_cm < 180.f || h_cm > 220.f) {
		printf("¬ведите другие параметры");
		return 0;
	}

	if (d_cm < 50.f || d_cm > 90.f) {
		printf("¬ведите другие парметры");
		return 0;
	}

	if (w_cm < 80.f || w_cm > 120.f) {
		printf("¬ведите другие парметры");
		return 0;
	}

	float h = h_cm / 100.f;
	float w = w_cm / 100.f;
	float d = d_cm / 100.f;

	int n_shelves = (int)floor(h_cm / 40.0) - 1;

	float vol_back = w * (h + 2.f * th_dsp) * th_dvp;
	float vol_sides = 2 * (h * d * th_dsp);
	float vol_roof_botton = 2 * (d * w * th_dsp);
	float vol_doors = (h + 2.f * th_dsp) * w * th_wood;
	float vol_shelves = n_shelves * (d * (w - 2.f * th_dsp) * th_dsp);

	float m_back = vol_back * p_dvp;
	float m_sides = vol_sides * p_dsp;
	float m_roof_botton = vol_roof_botton * p_dsp;
	float m_doors = vol_doors * p_wood;
	float m_shelves = vol_shelves * p_dsp;

	float m = m_back + m_sides + m_roof_botton + m_doors + m_shelves;

	printf("ћасса шкафа (кг) = %.2f", m);
	return 0;
}