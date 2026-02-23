#include <stdio.h>
#define N 1000
#include <locale.h>
#include <time.h>


int main() {
	int n, r, step = 10, i, j, tx[10], ty[10];
	int check = 1, bull, cows, x, y;
	x = 0;
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(0));
	printf("Привет! Это игра <Быки и коровы>. Правила просты:\nЯ загадываю число, ты пытаешься его угадать\n");
	do {
		printf("Введите n. Причем: 2<=n<=5\n");
		scanf_s("%d", &n);
	} while (n < 2 || n>5);

	do {
		check = 1;
		for (i = 0; i < n; i++) {
			r = rand() % step;
			tx[i] = r;
		}
		for (i = 0; i < n; i++) {
			for (j = i + 1; j < n; j++) {
				if (tx[i] == tx[j]) {
					check = 0;
					break;
				}
			}
		}
		if (tx[0] == 0) tx[0]=1;
		if (check == 1) {
			x = 0;
			for (int i = 0; i < n; i++)
				x = (x + tx[i]) * 10;
			x = x / 10;
		}
	} while (check != 1);

	printf("X=%d\n", x);
	i = 0; step = 1;

	while (i < n) {
		i++;
		step = step * 10;
	}
	step = step / 10;
	
	do {
		cows = 0;
		bull = 0;
		do {
			check = 1;
			printf("Попробуйте отгадать мое число! Оно состоит из %d знаков!\n", n);
			scanf_s("%d", &r);
			y = r;
			if (y / step < 1 || y / step > 10) {
				printf("Количество знаков не совпадает\n");
				check = -1;
			}
			for (i = n-1; i >= 0; i--) {
				ty[i] = r % 10;
				r = r / 10;
			}
			if (check != -1) {
				for (i = 0; i < n; i++) {
					for (j = i + 1; j < n;j++) {
						if (ty[i] == ty[j])
							check = -2;
					}
				}
			}
			if (check == -2) {
				printf("Числа должны быть разные!\n");
			}
		} while (check != 1);
		check = -1;
		for (i = 0; i < n;i++) {
			if (tx[i] == ty[i]) {
				bull++;
			}
			for (j = 0; j < i; j++) {
				if (tx[i] == ty[j]) {
					cows++;
				}
			}
			for (j = i + 1; j < n; j++) {
				if (tx[i] == ty[j]) {
					cows++;
				}
			}
		}
		printf("Количество коров %d\nКоличество быков %d\n", cows, bull);
	} while (bull != n);
	printf("Ура! Вы правы! Загаданное число %d\n", x);
	return 0;
}