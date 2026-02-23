#include <stdio.h>
#define density_dvp 0.735f
#define density_dsp 0.8f
#define density_wood 0.7f

int main()
{
	float h, w, d;
	float weight_back, weight_side, weight_doors, weight_top, weight_shelf;
	printf("Input height, width, depth:\n");
	scanf_s("%f%f%f", &h, &w, &d);
	while (h < 180.0f || h > 220.0f || w < 80.0f || w > 120.0f || d < 50.0f || d > 90.0f)
	{
		printf("Incorrect values, try again:\n");
		scanf_s("%f%f%f", &h, &w, &d);
	}
	weight_back = h * w * 0.5f * density_dvp;
	weight_side = h * d * 1.5f * density_dsp;
	weight_doors = h * w * 1.0f * density_wood;
	weight_top = w * (d + 1.5f) * 1.5f * density_dsp;
	weight_shelf = (w - 3.0f) * d * 1.5f * density_dsp;

	printf("The weight of the closet is %.2f kg", (weight_back + 2*weight_side + weight_doors + 2*weight_top + ((int)(h)/40-1)*weight_shelf)/1000.0f);
	return 0;
}