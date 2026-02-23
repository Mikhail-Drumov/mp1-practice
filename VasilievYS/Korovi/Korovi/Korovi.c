#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int checkSize(int num, int n)
{
    int cnt = 0;
    while (num > 0)
    {
        cnt++;
        num /= 10;
    }
    if (cnt == n)
    {
        return 1;
    }
    else { return 0; }
}
int main()
{
    int n, used[9] = { 0 }, temp, i, a[5], j = 0;
    int b[5] = { 0 }, num = 0, ans = 0, bull = 0, cow = 0;
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(0));
    do {
        printf("Длина числа(от 2 до 5): ");
        scanf_s("%d", &n);
    } while (n < 2 || n>5);
    a[0] = rand() % 9 + 1;
    num = a[0];
    used[a[0]-1]++;
    for (i = 1; i < n; i++)
    {  
        do
        {
            a[i] = rand() % 9 + 1;
        } while (used[a[i]-1] != 0);
        num = num * 10 + a[i];
        used[a[i]-1]++;
    } 
    do {
        cow = 0;
        bull = 0;
        do
        {
            printf("Ваше число длиной из %d cимволов: ", n);
            scanf_s("%d", &ans);
        } while (checkSize(ans, n) != 1);
        for (i = 0; i < n; i++)
        {
            temp = ans % 10;
            b[n - 1 - i] = temp;
            ans /= 10;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] == a[i])
            {
                bull++;
                continue;
            }
            else
            {
                for (j = 0; j < n; j++)
                {
                    if (b[i] == a[j] && i != j)
                    {
                        cow++;
                        continue;
                    }
                }
            }
        }
        if (bull != n)
        {
            printf("Быков: %d\n", bull);
            printf("Коров: %d\n", cow);
        }
    } while (bull != n);
    printf("Верно");
    return 0;
}