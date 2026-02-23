#include <stdio.h>
#include <string.h>
#define PROD_CNT 8
#define BARCODE_LEN 5
#define TITLE_LEN 10

char barcode_list[PROD_CNT][BARCODE_LEN] = {"0123", "1234", "2345", "3456", "4567", "5678", "6789", "7890"};
char product_list[PROD_CNT][TITLE_LEN] = {"Bread", "Milk", "Eggs", "Pasta", "Potato", "Meat", "Chocolate", "Water"};
int price_list[PROD_CNT] = {50, 80, 75, 85, 40, 300, 90, 60};
int discount_list[PROD_CNT] = {1, 5, 10, 15, 5, 30, 45, 50};

int barcode_checker(char barcode[]);
void price_calculator(int check_list[], int price_summary[], int discount_price_summary[], int* whole_price, int* total, int* total_discount);
void prod_information(int* index, int discount_price_summary[]);
void check_generator(int check_list[], int price_summary[], int discount_price_summary[], int* whole_price, int* total, int* total_discount);

int main() {
	int index = -1, whole_price = 0, total_discount = 0, total_price = 0, generator = 0, flag;
	int check_list[PROD_CNT] = { 0 }, price_summary[PROD_CNT] = { 0 }, discount_price_summary[PROD_CNT] = { 0 };
	char barcode[BARCODE_LEN], add[BARCODE_LEN] = { 0 };
	do {
		printf("Input a barcode. Input 'END' to end the purchase: ");
		scanf_s("%s", barcode, (unsigned)sizeof(barcode));
		printf("\n");
		while ((flag = getchar()) != '\n' && flag != EOF);
		index = barcode_checker(barcode);
		if (index != -1) {
			generator = 1;
			discount_price_summary[index] = (int)(price_list[index] * ((100 - discount_list[index]) / 100.0));
			prod_information(&index, discount_price_summary);
			printf("Input ADD to add the product to the list or press any key to skip and continue:\n");
			scanf_s("%s", add, (unsigned)sizeof(add));
			printf("\n");
			if (strcmp(add, "ADD") == 0) {
				check_list[index]++;
			}
		}
	} while (strcmp(barcode, "END") != 0);
	if (generator) {
		price_calculator(check_list, price_summary, discount_price_summary, &whole_price, &total_price, &total_discount);
		check_generator(check_list, price_summary, discount_price_summary, &whole_price, &total_price, &total_discount);
	}
	else {
		printf("Add products to the list to print the check.\n");
		printf("\n");
	}
	return 0;
}

int barcode_checker(char barcode[]) {
	for (int i = 0; i < PROD_CNT; i++) {
		if (strcmp(barcode, barcode_list[i]) == 0) {
			return i;
		}
	}
	if (strcmp(barcode, "END") != 0) {
		printf("Wrong input. Try again.\n");
		printf("\n");
	}
	return -1;
}

void price_calculator(int check_list[], int price_summary[], int discount_price_summary[], int* whole_price, int* total_price, int* total_discount) {
	for (int i = 0; i < PROD_CNT; i++) {
		if (check_list[i]) {
			price_summary[i] += discount_price_summary[i] * check_list[i];
			*whole_price += price_list[i] * check_list[i];
			*total_price += price_summary[i];
		}
	}
	*total_discount = *whole_price - *total_price;
}

void prod_information(int* index, int discount_price_summary[]) {
	printf("Information\n\n");
	printf("Title: %s\n", product_list[*index]);
	printf("Price: %d\n", price_list[*index]);
	printf("Discount: %d%%\n", discount_list[*index]);
	printf("Final price: %d\n", discount_price_summary[*index]);
	printf("\n");
}

void check_generator(int check_list[], int price_summary[], int discount_price_summary[], int* whole_price, int* total_price, int* total_discount) {
	printf("-----------------------------------\n");
	printf("| %-9s | %5s | %3s | %5s |\n", "Title", "Price", "Qua", "Final");
	printf("|---------------------------------|\n");
	for (int i = 0; i < PROD_CNT; i++) {
		if (check_list[i]) {
			printf("| %-9s | %5d | %3d | %5d |\n", product_list[i], discount_price_summary[i], check_list[i], price_summary[i]);
		}
	}
	printf("|---------------------------------|\n");
	printf("| Price: %-25d|\n", *whole_price);
	printf("| Discount: %-22d|\n", *total_discount);
	printf("| Final price: %-19d|\n", *total_price);
	printf("-----------------------------------\n");
	printf("\n");
}