//190 80 50 - 62.434998
//195 100 70 - 96.000
//200 90 55 - 80.381256
#include <stdio.h>
int main() {
    float m_zadn, m_bok, m_crysh, m_dver, m_polki, Ro_DVP, Ro_DSP, Ro_der, t_DVP, t_DSP, t_der;
    float h, w, d;
    t_DVP = 0.5f;
    t_DSP = 1.5f;
    t_der = 1.f;
    Ro_DVP = 0.000735f;
    Ro_DSP = 0.0008f;
    Ro_der = 0.0007f;

    do
    {
        printf_s("Vvedite vysotu h d cm ");
        scanf_s("%f", &h);
    } while (h > 220.f || h < 180.f);

    do   
    {   
        printf_s("Vvedite shirinu w v cm ");
        scanf_s("%f", &w);
    } while (w > 120.f || w < 80.f);

    do
    {
        printf_s("VVedite glubinu d v cm ");
        scanf_s("%f", &d);
    } while (d > 90.f || d < 50.f);
    
    m_zadn = (h + t_DSP*2.f) * w * t_DVP * Ro_DVP;
    m_bok = h * d * t_DSP * 2.f * Ro_DSP;
    m_crysh = w * d * t_DSP * 2.f * Ro_DSP;
    m_dver = (h + 2.f*t_DSP) * w * t_der * Ro_der;
    m_polki = t_DSP * (w - 2.f*t_DSP) * d * ((((int) h) / 40) - 1)* Ro_DSP;
	

    printf_s("Massa shkafa = %f", m_zadn + m_bok + m_crysh + m_dver + m_polki);
    return 0;
}