#include <stdio.h>
#include <string.h>

#define L 4

void scan(char qr[]);
void info(char qrSelect[], char* qrs[], char* name[], int cost[], int discount[]);
void addToCheck(char qrSelect[], int check[], char* qrs[]);
void createCheck(int check[], char* name[], int cost[], float discount[]);
void totalCost(int check[], int cost[], float discount[]);

int main()
{
	int i, select;
	int check[L] = {0,0,0,0};
	char* qr[L] = { "0000","0001","0200","9000" };
	char* name[L] = { "milk","cake","juse","bean" };
	int cost[L] = {50,250,15,30};
	float discount[L] = { 0.10f,0.40f,0.0f,0.15f };
	char qrSelect[5] = "9999";
	for (i = 0; i < L; i++) { printf("%s ",qr[i]); };
	printf("\n");
	do
	{
		printf("select option (0 - exit, 1 - scan QR, 2 - product info, 3 - add product to check, 4 - create check, 5 - get total cost): ");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: scan(qrSelect); break;
		case 2: info(qrSelect, qr, name, cost, discount); break;
		case 3: addToCheck(qrSelect, check, qr); break;
		case 4: createCheck(check, name, cost, discount); break;
		case 5: totalCost(check, cost, discount); select = 0; break;
		default:break;
		}

	} while (select != 0);
	return 0;
}

void scan(char qr[])
{
	getchar();
	printf("Enter QR:");
	fgets(qr,5, stdin);
	while (getchar() != '\n');
}
void info(char qrSelect[], char* qrs[], char* name[], int cost[], float discount[])
{
	int i,j;
	for (i = 0; i < L; i++) {
		if (strcmp(qrSelect, qrs[i]) == 0)
		{
			printf("product name: %s\n", name[i]);
			printf("product cost: %d\n", cost[i]);
			printf("product discount: %2.1f\n", discount[i] * 100);
			break;
		}
	}
	if (i == L) { printf("uncorect QR\n"); }
}
void addToCheck(char qrSelect[], int check[], char* qrs[])
{
	int i;
	for (i = 0; i < L; i++) {
		if (strcmp(qrSelect, qrs[i]) == 0)
		{
			check[i]++;
			printf("product added\n");
			break;
		}
	}
	if (i == L) { printf("uncorect QR\n"); }
}
void createCheck(int check[], char* name[], int cost[], float discount[])
{
	int i,j;
	printf("\tname\t|\tcost\t|\tquantity\t|\ttotal cost\t\n");
	printf("--------------------------------------------------------------------------------\n");
	for (i = 0; i < L; i++)
	{
		if (check[i] > 0)
		{
			printf("\t%s\t|\t%.2f\t|\t%8d\t|\t%.2f\t\n", name[i], cost[i] * (1 - discount[i]), check[i], cost[i] * (1 - discount[i]) * check[i]);
		}
	}
}
void totalCost(int check[], int cost[], float discount[])
{
	int i; float s = 0.0f;
	for (i = 0; i < L; i++)
	{
		s += cost[i] * (1 - discount[i]) * check[i];
	}
	printf("Total Cost: %.2f",s);
}