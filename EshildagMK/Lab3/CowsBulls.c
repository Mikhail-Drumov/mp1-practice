#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int formNum(int n, int* gm_digit);

int main() {
	int gnum = 0, plnum, i = 0, j = 0, ncount, ic = 0, ib = 0, temp;
	int pl_digit[5] = { 0, 0, 0, 0, 0 };
	int gm_digit[5] = { 0, 0, 0, 0, 0 };

	srand(time(NULL));

	printf("Enter ammount of numbers:\n");
	scanf_s("%d", &ncount);
	gnum = formNum(ncount, gm_digit);
	i = 0;

	while (ib != ncount) {
		ic = 0; ib = 0; i = 0;
		for (i = 0; i < 5; i++) {
			pl_digit[i] = 0;
		}
		i = 0;
		printf("Enter your number:\n");
		scanf_s("%d", &plnum);

		temp = plnum;
		while (temp > 0) {
			pl_digit[i] = temp % 10;
			temp /= 10;
			i++;
		}
		i = 0;

		for (i = 0; i < ncount; i++) {
			if (pl_digit[i] == gm_digit[i]) {
				ib++;
			}
			else {
				for (j = 0; j < ncount; j++) {
					if (pl_digit[i] == gm_digit[j]) {
						ic++;
					}
				}
			}
		}

		printf("Cows: %d", ic);
		printf("\nBulls: %d", ib);
		printf("\n");
	}
	printf("YOU WON!  %d", gnum);
}

int formNum(int n, int* gm_digit) {
	int i = 0, rnum, s = 0;
	int UsedNums[10] = { 0 };
	while (i < n) {
		rnum = rand() % 10;
		if (UsedNums[rnum] == 1 || (i == 0 && rnum == 0)) {
			continue;
		}
		UsedNums[rnum] = 1;
		s *= 10;
		s += rnum;
		gm_digit[n - i - 1] = rnum;
		i++;
	}
	return s;
}