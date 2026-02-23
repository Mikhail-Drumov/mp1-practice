#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

#define DEBUG

#define SALES_REGISTER_FRAME "\
|-----------------------------------------------------------------------------------------|\n\
|                                    Электронная касса                                    |\n\
|-----------------------------------------------------------------------------------------|\n\n"

#define MAIN_OPERATIONS "\
Список операций:\n\
1. Отсканировать товар\n\
2. Сформировать чек\n\
0. Выход\n\n"

#define ADD_CART_OPERATIONS "\
Операции:\n\
1. Добавить товар в корзину\n\
2. Назад\n\n"

#define EDIT_CART_OPERATIONS "\
Операции:\n\
1. Изменить количество товара\n\
2. Назад\n\n"

#define PAYMENT_OPERATIONS "\
Операции:\n\
1. Купить\n\
2. Назад\n\n"

struct Product {
    char barcode[5];
    char name[36];
    int price;
    int discount;
};

struct buyProductCounter {
    char barcode[5];
    int count;
};

#define COUNT_PRODUCTS 5

void printStartInfo(struct Product listProducts[], int n);
void addProductInShop(struct Product listProducts[], int indexAddProduct, char barcode[5], char name[36], int price, int discount);
void generateListBuyProductsCounter(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n);
void printProductsList(struct Product listProducts[], int n);
void scanningProduct(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n);
void receiptFormation(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n);

int main() {
    struct Product listProducts[COUNT_PRODUCTS];
    struct buyProductCounter listBuyProductsCounter[COUNT_PRODUCTS];
	setlocale(LC_ALL, "rus");
	addProductInShop(listProducts, 0, "1807", "Карандаш чернографитный", 15, 0);
    addProductInShop(listProducts, 1, "2007", "Шариковая ручка", 20, 0);
    addProductInShop(listProducts, 2, "1110", "Ластик", 25, 0);
    addProductInShop(listProducts, 3, "1991", "Металлическая линейка 15 см", 30, 20);
    addProductInShop(listProducts, 4, "0993", "Тетрадь в клетку 80 листов", 150, 29);
    generateListBuyProductsCounter(listProducts, listBuyProductsCounter, COUNT_PRODUCTS);

    while (1) {
        int operation;
        printStartInfo(listProducts, COUNT_PRODUCTS);
        printf(MAIN_OPERATIONS);

        printf("Введите операцию: ");
        scanf_s("%d", &operation);
        while (operation < 0 || operation > 2) {
            printf("Некорректная операция. Введите операцию: ");
            scanf_s("%d", &operation);
        }

        if (operation == 1) {
            scanningProduct(listProducts, listBuyProductsCounter, COUNT_PRODUCTS);
        }
        else if (operation == 2) {
            receiptFormation(listProducts, listBuyProductsCounter, COUNT_PRODUCTS);
        }
        else {
            break;
        }
    }

	return 0;
}

void printStartInfo(struct Product listProducts[], int n) {
    system("cls");
    printf(SALES_REGISTER_FRAME);
    printProductsList(listProducts, n);
}

void addProductInShop(struct Product listProducts[], int indexAddProduct, char barcode[5], char name[36], int price, int discount) {
    strcpy_s(listProducts[indexAddProduct].barcode, 5, barcode);
    strcpy_s(listProducts[indexAddProduct].name, 36, name);
    listProducts[indexAddProduct].price = price;
    listProducts[indexAddProduct].discount = discount;
}

void generateListBuyProductsCounter(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        strcpy_s(listBuyProductsCounter[i].barcode, 5, listProducts[i].barcode);
        listBuyProductsCounter[i].count = 0;
    }
}

void printProductsList(struct Product listProducts[], int n) {
    int i;
    printf("Список товаров:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s (штрихкод - %s)\n", i+1, listProducts[i].name, listProducts[i].barcode);
    }
    printf("\n");
}

int findProductByBarcode(struct Product listProducts[], int n, char barcode[5]);
int editCountProduct(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int indexProductByBarcode, int isProductInCart);

