/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG
void main() {
	int a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, user_ans, cnt_bc = 0, cow_cnt, bull_cnt, num_len = 0;
	srand((unsigned int)time(0));
	printf("Bulls and Cows\n");
	while (num_len < 2 || num_len > 5) {
		printf("Input number length in range 2-5:\n");
		scanf_s("%d", &num_len);
		if (num_len < 2 || num_len > 5) printf("Wrong input. Try again.\n");
	}
	switch (num_len) {
	case 2:
		a1 = 1 + rand() % 9;
		do {
			a2 = rand() % 10;
		} while (a2 == a1);
		do {
			a3 = rand() % 10;
		} while (a3 == a1 || a3 == a2);
		printf("Guess a two-digit number.\nNumbers must not repeat:\n");
#ifdef DEBUG
		printf("//DEBUG MODE: %d%d\n", a1, a2);
#endif
		do {
			scanf_s("%d", &user_ans);
			b1 = user_ans / 10;
			b2 = user_ans % 10;
			if (user_ans / 10 < 0 || user_ans / 10 > 10) {
				printf("Wrong input. Try again.\n");
				continue;
			}
			cow_cnt = 0;
			bull_cnt = 0;
			if (b1 == a1) {
				bull_cnt++;
			}
			else if (b1 == a2) {
				cow_cnt++;
			}
			if (b2 == a2) {
				bull_cnt++;
			}
			else if (b2 == a1) {
				cow_cnt++;
			}
			printf("Bulls: %d, Cows: %d\n", bull_cnt, cow_cnt);
			cnt_bc++;
		} while ((a1 != b1 || a2 != b2) && cnt_bc < 10);
		if (a1 == b1 && a2 == b2) {
			printf("You won!\n");
		}
		if (cnt_bc == 10) {
			printf("Answer: %d%d\n", a1, a2);
		}
		break;
	case 3:
		a1 = 1 + rand() % 9;
		do {
			a2 = rand() % 10;
		} while (a2 == a1);
		do {
			a3 = rand() % 10;
		} while (a3 == a1 || a3 == a2);
		printf("Guess a three-digit number.\nNumbers must not repeat:\n");
#ifdef DEBUG
		printf("//DEBUG MODE: %d%d%d\n", a1, a2, a3);
#endif
		do {
			scanf_s("%d", &user_ans);
			b1 = user_ans / 100;
			b2 = (user_ans % 100) / 10;
			b3 = user_ans % 10;
			if (user_ans / 100 < 0 || user_ans / 100 > 10) {
				printf("Wrong input. Try again.\n");
				continue;
			}
			cow_cnt = 0;
			bull_cnt = 0;
			if (b1 == a1) {
				bull_cnt++;
			}
			else if (b1 == a2 || b1 == a3) {
				cow_cnt++;
			}
			if (b2 == a2) {
				bull_cnt++;
			}
			else if (b2 == a1 || b2 == a3) {
				cow_cnt++;
			}
			if (b3 == a3) {
				bull_cnt++;
			}
			else if (b3 == a1 || b3 == a2) {
				cow_cnt++;
			}
			printf("Bulls: %d, Cows: %d\n", bull_cnt, cow_cnt);
			cnt_bc++;
		} while ((a1 != b1 || a2 != b2 || a3 != b3) && cnt_bc < 10);
		if (a1 == b1 && a2 == b2 && a3 == b3) {
			printf("You won!\n");
		}
		if (cnt_bc == 10) {
			printf("Answer: %d%d%d\n", a1, a2, a3);
		}
		break;
	case 4:
		a1 = 1 + rand() % 9;
		do {
			a2 = rand() % 10;
		} while (a2 == a1);
		do {
			a3 = rand() % 10;
		} while (a3 == a1 || a3 == a2);
		do {
			a4 = rand() % 10;
		} while (a4 == a1 || a4 == a2 || a4 == a3);
		printf("Guess a four-digit number.\nNumbers must not repeat:\n");
#ifdef DEBUG
		printf("//DEBUG MODE: %d%d%d%d\n", a1, a2, a3, a4);
#endif
		do {
			scanf_s("%d", &user_ans);
			b1 = user_ans / 1000;
			b2 = (user_ans % 1000) / 100;
			b3 = (user_ans % 100) / 10;
			b4 = user_ans % 10;
			if (user_ans / 1000 < 0 || user_ans / 1000 > 10) {
				printf("Wrong input. Try again.\n");
				continue;
			}
			cow_cnt = 0;
			bull_cnt = 0;
			if (b1 == a1) {
				bull_cnt++;
			}
			else if (b1 == a2 || b1 == a3 || b1 == a4) {
				cow_cnt++;
			}
			if (b2 == a2) {
				bull_cnt++;
			}
			else if (b2 == a1 || b2 == a3 || b2 == a4) {
				cow_cnt++;
			}
			if (b3 == a3) {
				bull_cnt++;
			}
			else if (b3 == a1 || b3 == a2 || b3 == a4) {
				cow_cnt++;
			}
			if (b4 == a4) {
				bull_cnt++;
			}
			else if (b4 == a1 || b4 == a2 || b4 == a3) {
				cow_cnt++;
			}
			printf("Bulls: %d, Cows: %d\n", bull_cnt, cow_cnt);
			cnt_bc++;
		} while ((a1 != b1 || a2 != b2 || a3 != b3 || a4 != b4) && cnt_bc < 10);
		if (a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4) {
			printf("You won!\n");
		}
		if (cnt_bc == 10) {
			printf("Answer: %d%d%d%d\n", a1, a2, a3, a4);
		}
		break;
	case 5:
		a1 = 1 + rand() % 9;
		do {
			a2 = rand() % 10;
		} while (a2 == a1);
		do {
			a3 = rand() % 10;
		} while (a3 == a1 || a3 == a2);
		do {
			a4 = rand() % 10;
		} while (a4 == a1 || a4 == a2 || a4 == a3);
		do {
			a5 = rand() % 10;
		} while (a5 == a1 || a5 == a2 || a5 == a3 || a5 == a4);
		printf("Guess a five-digit number.\nNumbers must not repeat:\n");
#ifdef DEBUG
		printf("//DEBUG MODE: %d%d%d%d%d\n", a1, a2, a3, a4, a5);
#endif
		do {
			scanf_s("%d", &user_ans);
			b1 = user_ans / 10000;
			b2 = (user_ans % 10000) / 1000;
			b3 = (user_ans % 1000) / 100;
			b4 = (user_ans % 100) / 10;
			b5 = user_ans % 10;
			if (user_ans / 10000 < 0 || user_ans / 10000 > 10) {
				printf("Wrong input. Try again.\n");
				continue;
			}
			cow_cnt = 0;
			bull_cnt = 0;
			if (b1 == a1) {
				bull_cnt++;
			}
			else if (b1 == a2 || b1 == a3 || b1 == a4 || b1 == a5) {
				cow_cnt++;
			}
			if (b2 == a2) {
				bull_cnt++;
			}
			else if (b2 == a1 || b2 == a3 || b2 == a4 || b2 == a5) {
				cow_cnt++;
			}
			if (b3 == a3) {
				bull_cnt++;
			}
			else if (b3 == a1 || b3 == a2 || b3 == a4 || b3 == a5) {
				cow_cnt++;
			}
			if (b4 == a4) {
				bull_cnt++;
			}
			else if (b4 == a1 || b4 == a2 || b4 == a3 || b4 == a5) {
				cow_cnt++;
			}
			if (b5 == a5) {
				bull_cnt++;
			}
			else if (b5 == a1 || b5 == a2 || b5 == a3 || b5 == a4) {
				cow_cnt++;
			}
			printf("Bulls: %d, Cows: %d\n", bull_cnt, cow_cnt);
			cnt_bc++;
		} while ((a1 != b1 || a2 != b2 || a3 != b3 || a4 != b4 || a5 != b5) && cnt_bc < 10);
		if (a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4 && a5 == b5) {
			printf("You won!\n");
		}
		if (cnt_bc == 10) {
			printf("Answer: %d%d%d%d%d\n", a1, a2, a3, a4, a5);
		}
		break;
	}
}*/