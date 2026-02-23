#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG
void main() {
	int a[5], b[5];
	int user_ans, cnt_bc = 0, cow_cnt, bull_cnt, num_len = 0, i, j, k, flag = 0, len_cnt;
	srand((unsigned int)time(0));
	printf("Bulls and Cows\n");
	while (num_len < 2 || num_len > 5) {
		printf("Input number length in range 2-5:\n");
		scanf_s("%d", &num_len);
		if (num_len < 2 || num_len > 5) printf("Wrong input. Try again.\n");
	}
	a[0] = 1 + rand() % 9;
	for (i = 1; i < num_len; i++) {
		do {
			a[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (a[i] == a[j]) {
					flag = 1;
				}
			}
		} while (flag);
	}
	printf("Guess a %d-digit number.\nNumbers must not repeat:\n", num_len);
#ifdef DEBUG
	printf("//DEBUG MODE: ");
	for (k = 0; k < num_len; k++) {
		printf("%d", a[k]);
	}
	printf("\n");
#endif
	do {
		len_cnt = 0;
		scanf_s("%d", &user_ans);
		for (i = 1; i <= num_len; i++) {
			b[num_len - i] = user_ans % 10;
			user_ans /= 10;
			len_cnt++;
		}
		if (len_cnt != num_len) {
			printf("Wrong input. Try again.\n");
			continue;
		}
		cow_cnt = 0;
		bull_cnt = 0;
		for (i = 0; i < num_len; i++) {
			if (b[i] == a[i]) {
				bull_cnt++;
			}
			for (j = 0; j < num_len; j++) {
				if ((b[i] == a[j]) && (i != j)) {
					cow_cnt++;
				}
			}
		}
		flag = 0;
		for (i = 0; i < num_len; i++) {
			if (b[i] == a[i]) {
				flag++;
			}
		}
		printf("Bulls: %d, Cows: %d\n", bull_cnt, cow_cnt);
		cnt_bc++;
	} while ((flag < num_len) && (cnt_bc < 10));
	if (flag == num_len) {
		printf("You won!\n");
	}
	if (cnt_bc == 10) {
		printf("Answer: ");
		for (k = 0; k < num_len; k++) {
			printf("%d", a[k]);
		}
	}
}