void scanningProduct(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n) {
    int indexProductByBarcode;
    int isProductInCart;
    char barcode[5];
    int operation;

    printStartInfo(listProducts, n);
    printf("Введите штрихкод: ");
    scanf_s("%4s", barcode, 5);
    while (getchar() != '\n');
    indexProductByBarcode = findProductByBarcode(listProducts, n, barcode);
    while (indexProductByBarcode == -1) {
        printf("Товара с таким штрихкодом не существует!\nВведите штрихкод: ");
        scanf_s("%4s", barcode, 5);
        while (getchar() != '\n');
        indexProductByBarcode = findProductByBarcode(listProducts, n, barcode);
    }

    printStartInfo(listProducts, n);
    printf("Информация о товаре со штрихкодом %s:\n", barcode);
    printf("Наименование: %s\n", listProducts[indexProductByBarcode].name);

    if (listProducts[indexProductByBarcode].discount == 0) {
        printf("Цена: %d руб.\n", listProducts[indexProductByBarcode].price);
        printf("Скидка: отсутствует\n\n");
    }
    else {
        printf("Цена без скидки: %d руб.\n", listProducts[indexProductByBarcode].price);
        printf("Скидка: %d%%\n", listProducts[indexProductByBarcode].discount);
        printf("Цена со скидкой: %d руб.\n\n", (int)(listProducts[indexProductByBarcode].price * (100 - listProducts[indexProductByBarcode].discount) / 100.0));
    }
    Sleep(3000);
    isProductInCart = listBuyProductsCounter[indexProductByBarcode].count != 0;
    if (isProductInCart) {
        printf("Количество товара \"%s\" в корзине: %d\n", listProducts[indexProductByBarcode].name, listBuyProductsCounter[indexProductByBarcode].count);
    }
    printf(!isProductInCart ? ADD_CART_OPERATIONS : EDIT_CART_OPERATIONS);
    printf("Введите операцию: ");
    scanf_s("%d", &operation);
    while (operation < 1 || operation > 2) {
        printf("Некорректная операция. Введите операцию: ");
        scanf_s("%d", &operation);
    }

    if (operation == 1) {
        editCountProduct(listProducts, listBuyProductsCounter, indexProductByBarcode, isProductInCart);
    }
}

int findProductByBarcode(struct Product listProducts[], int n, char barcode[5]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(listProducts[i].barcode, barcode) == 0) {
            return i;
        }
    }
    return -1;
}

int editCountProduct(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int indexProductByBarcode, int isProductInCart) {
    int count;
    int minCount = !isProductInCart ? 1 : 0;
    printf("Введите количество товара (от %d до 50): ", minCount);
    scanf_s("%d", &count);
    while (count < minCount || count > 50) {
        printf("Некорректное количество. Введите количество товара (от %d до 50): ", minCount);
        scanf_s("%d", &count);
    }
    listBuyProductsCounter[indexProductByBarcode].count = count;
    if (!isProductInCart) {
        printf("Товар \"%s\" (x%d) успешно добавлен в корзину!\n\n", listProducts[indexProductByBarcode].name, count);
    }
    else {
        printf("Количество товара \"%s\" успешно изменено!\n\n", listProducts[indexProductByBarcode].name);
    }
    system("pause");
}

int isCartEmpty(struct buyProductCounter listBuyProductsCounter[], int n);

void receiptFormation(struct Product listProducts[], struct buyProductCounter listBuyProductsCounter[], int n) {
    int i, finalPrice = 0, finalPriceIncludingDiscount = 0;
    int operation;
    printStartInfo(listProducts, n);
    if (isCartEmpty(listBuyProductsCounter, n)) {
        printf("Корзина пуста!\n\n");
        system("pause");
        return;
    }

    printf("|-----------------------------------------------------------------------------------------|\n");
    printf("|                                     Электронный чек                                     |\n");
    printf("|-------------------------------------O--------O--------------O------------O--------------|\n");
    printf("| Наименование                        | Скидка | Цена         | Количество | Сумма        |\n");
    for (i = 0; i < n; i++) {
        if (listBuyProductsCounter[i].count != 0) {
            char name[35];
            int price = listProducts[i].price;
            int discount = listProducts[i].discount;
            int count = listBuyProductsCounter[i].count;
            int priceIncludingDiscount = discount == 0 ? price : (int)(price * (100 - discount) / 100.0);
            int sumPrice = priceIncludingDiscount * count;
            strcpy_s(name, 35, listProducts[i].name);
            printf("|-------------------------------------|--------|--------------|------------|--------------|\n");
            printf("| %-36s| %-5d%% | %-7d РУБ. | %-6d ШТ. | %-7d РУБ. |\n", name, discount, priceIncludingDiscount, count, sumPrice);
            finalPrice += price * count;
            finalPriceIncludingDiscount += sumPrice;
        }
    }
    printf("|-------------------------------------O--------O--------------O------------O--------------|\n");
    printf("| ИТОГО: %-76dРУБ. |\n", finalPriceIncludingDiscount);
    if (finalPriceIncludingDiscount < finalPrice) {
        printf("| БЕЗ СКИДОК: %-71dРУБ. |\n", finalPrice);
        printf("| ЭКОНОМИЯ: %-73dРУБ. |\n", finalPrice - finalPriceIncludingDiscount);
    }
    printf("|-----------------------------------------------------------------------------------------|\n\n");

    printf(PAYMENT_OPERATIONS);
    printf("Введите операцию: ");
    scanf_s("%d", &operation);
    while (operation < 1 || operation > 2) {
        printf("Некорректная операция. Введите операцию: ");
        scanf_s("%d", &operation);
    }

    if (operation == 1) {
        printf("Покупка успешно совершена! С Вашего счета списано %d руб.\n\n", finalPriceIncludingDiscount);
        generateListBuyProductsCounter(listProducts, listBuyProductsCounter, n);
        system("pause");
    }
}

int isCartEmpty(struct buyProductCounter listBuyProductsCounter[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (listBuyProductsCounter[i].count != 0) {
            return 0;
        }
    }
    return 1;
}