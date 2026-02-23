#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int rasn(int, int);

int main()
{
	int n, bk, kr, z, u = 0, mz[5], mu[5], i, j, f, z1;
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	do
	{
		printf("Выберите длину загаданного числа n от 2 до 5: ");
		scanf_s("%d", &n);
	} while (n < 2 || n>5);
	if (n == 2)
		do {
			z = rand() % (99 - 10 + 1) + 10;
		} while (rasn(z, 2) == 0);
	else if (n == 3)
		do {
			z = rand() % (999 - 100 + 1) + 100;
		} while (rasn(z, 3) == 0);
	else if (n == 4)
		do {
			z = rand() % (9999 - 1000 + 1) + 1000;
		} while (rasn(z, 4) == 0);
	else if (n == 5)
		do {
			z = rand() % (99999 - 10000 + 1) + 10000;
		} while (rasn(z, 5) == 0);
	z1 = z;
	i = 0;
	while (z1 > 0)
	{
		mz[n-i-1] = z1 % 10;
		z1 = z1 / 10;
		i++;
	}
	int n1 = 0;
	i = 0;
	do
	{
		printf("Введите число с неповторяющимися цифрами длиной %d знаков: ", n);
		i = 0;
		do
		{
			n1 = 0;
			scanf_s("%d", &u);
			int u1 = u;
			while (u1 > 0)
			{
				n1 += 1;
				mu[n - i - 1] = u1 % 10;
				u1 = u1 / 10;
				i++;
			}

		} while (n1 != n || rasn(u, n) == 0);
		bk = 0;
		kr = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (mu[i] == mz[j]) {
					if (i == j)
						bk++;
					else
						kr++;
				}
			}
		}
		printf("быков %d, коров %d \n", bk, kr);
	} while (bk != n);
	printf("Вы угадали!!!!!!");
	return 0;
}
int rasn(int z, int l) 
{
	int m[5], i, j;
	int itog = 1;
	int z1 = z;
	for (i = 0; i < l; i++) {
		m[i] = z1 % 10;
		z1 = z1 / 10;
	}
	for (i = 0; i < l; i++) {
		for (j = 0; j < i; j++) {
			if (m[i] == m[j]) {
				itog = 0;
				break;
			}
		}
		if (itog == 0)
		{
			break;
		}
	}
	return itog;
}
