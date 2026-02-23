#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 4

void user_input(char* user_choice);
void scan(char goods[][20], char data_barcode[][4], int data_price[], int discounts[], int data_discounts_price[], int check[]);
int form_check(char goods[][20], int check[], int data_price[], int value_disc[], int data_discounts_price[], int *disc_sum, int *summa, int *final_summa);

int main() {    
    char userChoice;
    int is_true = 1, i, flag = 0;
    char barcode[5] = "";
    char goods[N][20] = { "Маркер", "Карандаш", "Ручка", "Ластик" };
    char data_barcode[N][4] = { "1337", "1488", "1309", "0512" };
    int data_price[N] = { 119, 29, 69, 25 };
    int check[N] = { 0, 0, 0, 0 };
    int discounts[N] = { 1 + rand() % 50, 1 + rand() % 50, 1 + rand() % 50, 1 + rand() % 50 };
    int data_discounts_price[N] = {
        data_price[0] - (int)(data_price[0] * discounts[0] / (float)100),
        data_price[1] - (int)(data_price[1] * discounts[1] / (float)100),
        data_price[2] - (int)(data_price[2] * discounts[2] / (float)100),
        data_price[3] - (int)(data_price[3] * discounts[3] / (float)100)
    };
    int summa = 0, final_summa = 0, disc_sum = 0;
    int value_disc[N] = {
        (int)(data_price[0] * discounts[0] / (float)100),
        (int)(data_price[1] * discounts[1] / (float)100),
        (int)(data_price[2] * discounts[2] / (float)100),
        (int)(data_price[3] * discounts[3] / (float)100)
    };
    setlocale(LC_ALL, "rus");
    srand((unsigned int)time(0));

    do {
        printf("Электронная касса \n"); printf("----------------------\n\n");
        printf("1) СКАН\n2) Сформировать чек\n");
        user_input(&userChoice);

        if (userChoice == '1') {
            scan(goods, data_barcode, data_price, discounts, data_discounts_price, check);
        }
        else if (userChoice == '2') {
            int res = form_check(goods, check, data_price, value_disc, data_discounts_price, &disc_sum, &summa, &final_summa);

            if (res == 1) return 1;
        }
    } while (is_true);
    return 0;
}


void user_input(char* user_choice) {
    int c, ex_ch;
    while (1) {
        printf("\nКоманда: ");
        scanf_s(" %c", user_choice, 1) != 1;
        ex_ch = 0;
        while ((c = getchar()) != '\n') {
            ex_ch++;
        }

        if ((*user_choice == '1' || *user_choice == '2') && ex_ch == 0) {
            break;
        }
        else {
            printf("Ошибка. Допустимы команды 1 или 2\n");
        }
    }
}

void scan(char goods[][20], char data_barcode[][4], int data_price[], int discounts[], int data_discounts_price[], int check[]) {
    int i, flag=0;
    char barcode[5] = "", userChoice;

    printf("Введите штрих-код товара: "); scanf_s("%4s", barcode, sizeof(barcode));

    for (i = 0; i < N; i++) {
        if (strncmp(barcode, data_barcode[i], 4) == 0) {
            flag = 1;

            printf("\n    Товар   |  Цена(руб)  |  Скидка %% | Цена со скидкой\n");
            printf("-------------------------------------------------------\n");
            printf(" %-16s %-12d %-12d %d", goods[i], data_price[i], discounts[i], data_discounts_price[i]);

            printf("\n\n1) Добавить товар в чек\n2) Назад\n");
            user_input(&userChoice);

            if (userChoice == '1') check[i]++;
            else continue;

        }
    }
    if (flag == 0) {
        printf("Ошибка! Введенный штрих-код не существует\n\n");
    }
}

int form_check(char goods[][20], int check[], int data_price[], int value_disc[], int data_discounts_price[], int *disc_sum, int *summa, int *final_summa) {
    int i, flag = 0, breaker=0;
    char userChoice;
    printf("----------------------ЧЕК---------------------\n");
    printf("\n    Товар   | Кол-во |Цена за 1 ед.| Общая сумма \n");

    for (i = 0; i < N; i++) {
        if (check[i] != 0) {
            flag = 1;
            *summa += (check[i] * data_price[i]);
            *disc_sum += (check[i] * value_disc[i]);
            *final_summa += (data_discounts_price[i] * check[i]);
            printf("------------------------------------------------\n");
            printf(" %-15s %-8d %d            %d\n", goods[i], check[i], data_price[i], data_discounts_price[i] * check[i]);

        }
    }
    printf("Общая цена: %d\nСумма скидок: %d\nИтоговая сумма: %d\n", *summa, *disc_sum, *final_summa);
    printf("------------------------------------------------\n\n\n");

    if (flag == 1) {
        printf("1) Расчитать итоговую сумму\n2)Продолжить\n");
        user_input(&userChoice);
        if (userChoice == '1') {
            printf("Сумма к оплате: %d\n", *final_summa);
            return 1;
        }

    }
    else {
        printf("Добавьте хоть 1 товар в чек!!!\n\n");
    }
    return 0;
}


/*flag = 0;
printf("----------------------ЧЕК---------------------\n");
printf("\n    Товар   | Кол-во |Цена за 1 ед.| Общая сумма \n");

for (i = 0; i < N; i++) {
    if (check[i] != 0) {
        flag = 1;
        summa += (check[i] * data_price[i]);
        disc_sum += (check[i] * value_disc[i]);
        final_summa += (data_discounts_price[i] * check[i]);
        printf("------------------------------------------------\n");
        printf(" %-15s %-8d %d            %d\n", goods[i], check[i], data_price[i], data_discounts_price[i] * check[i]);

    }
}
printf("Общая цена: %d\nСумма скидок: %d\nИтоговая сумма: %d\n", summa, disc_sum, final_summa);
printf("------------------------------------------------\n\n\n");

if (flag == 1) {
    printf("1) Расчитать итоговую сумму\n2)Продолжить\n");
    user_input(&userChoice);
    if (userChoice == '1') {
        printf("Сумма к оплате: %d\n", final_summa);
        return 1;
    }
    else continue;

}
else {
    printf("Добавьте хоть 1 товар в чек!!!\n\n");
    continue;
}*/