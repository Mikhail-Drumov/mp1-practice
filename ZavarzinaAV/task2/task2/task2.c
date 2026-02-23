#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int k, a, n, count = 0, l = 1, h = 1000, guess;
	char r = 0;

	setlocale(LC_ALL, "");
	srand((unsigned int)time(0));

	printf("Выберете режим 1-вы угадываете число, 2-компьютер угадывает число\n");
	scanf_s("%d", &k);

	if (k == 1) {	
		a = rand() % 1000 + 1;
		printf("случайное число от 1 до 1000\n");

		for (count = 1; ; count++) {
			printf("попытка: %d\n", count);
			scanf_s("%d", &n);

			if (n < a) {
				printf("Загаданное число больше\n");
			}

			else if (n > a) {
				printf("Загаданное число меньше\n");
			}

			else {
				printf("угадали за %d попыток\n", count);
				break;
			}
		}
		return 0;
	}

	if (k == 2) {

		while (l <= h) {
			guess = l + (h - l) / 2;
			count++;

			printf("попытка: %d \n", count);
			printf("%d\n", guess);
			printf("Оценка >, <, = : \n");
			scanf_s("%*c%c", &r);

			if (r == '>') {
				l = guess + 1;
			}

			else if (r == '<') {
				h = guess - 1;
			}

			else if (r == '=') {
				printf("Угадал! За %d попыток", count);
				break;
			}
		}
		return 0;
	}
	return 0;
}


/*#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");

	int l = 1, h = 1000, count=0, guess, i;
	char r = 0;

	while(l <= h){
		guess = l + (h - l) / 2;
		count++;

		printf("попытка: %d \n", count);
		printf("%d\n", guess);
		printf("Оценка >, <, = : \n");
		scanf_s(" %c", &r);

		if (r == '>') {
			l = guess + 1;
		}

		else if (r == '<') {
			h = guess - 1;
		}

		else if (r == '=') {
			printf("Угадал! За %d попыток", count);
			break;
		}
	}
	return 0;
}
*/		

	