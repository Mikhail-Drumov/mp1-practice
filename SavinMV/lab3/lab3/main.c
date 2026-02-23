#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int dl, bik = 0, kor = 0, i = 0, k = 0, j = 0, c = 0, l = 0, ch;
	int d[10] = { 0 }, chp[5] = { 0 }, pc_num[5] = { 0 };
	srand((unsigned int)time(0));
	do {
		printf("Vvedi dlinu ot 2 do 5: ");
		scanf_s("%d", &dl);
	} while (dl < 2 || dl>5);


	for (i; i < dl; i++) {
		do {
			if (i == 0) pc_num[i] = rand() % 9 + 1;
			else pc_num[i] = rand() % 10;
		} while (d[pc_num[i]] == 1);
		d[pc_num[i]] = 1;
	}
	
	if (dl == 2) printf("chislo kompa: %d%d\n", pc_num[0], pc_num[1]);
	if (dl == 3) printf("chislo kompa: %d%d%d\n", pc_num[0], pc_num[1], pc_num[2]);
	if (dl == 4) printf("chislo kompa: %d%d%d%d\n", pc_num[0], pc_num[1], pc_num[2], pc_num[3]);
	if (dl == 5) printf("chislo kompa: %d%d%d%d%d\n", pc_num[0], pc_num[1], pc_num[2], pc_num[3], pc_num[4]);
	
	l = dl;
	printf("Poprobuy vvesti chislo dlinoy %d: ", dl);
	

	do {
		bik = 0;
		kor = 0;
		scanf_s("%d", &ch);
		while (ch != 0) {
			c = ch % 10;
			chp[dl - 1] = c;
			ch /= 10;
			dl -= 1;
		}
		dl=l;
		for (i = 0;i < l;i++) {
			if (pc_num[i] == chp[i]) bik += 1;
			for (j = 0;j < i;j++) {
				if (pc_num[i] == chp[j]) kor += 1;

			}
			for (j = i + 1; j < l;j++) {
				if (pc_num[i] == chp[j]) kor += 1;
			}
		}
		printf("%d bik and %d kor\n", bik, kor);
		if (bik != l) printf("ne ygadal, poprobui eshe\n");
	} while (bik != l);
	printf("ygadal");
	return 0;
}