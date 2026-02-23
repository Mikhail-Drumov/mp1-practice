#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main() {
	unsigned corov = 0, buk = 0, b[5] = { 10, 10, 10, 10, 10 };
	unsigned n, a[5] = { 10, 10, 10, 10, 10 };
	int i, j;
	setlocale(LC_ALL, "RU");
	printf("»гра \"Ѕыки и коровы\"\n«агадайте длину числа от 2 до 5: ");

	do {
		scanf_s("%u", &n);
		if (n < 2 || n > 5) printf("¬ведена неправильна€ длина числа\n");
	} while (n < 2 || n > 5);

	srand(time(NULL));
	a[0] = rand() % 9 + 1; // гарантирует, что 1-а€ цифра не 0
	for (i = 1; i < n; i++) {
		if (a[i] == 10) a[i] = rand() % 10;
		for (j = 0; j < i; j++) {
			if (a[i] == a[j]) {
				a[i] = rand() % 10;
				j = -1; // как нашел повторение, провер€ю всЄ снова
			}
		}
	}
	
	//for (i = 0; i < n; i++) {
	//	printf("%u ", a[i]);
	//} // чит на показ числа ;)

	printf_s("\nя задумал число длины %u из цифр от 0 до 9 - угадайте его: ", n);
	do {
		j = 0;
		do {
			scanf_s("%u", &(b[j]));
			j++;
		} while (j < n);

		for (i = 0; i < n; i++) {
			if (a[i] == b[i]) buk++;
			for (j = 0; j < i; j++) {
				if (a[i] == b[j]) corov++;
			}
			for (j = i + 1; j < n; j++) {
				if (a[i] == b[j]) corov++;
			}
		}
		printf("”гадано коров %u, угадано быков %u\n", corov, buk);
		if (buk == n) break;
		buk = 0;
		corov = 0;
	} while (1);
	return 0;
}