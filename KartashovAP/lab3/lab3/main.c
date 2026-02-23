#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 5

int main() {
	int dlina, bulls, cows, popitok = 0, pol;
	int i, j;
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "Russian");

	//Считывание длины числа от 2 до 5 с проверкой
	do {
		printf("Введите число от 2 до 5\n");
		scanf_s("%d", &dlina);
	} while (dlina < 2 || dlina > 5);

	//Создание массива под генерацию чисел и массива для использованных чисел, загадывание первой цифры  
	int chislo[N] = {0}; 
	int usedch[10] = {0};
	chislo[0] = rand() % 9 + 1;
	usedch[chislo[0]] = 1;

	//Генерация остальных неповторяющихся чисел
	for (i = 1; i < dlina; i++) {
		do {
			chislo[i] = rand() % 10;
		} while (usedch[chislo[i]] == 1);
		usedch[chislo[i]] = 1;
	}

	printf("Введите число для отгадки\n");

	//работа с пользовательским числом, поиск быков и коров до тех пор пока быки не станут равны длине
	do {
		int polm[N] = {0};
		bulls = 0;
		cows = 0;
		popitok += 1;

		scanf_s("%d", &pol);

		for (i = dlina; i > 0; i--) {
			polm[i - 1] = pol % 10;
			pol = pol / 10;
		}

		for (i = 0; i < dlina; i++) {
			if (chislo[i] == polm[i]) {
				bulls += 1;
			}
		}
		for (i = 0; i < dlina; i++) {
			for (j = 0; j < i; j++) {
				if (chislo[i] == polm[j]) {
					cows += 1;
				}
				}
			for ( j = i+1; j < dlina; j++) {
				if (chislo[i] == polm[j]) {
					cows += 1;
				}
			}
		}
		printf("%d быков и %d коров\n", bulls, cows);
		if (bulls != dlina) {
			printf("к сожалению вы не угадали, попробуйте еще раз\n");
		}
	} while (bulls != dlina);


	//Вывод сообщения о победе и колво попыток
	printf("Вы - победитель, %d количество попыток", popitok);

	return 0;
}