#include <stdio.h>

int main() {
    float h, w, d, h_m, w_m, d_m, wall_dvp, mass_wall, sidewall_dsp, mass_sidewalls,
		cap_dsp, mass_caps, door_wood, mass_doors, shelf_dsp, mass_shelves, total_mass;
	int count_shelf_dsp;
    float dsp = 735.f, dvp = 800.f, wood = 700.f, s1 = 0.005f, s2 = 0.015f, s3 = 0.01f;
    do {
        scanf_s("%f %f %f", &h, &w, &d);
    } while (h <= 180.f || h >= 220.f || w <= 80.f || w >= 120.f || d <= 50.f || d >= 90.f);
    // перевод в метры
    h_m = h / 100.0f;
    w_m = w / 100.0f;
    d_m = d / 100.0f;

    wall_dvp = h_m * w_m * s1; // задняя стенка
    mass_wall = wall_dvp * dvp;

    sidewall_dsp = h_m * d_m * s2; // 2 боковины
    mass_sidewalls = 2.f * sidewall_dsp * dsp;

    cap_dsp = w_m * d_m * s2; // 2 крышки
    mass_caps = 2.f * cap_dsp * dsp;

    door_wood = h_m * w_m * s3; // 2 двери 
    mass_doors = door_wood * wood;

    count_shelf_dsp = (int)(h_m * 100) / 40; // полки
	count_shelf_dsp = ((int)(h_m * 100) % 40 != 0) ? count_shelf_dsp : count_shelf_dsp - 1; // полки
    shelf_dsp = (w_m - 2.f * s2) * d_m * s2;
    mass_shelves = count_shelf_dsp * shelf_dsp * dsp;

    total_mass = mass_wall + mass_sidewalls + mass_caps + mass_doors + mass_shelves;
    printf("%f", total_mass);
    return 0;
}