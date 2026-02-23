#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int rej = 0, ran, otv;
	int l = 0, r = 1000, ans, t = 0, cnt = 1;
	char h = '=';
	setlocale(LC_ALL, "Russian");
	do
	{
		printf("Угадать(0) или загадать(1) ");
		scanf_s("%d", &rej);
	} while (rej != 1 && rej != 0);

	if (rej == 0)
	{


		srand(time(NULL));
		ran = rand() % 1000 + 1;
		printf("Попробуй угадать число:\n ");
		scanf_s("%d", &otv);
		cnt = 1;
		while (otv != ran)
		{
			if (otv > ran)
			{
				printf("Загаданное число меньше\n ");
				cnt++;
				scanf_s("%d", &otv);
			}
			else
			{
				printf("Загаданное число больше\n ");
				cnt++;
				scanf_s("%d", &otv);
			}
		}
		printf("Угадали.\n Число было отгадано за %d попытки(-ок)", cnt);
		return 0;
	}


	else
	{


		do {
			printf("Загадайте число от 1 до 1000 ");
			scanf_s("%d", &ans);
		} while (ans < 1 || ans>1000);

		while (t != ans)
		{
			t = (l + r) / 2;
			printf("Ваше число %d?(>-если ваше число больше, < - если меньше, = - если равно) ", t);
			do
			{
				scanf_s(" %c", &h, 1);
			} while (h != '>' && h != '<' && h != '=');
			if (h == '=')
			{
				t = ans;
				break;
			}
			if (h == '>')
			{
				l = t + 1;
				cnt++;
			}
			else
			{
				r = t - 1;
				cnt++;
			}
		}
		printf("Число было угадано за %d попытки(-ок)", cnt);
		return 0;
	}
}