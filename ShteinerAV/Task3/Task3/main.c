#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define DEBUG
int find(int arr[], int size, int target);
void create_rand_num(int generate_arr[], int size);
void user_answer();
int different_num();


int main() {
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(0));

	int komp_arr[5], is_play = 1, cnt_try = 0, len, i;

	printf("Введите длину числа");
	scanf_s("%d", &len);

	while (len < 2 || len > 5) {
		printf("Некорректный ввод");
		printf("Введите длину числа");
		scanf_s("%d", &len);
	}


	create_rand_num(komp_arr, len);


#ifdef DEBUG
	printf("***Загаданная комбинация - ");
	for (i = 0; i < len; i++) {
		printf("%d", komp_arr[i]);
	}
	printf("***\n--------------------------------------\n");
#endif 

	do {
		int user_arr[5], cnt_bulls = 0, cnt_cows = 0, i;
		cnt_try += 1;

		user_answer(user_arr, len);

		while (different_num(user_arr, len) != len) {
			printf("Ты ввёл число c повтором!\n");
			user_answer(user_arr, len);
		}

		for (i = 0; i < len; i++) {

			if (komp_arr[i] == user_arr[i]) {
				cnt_bulls += 1;
				continue;
			}
			else if (find(komp_arr, len, user_arr[i])) {
				cnt_cows += 1;
			}

		}

		if (cnt_bulls == len) {
			is_play = 0;
		}

		printf("\n");

		for (i = 0; i < len; i++) {
			printf("%d", user_arr[i]);
		}

		printf("\nКол-во быков: %d\n", cnt_bulls);
		printf("Кол-во коров: %d\n--------------------------------------\n", cnt_cows);

	} while (is_play);

	printf("Ты выйграл за %d попыток!", cnt_try);

	return 777;
}

int find(int arr[], int size, int target) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == target) {
			return 1;
		}
	}

	return 0;
}

int different_num(int arr[], int size) {
	int i, j, flag, cnt = 0;

	for (i = 0; i < size; i++) {
		flag = 1;
		for (j = 0; j < i; j++) {
			if (arr[j] == arr[i]) {
				flag = 0;
			}
		}

		if (flag) {
			cnt++;
		}
	}

	return cnt;
}

void create_rand_num(int generate_arr[], int size) {
	int digits[10] = { 0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < size; i++) {
		int number = rand() % 10;
		if (i == 0 && number == 0) {
			number = 1 + rand() % 9;
		}
		while (digits[number] != 0) {
			number = rand() % 10;
		}
		digits[number] = 1;
		generate_arr[i] = number;
	}
}

void user_answer(int user_arr[], int size) {
	int user_num, i, max_value = 0, min_value = 1;

	for (i = 0; i < size - 1; i++) {
		min_value *= 10;
		max_value += 9;
		max_value *= 10;
	}
	max_value += 9;

	printf("Введи число длины %d: ", size);
	scanf_s("%d", &user_num);

	while (user_num < min_value || user_num > max_value) {
		printf("Ты ввёл число не той длины!");
		printf("\nВведи число длины %d: ", size);
		scanf_s("%d", &user_num);
	}

	i = size - 1;
	while (user_num != 0) {
		user_arr[i--] = user_num % 10;
		user_num /= 10;
	}

}
