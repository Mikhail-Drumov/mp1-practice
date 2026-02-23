#include <stdio.h>
#include <string.h>
#define PRODUCTS_COUNT 5
#define BARCODE_LENGTH 5
#define MAX_PRODUCT_NAME_LENGTH 20

//products info
char barcodes[PRODUCTS_COUNT][BARCODE_LENGTH] = {
"1111",
"0123",
"1234",
"5678",
"9012"
};

char product_names[PRODUCTS_COUNT][MAX_PRODUCT_NAME_LENGTH] = {
"Pizza",
"Cucumber",
"Potato",
"Chocolate",
"Tea"
};

int cost[PRODUCTS_COUNT] = { 100, 20, 50, 150, 300 };

int discounts[PRODUCTS_COUNT] = { 5, 1, 10, 25, 50 }; //in percentages

//functions
int check_the_barcode(char barcode[]) {
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (strcmp(barcode, barcodes[i]) == 0) {
			return i;
		}
	}
	if (strcmp(barcode, "END") != 0) {
		printf("ERROR: Barcode is not found.\n\n");
	}
	return -1;
}

void calculations(int total_products_count[], int summ_products_cost[], int cost_with_discount[], int* total_without_discount, int* total, int* total_discount) {
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (total_products_count[i]) {
			summ_products_cost[i] += cost_with_discount[i] * total_products_count[i];
			*total_without_discount += cost[i] * total_products_count[i];
			*total += summ_products_cost[i];
		}
	}
	*total_discount = *total_without_discount - *total;
}

void info_print(int* idx, int cost_with_discount[]) {
	printf("INFORMATION\n");
	printf("--------------------------------\n");
	printf("Name: %s\n", product_names[*idx]);
	printf("Price: %d\n", cost_with_discount[*idx]);
	printf("Discount: %d%%\n", discounts[*idx]);
	printf("Price (without discount): %d\n\n", cost[*idx]);
}

void question(int* idx, int total_products_count[]) {
	int query;
	do {
		printf("Do you want to add the product to the check?\n\n");
		printf("1. Yes\n");
		printf("2. No\n\n");
		printf("Answer: ");
		scanf_s("%d", &query);
		if (query == 1) {
			total_products_count[*idx]++;
			printf("The product added.\n\n");
		}
		if (query != 1 && query != 2) {
			printf("ERROR: Uncorrect input!\n\n");
		}
	} while (query != 1 && query != 2);
}

void check_print(int total_products_count[], int summ_products_cost[],
		int cost_with_discount[], int* total_without_discount, int* total, int* total_discount) {
	printf("---------------------------------------------------------------\n");
	printf("|                            CHECK                            |\n");
	printf("|-------------------------------------------------------------|\n");
	printf("| %-20s | %10s | %10s | %10s |\n", "NAME", "PRICE", "QTY", "TOTAL");
	printf("|-------------------------------------------------------------|\n");
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (total_products_count[i]) {
			printf("| %-20s | %10d | %10d | %10d |\n", product_names[i], 
				cost_with_discount[i], total_products_count[i], summ_products_cost[i]);
		}
	}
	printf("|-------------------------------------------------------------|\n");
	printf("| TOTAL without discount: %-36d|\n", *total_without_discount);
	printf("| TOTAL DISCOUNT: %-44d|\n", *total_discount);
	printf("| TOTAL: %-53d|\n", *total);
	printf("---------------------------------------------------------------\n\n");
}

//main code
int main() {
	int idx = -1, total_without_discount = 0, total_discount = 0, total = 0, check_printing = 0, c;
	int total_products_count[PRODUCTS_COUNT] = { 0 }, summ_products_cost[PRODUCTS_COUNT] = { 0 },
		cost_with_discount[PRODUCTS_COUNT] = { 0 };
	char barcode[BARCODE_LENGTH];

	do {
		printf("Input a barcode or END (to end the purchase): ");
		scanf_s("%s", barcode, (unsigned)sizeof(barcode));
		while ((c = getchar()) != '\n' && c != EOF);
		idx = check_the_barcode(barcode);
		if (idx != -1) {
			check_printing = 1;
			cost_with_discount[idx] = (int)(cost[idx] * ((100 - discounts[idx]) / 100.0));
			info_print(&idx, cost_with_discount);
			question(&idx, total_products_count);
		}
	} while (strcmp(barcode, "END") != 0);

	if (check_printing) {
		calculations(total_products_count, summ_products_cost, cost_with_discount,
			&total_without_discount, &total, &total_discount);
		check_print(total_products_count, summ_products_cost, cost_with_discount,
			&total_without_discount, &total, &total_discount);
	}
	else {
		printf("Check is empty. Nothing to print.\n\n");
	}

	return 0;
}