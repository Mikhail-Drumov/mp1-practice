#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define am_prod 8
int prod_finder(char* barcode);
void add_to_cart(int i, int am);
void form_receipt();

char exit_code = 0;
int item_count = 0;
typedef struct {
	char barcode[5];
	int price;
	int discount;
	int sum;
	char name[20];
} Product;

Product products[am_prod] = {
	{"1111", 100, 15, 0, "TOMATOES"},
	{"2222", 90, 17, 0, "CUCUMBERS"},
	{"3333", 80, 21, 0, "CHEESE"},
	{"4444", 70, 9, 0, "ONIONS"},
	{"5555", 60, 11, 0, "CARTON OF MILK"},
	{"6666", 50, 7, 0, "MEAT"},
	{"7777", 40, 34, 0, "ORANGES"},
	{"8888", 30, 5, 0, "WATER"}
};
//int am_prod = 8; //êîëè÷åñòâî ïðîäóêòîâ
int main() {
	int currID, currAmmount;
	char enterCode[10];

	printf("===Electronic sales register===\n");
	printf("To add a product to the shopping cart, enter the barcode\n");
	printf("To exit and form a receipt enter '0' \n");

	while (1) {
		printf("Please, enter barcode: ");
		scanf_s("%9s", enterCode, 10);
		if (strcmp(enterCode, "0") == 0) {
			if (item_count > 0) {
				form_receipt();
				break;
			}
			else {
				printf("Receipt is empty.");
				break;
			}
		}
		else {
			currID = prod_finder(enterCode);
			if (currID >= 0 && strlen(enterCode) == 4) {
				printf("You scanned %s\n", products[currID].name);
				printf("It`s price: %d Rub.\n", products[currID].price);
				printf("Today`s discount: %d%%\n", products[currID].discount);
				printf("Enter amount of items: ");
				scanf_s("%d", &currAmmount);
				add_to_cart(currID, currAmmount);
				if (currAmmount > 0) {
					printf("ADDED\n");
				}
				else { printf("Nothing to add...\n"); }
			}
			else {
				printf("Error. There is no product with this barcode: %s\n", enterCode);
			}

		}
	}
}

int prod_finder(char* enterCode) {
	int i;
	for (i = 0; i < am_prod; i++) {
		if (strcmp(products[i].barcode, enterCode) == 0) {
			return i;
		}
	}
	return -1;
}

void add_to_cart(int i, int am) {
	products[i].sum += am;
	item_count += am;
}
void form_receipt() {
	int i, receipt_pos = 0, itemPRICE = 0, totalSUM = 0, totalDISCOUNT = 0;
	printf("\nRECEIPT\n");
	for (i = 0; i < am_prod; i++) {
		if (products[i].sum > 0) {
			receipt_pos++;
			itemPRICE = (products[i].price - ((products[i].discount * products[i].price) / 100)) * products[i].sum;
			totalSUM += itemPRICE;
			totalDISCOUNT += ((products[i].discount * products[i].price) / 100) * products[i].sum;
			printf("%d. %s (%d) --- ", receipt_pos, products[i].name, products[i].sum);
			printf("Price: %d Rub. | Price with discount(%d%%): %d Rub.\n", products[i].price * products[i].sum, products[i].discount, itemPRICE);
		}
	}
	printf("TOTAL: %d Rub., Your discount: %d Rub.\n", totalSUM, totalDISCOUNT);
}