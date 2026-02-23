#include <stdio.h>
int main() {
  int i=0;
  int max = -1;
  float weight;
  float h;
  float w;
  float d;
  float thick_back_wall = 0.5f;
  float thick_side_wall = 1.5f;
  float thick_lid = 1.5f;
  float thick_door = 1.0f;
  float thick_shelf = 1.5f;
  float dens_dsp = 0.8f;
  float dens_dvp = 0.735f;
  float dens_oak = 0.7f;
  do {
    scanf_s("%f", &h);
  } while (h<180.0f||h>220.0f);
  do {
    scanf_s("%f", &w);
  } while (w < 80.0f || w>120.0f);
  do {
    scanf_s("%f", &d);
  } while (d < 50.0f || d>90.0f);
  i = 0;
  float tmp = 0.0;
  while (h > tmp) {
    i++;
    tmp += thick_shelf + 40.0f;
  }
  i--;
  printf("%d\n", i);
  weight = (dens_dvp * h * w * thick_back_wall + dens_dsp * 2.f * (h * d * thick_side_wall +
    w * d * thick_lid) + dens_oak * w * h * thick_door + dens_dsp * i * thick_side_wall * d * (w - thick_side_wall*2.f))/1000.f;
  printf("weight_cabinet=%f", weight);
  return 0;
}