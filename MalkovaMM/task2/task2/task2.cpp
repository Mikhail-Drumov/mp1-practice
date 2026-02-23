#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int z, n = 0, s=1, f=1000, cnt = 0;
    int u;
    char ans;
    srand((unsigned int)time(0));
    do
    {
        printf("¬ыберите режим: 1 - вы угадываете число, 2 - вы загадываете число: \n");
        scanf_s("%d", &n);
    } while ((n != 1) && (n != 2));
    if (n == 1)
    {
        cnt = 0;
        z = rand() % (1000 - 1 + 1) + 1;
        do
        {
            cnt++;
            printf("”гадайте число от 1 до 1000: \n");
            scanf_s("%d", &u);
            if (u > z) {
                printf("загаданное число меньше \n");
            }
            else if (u < z) {
                printf("загаданное число больше \n");
            }
        } while (u != z);
        printf("угадали за %d попыток", cnt);
        return 0;
    }
    else
    {
        cnt = 0;
        do
        {
            printf("«агадайте число от 1 до 1000: \n");
            scanf_s("%d", &z);
        } while ((z < 1) || (z > 1000));
        printf("ѕрограмма будет угадывать число, отвечайте > , < или = \n");
        do
        {
            cnt++;
            u = rand() % (f - s + 1) + s;
            printf("%d\n", u);
            scanf_s(" %c", &ans);
            if (ans == '>') {
                s = u + 1;
            } else if (ans == '<') {
                f = u - 1;
            }

        } while (ans != '=');
        printf("угадано за %d попыток", cnt);
        return 0;
    }
    return 0;
}