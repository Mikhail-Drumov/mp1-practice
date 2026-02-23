#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	int reshim, chislor, chpol;
	int minch, maxch;
	int cnt = 0;
	char polznak;
	printf("vybrat reshim: 1 - ygadat chislo, 2 - zagadat chislo\n");
	scanf_s(" %d", &reshim);
	if (reshim == 1) {
		srand((unsigned int)time(0));
		chislor = rand() % (1000) + 1;
		printf("igra zagadala chislo ot 1 do 1000, pishite vashi otgatki\n");
		do {
			scanf_s("%d", &chpol);
			if (chpol > 1000 || chpol < 1) {
				printf("OT 1 DO 1000\n");
			}
			else if (chpol < chislor) {
				printf("Bolshe\n");
				cnt += 1;
			}
			else if (chpol > chislor) {
				printf("Menshe\n");
				cnt += 1;
			}
		} while (chpol != chislor);

		if (chislor == chpol) {
			printf("Vigral, %d popitok", cnt + 1);
		}
	}
	if (reshim == 2) {
		printf("Zagadai chislo ot 1 do 1000\n");
		printf("nasha programma budet ugaduvat vashe chislo\n");
		printf("na vse otgadki compyter pisihite znak < > =\n");
		minch = 1;
		maxch = 1000;
		do {
			chislor = (minch + maxch) / 2;
			printf("%d\n", chislor);
			scanf_s(" %c", &polznak);
			if (polznak == '>') {
				minch = chislor + 1;
				cnt += 1;
			}
			if (polznak == '<') {
				maxch = chislor - 1;
				cnt += 1;
			}
			if (polznak == '=') {
				printf("Vigral, %d popitok", cnt + 1);
				return 0;
			}
			if (polznak != '>' && polznak != '<' && polznak != '=') {
				printf("Tolko <, >, =\n");
			}
			if (minch > maxch) {
				printf("Oshibka");
				return 1;
			}
		} while (minch <= maxch);
	}
	return 0;
}