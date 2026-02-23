#include <stdio.h>
#include <time.h>

int main() {
	
	int komp, pol = 0, cnt = 0, rez, min, max;
	char znak;
	printf("Viberi rezhim\n");
	scanf_s("%d", &rez);

	if (rez == 1) {
		printf("Vvodi chisla ot 1 do 1000\n");
		srand((unsigned int)time(0));
		komp = rand() % (1000) + 1;
		do {
			scanf_s("%d", &pol);
			if (pol > 1000 || pol < 1) {
				printf("OT 1 DO 1000\n");
			}
			else if (pol < komp) {
				printf("Bolshe\n");
				cnt += 1;
			}
			else if (pol > komp) {
				printf("Menshe\n");
				cnt += 1;
			}
		} while (pol != komp);
		if (pol == komp) {
			printf("Vigral, %d popitok", cnt + 1);
		}
	
	}
	
	if (rez == 2) {
		printf("Zagadai chislo ot 1 do 1000\n");
		min = 1;
		max = 1000;
			do {
				komp = (min + max) / 2;
				printf("%d\n", komp);
				scanf_s(" %c", &znak);
				
				if (znak == '>') {
					min = komp + 1;
					cnt += 1;
				}
				
				if (znak == '<') {
					max = komp - 1;
					cnt += 1;
			    }
				if (znak == '=') {
					printf("Vigral, %d popitok", cnt + 1);
					return 0;
				}
				if (znak != '>' && znak != '<' && znak != '=') {
					printf("Tolko <, > ili =\n");
				}
				if (min > max) {
					printf("Oshibka");
					return 1;
				}
		    } while (min <= max);
			

			
	}
	return 0;
}