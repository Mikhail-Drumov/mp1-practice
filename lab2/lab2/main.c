#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int r, count = 0, chr, chp,chmin=1,chmax=1000;
	char c;
	printf("Выбери режим 1-угадывай, 2-загадывай:");
	scanf_s("%d", &r);
	if (r == 1) {
		srand((unsigned int)time(0));
		chr = rand() % (1000) + 1;
		printf("Пиши отгадки:");
		do {
			scanf_s("%d", &chp);
			if (chp > 1000 || chp < 1) {
				printf("Число должно быть от 1 до 1000\n");
			}
			else if (chp < chr) {
				printf("Загаданное число больше\n");
				count += 1;
			}
			else if (chp > chr) {
				printf("Загаданное число меньше\n");
				count += 1;
			}
		} while (chp != chr);
		printf("Угадал с %d-ой попытки", count + 1);

	}
	if (r == 2) {
		printf("Загадай число от 1 до 1000\n");

		do {
			chr = (chmax + chmin) / 2;
			printf("%d\n", chr);
			printf("Введи символ >,<,=:");
			scanf_s(" %c", &c);

			if (c == '>') {
				chmin = chr + 1;
				count++;
			}

			if (c == '<') {
				chmax = chr - 1;
				count ++;
			}
			if (c == '=') {
				printf("Компьютер угадал с %d-ой попытки", count+1);
				return 0;
			}
			if (c != '>' && c != '<' && c != '=') {
				printf("Неверный символ\n");
			}
			
		} while (chmin <= chmax);
		printf("Вы где-то ошиблись");
		return 1;
	}
	return 0;
}
	