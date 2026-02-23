#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(void) {
    int a, i = 0;
    setlocale(LC_ALL, "RU");
    printf("Выберете режим:\n\"Угадай число (1)\"\n\"Загадай число (2)\"\nВаш выбор: ");
    scanf_s("%d", &a);


    if (a != 1 && a != 2) {
        printf("Неправильный номер режима");
        return 1;
    }


    switch (a) {
    case 1:
        printf("Режим \"Угадай число\"\n \"Угадайте число от 1 до 1000:\"\n");
        srand(time(NULL));
        int c = rand() % 1000 + 1;
        int r;
        do {
            scanf_s("%d", &r);
            i++;
            if (c > r) printf("Загаданное число больше\n");
            else if (c < r) printf("Загаданное число меньше\n");
        } while (c != r);
        printf("Угадали!\nЧисло попыток: %d", i);
        break;

    case 2:
        printf("Режим \"Загадай число\"\n \"Загадайте число от 1 до 1000:\"\n");
        int min = 1, max = 1000, attempt;
        char answer;

        do {
            attempt = min + (max - min) / 2;
            i++;
            printf("Догадка %d: %d\n Ваш ответ (> , < , =): ", i, attempt);
            scanf_s(" %c", &answer);

            if (answer == '>') {
                min = attempt + 1;
            }
            else if (answer == '<') {
                max = attempt - 1;
            }
            else if (answer == '=') {
                printf("Я угадала число %d за %d попыток!\n", attempt, i);
                break;
            }
            else {
                printf("Используйте только >, < или =\n");
                i--;
                continue;
            }

            if (min > max) {
                printf("Где-то ошибка в ваших ответах");
                break;
            }

        } while (1); //поставил 1 (условие всегда истинно), чтобы был бесконечный цикл, пока не сработает один из break. Удобная фича

        break;
    }
}