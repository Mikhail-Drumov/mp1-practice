#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define N 1000
#define sizedb 15

char* given_codes[sizedb] = { "0001", "0002", "0003", "0004", "0005", "0006",
							  "0007", "0008", "0009", "0010", "0011", "0012",
							  "0013", "0014", "0015"};
char* name[sizedb] = { "apples", "milk", "bananas", "bread", "juice",
					   "ketchup", "mayonaise", "eggs", "cheese", "tomatoes",
	                   "sausages", "salad", "meat", "butter", "fish"};
int price[sizedb] = {100, 90, 75, 30, 300, 80, 75, 60, 140, 200, 300, 250, 400,
					 170, 270};
float discount[sizedb] = {0.15, 0.10, 0.25, 0.35, 0.5, 0.20, 0.40, 0.35, 0.10,
						  0.35, 0.45, 0.10, 0.10, 0.20, 0.40};
int cnt[sizedb] = { 0 };//массив для подсчета количества товаров

int scan(char code[]);
void add(char code[]);
void print_receipt();
int search(char code[]);

int main()
{
	int exit_prog = 1;
	do { 
		char code[8]; //переменная, в которую считываем код
		char ans[8];//переменная, в которую считываем проверку на запись в чек и выход из цикла
		int err = scan(code);

		if (strcmp(code, "exit") == 0)
		{
			exit_prog = 0;
			break;
		}
		if (err != 0)
		{
			printf_s("Item not found. Try again\n");
			continue;
		}//продолжаем, если код найден
		//при сканировании спрашивать, добавить ли товар в чек
		printf_s("Add? ");
		gets_s(ans, sizeof(ans));


		if (strcmp(ans, "y") == 0) add(code);
		else (printf_s("the item is not added\n"));
	} while (exit_prog);
	print_receipt();
	return 0; 
}

int scan(char *code)
{	//счетчик количества товара увеличивается сразу при добавлении
	int idx = -1;
	printf_s("Input code: ");
	gets_s(code, sizeof(code));
	idx = search(code);
	return (idx >= 0 ? 0 : 1);
}

int search(char code[])
{	
	int idx;
	int i; 
	for (i = 0; i < sizedb; i++)
	{
		if (strcmp(code, given_codes[i]) == 0)
		{
			return i;
			
		}
	}
	return -1;
}

void add(char code[])
{
	int idx = search(code);
	cnt[idx] += 1;
}

void print_receipt()
{
	float total = 0;
	int i;
	for (i = 0; i < sizedb; i++) {
		if (cnt[i] > 0)
		{
			printf_s("Code: %s, name: %s, price: %d, count: %d, discount: %.2f = %.2f\n",
				given_codes[i], name[i], price[i], cnt[i],
				cnt[i] * price[i] * discount[i],
				cnt[i]*(price[i] - price[i] * discount[i]));
			total += cnt[i]*(price[i] - price[i] * discount[i]);
		}
	}
	printf_s("TOTAL = %.2f", total);
}