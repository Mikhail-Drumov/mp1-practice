#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int mode, guess, answ, max, min, tries;
	char sign;
	printf_s("Выберите режим игры:\n");
	printf_s("1 - число отгадываете Вы, 2 - число отгадывает компьютер\n");
	do
	{	
		printf_s("Введите режим:");
		scanf_s("%d", &mode);
	} while ((mode <= 0)|| (mode >= 3));

	if (mode == 1)
	{
		tries = 0;
		srand(time(NULL));
		answ = (rand() % 1000) + 1;
		do
		{
			printf_s("Введите догадку:");
			scanf_s("%d", &guess);
			if (guess > answ) 
			{
				printf_s("Загаданное число меньше\n");
				tries += 1;
			}
			if (guess < answ)
			{
				printf_s("Загаданное число больше\n");
				tries += 1;
			}
			
		} while (guess != answ);
		tries += 1;
		printf_s("Угадали\n");
		printf_s("Число попыток: %d", tries);
		return 0;

	}
	else {
		tries = 0;
		max = 1000;
		min = 1;
		do
		{
			srand(time(NULL));
			guess = (rand()%(max-min + 1)) + min;
			printf_s("Догадка компьютера: %d\n", guess);
			printf_s("Введите знак: <, >, =\n");
			do
			{
				scanf_s("%c", &sign);
			} while ((sign != '<') && (sign != '>') && (sign != '='));
			if (sign == '<')
			{
				max = guess - 1;
				tries += 1;
			}
			if (sign == '>')
			{
				min = guess + 1;
				tries += 1;
			}
			if (min >= max) {
				printf_s("Ошибка ввода на предыдущих попытках");
				return 1;
			}
		} while (sign != '=');
		tries += 1;
		printf_s("Компьютер угадал!");
		printf_s("Число попыток: %d", tries);
		return 0;
	}
}