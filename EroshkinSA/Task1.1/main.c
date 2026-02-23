#include <stdio.h>

int main() {
	float h, w, d, dsp = 1.5f, dvp = 0.5f, tree = 1.0f,
		v_back, v_roofs, v_sides, v_shelfs = 0, v_doors,
		m_dsp, m_dvp, m_tree, m, current_height = 0;
	float density_dsp = 800 / 1e6, density_dvp = 735 / 1e6, density_tree = 700 / 1e6;
	int cnt = 0;
	do {
		scanf_s("%f %f %f", &h, &w, &d);
	} while (h < 180.f || h > 210.f || w < 80.f || w > 120.f || d < 50.f || d > 90.f);
	v_back = (h + 3.0f) * w * dvp;
	v_roofs = 2.f * h * d * dsp;
	v_sides = 2.f * w * d * dsp;
	while (current_height + 41.5f <= h) {
		v_shelfs += (w - 3.f) * d * dsp;
		cnt++;
		current_height += 41.5f;
	}
	v_doors = w * h * tree;
	m_dvp = v_back * density_dvp;
	m_dsp = (v_roofs + v_sides + v_shelfs) * density_dsp;
	m_tree = v_doors * density_tree;
	m = m_dvp + m_dsp + m_tree;
	printf("Number of shelfs = %d\n", cnt);
	printf("Mass of the closet = %f kg", m);
	return 0;
}
