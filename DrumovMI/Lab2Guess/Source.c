#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int cnt = 0, type, t;
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	printf("Выберите режим (1 - программа загадывает, пользователь отгадывает, "
		"2 - пользователь загадывает, компьютер отгадывает): ");
	do {
		t = scanf("%d", &type);
	} while ((t == 0) || (t == 1 && !(type == 1 || type == 2)));

	if (type == 1) {
		int x = 1 + (rand()) % (1000 - 1 + 1);
		int guess;
		while (true) {
			printf("Ваша догадка: ");
			t = scanf("%d", &guess);
			cnt++;
			if (guess < x)
				printf("Загаданное число больше.\n");
			else if (guess > x)
				printf("Загаданное число меньше.\n");
			else {
				printf("Угадали.\n");
				break;
			}
		}
	}
	else {
		int l = 1, r = 1000;
		while (l <= r) {
			int c = l + (r - l) / 2;

			char ch;
			printf("Догадка программы - %d. "
				"Ваше число меньше(<), больше(>) или равно(=) "
				"угаданному программой числу? ", c);
			cnt++;

			do {
				scanf("%c", &ch);
			} while (ch != '<' && ch != '=' && ch != '>');

			if (ch == '=') { printf("Угадано число %d\n", c); break; }
			else if (ch == '>') l = c + 1;
			else r = c - 1;
		}
	}

	printf("Кол-во сравнений: %d\n", cnt);
	system("chcp 866");
	return 0;
}