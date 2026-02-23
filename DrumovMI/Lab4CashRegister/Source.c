#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LINE 512
#define ENTRY_SIZE 1000
#define str(x) # x

// function prototypes
int cmd_help (char *arg);
int cmd_scan (char *arg);
int cmd_view (char *arg);
int cmd_add  (char *arg);
int cmd_check(char *arg);
int cmd_total(char *arg);
int cmd_quit (char *arg);

// structs:
// check, entry, product --- actual program logic
// command --- command line processing
// state --- global state for program logic

struct product {
    const char* barcode;
    const char* name;
    int price, relative_discount;
};

struct check {
    struct entry {
        int product_index;
        int entry_amount, entry_cost;
    } entries[ENTRY_SIZE];
    int entry_count;
    int total_cost, absolute_discount;
    int final_cost;
};

struct command {
    const char* name;
    int (*handler)(char *);
};

struct program_state {
    bool has_product;
    int product_index;
    bool has_check;
    struct check current_check, final_check;
};

// ---------------------

// Product table
struct product products[] = {
  {"0000", "Apple",  20,  5},
  {"0001", "Banana", 50,  2},
  {"0002", "Orange", 30,  3}
};
int products_amount = sizeof(products) / sizeof(struct product);

// Command table
struct command commands[] = {
    { "help", cmd_help },
    { "scan", cmd_scan },
    { "view", cmd_view },
    {  "add", cmd_add  },
    {"check", cmd_check},
    {"total", cmd_total},
    { "quit", cmd_quit }
};
int commands_amount = sizeof(commands) / sizeof(struct command);

// Global state
struct program_state state = {
    .has_product = false,
    .has_check = false,
    .current_check = {
        .entry_count = 0,
        .total_cost = 0, .absolute_discount = 0,
        .final_cost = 0
    }
};

int main() {
    char query[LINE];

    while (true) {
        int i;
        char *arg;
        bool found;

        printf("> ");
        fgets(query, LINE, stdin);

        query[strcspn(query, "\n")] = 0;
        strtok(query, " ");
        arg = strtok(NULL, " ");

        for (i = 0; query[i]; i++)
            query[i] = tolower(query[i]);

        found = false;
        for (i = 0; i < commands_amount; i++)
            if (strcmp(commands[i].name, query) == 0) {
                found = true;
                commands[i].handler(arg);
            }

        if (!found)
            printf("Unknown command. Use HELP to view command list.\n");
    }
    return 0;
}

int cmd_help(char *arg) {
    printf("Available commands:\n"
            "HELP - prints out this command list\n"
            "SCAN [barcode] - scans a new product\n"
            "VIEW - prints information about a recently scanned product\n"
            "ADD [amount] - adds [amount] scanned products to the check\n"
            "CHECK - forms a check\n"
            "TOTAL - prints out the formed check\n"
            "QUIT - quits the program\n");
    return 0;
}

int cmd_scan(char *arg) {
    int i;

    if (arg == NULL) {
        printf("SCAN requires a 4-digit argument [barcode].\n");
        return 1;
    }

    if (strlen(arg) != 4) {
        printf("Invalid barcode length. Must be 4.\n");
        return 1;
    }

    for (i = 0; i < products_amount; i++) {
        if (strcmp(products[i].barcode, arg) == 0) {
            state.has_product = true;
            state.product_index = i;
            printf("Product %s - %s scanned.\n",
                   products[i].barcode, products[i].name);
            return 0;
        }
    }
    printf("Product with barcode %s was not found.\n", arg);
    return 1;
}

int cmd_view(char *arg) {
    struct product *scanned;

    if (state.has_product == false) {
        printf("Scan a product first.\n");
        return 1;
    }

    scanned = &products[state.product_index];
    printf("Barcode: %s\nName: %s\nPrice per item: %d\nDiscount: %d%%\n",
        scanned->barcode, scanned->name, scanned->price, scanned->relative_discount);
    return 0;
}

int cmd_add(char *arg) {
    int i;
    char *endptr;
    int amount;
    struct entry *entries = state.current_check.entries;
    struct product *scanned_product;

    if (!state.has_product) {
        printf("Scan a product first.\n");
        return 1;
    }

    scanned_product = &products[state.product_index];

    errno = 0;
    amount = (int) strtol(arg, &endptr, 10);
    if (errno != 0 || endptr == arg || amount <= 0) {
        printf("Invalid argument.\n");
        return 1;
    }

    for (i = 0; i < state.current_check.entry_count; i++) {
        struct product *entry_product = &products[entries[i].product_index];
        if (strcmp(entry_product->barcode, scanned_product->barcode) == 0) {
            entries[i].entry_amount += amount;
            entries[i].entry_cost += amount * scanned_product->price;
            printf("Product %s - %s (amount - %d) added to the check.\n",
                scanned_product->barcode, scanned_product->name, amount);
            return 0;
        }
    }

    if (state.current_check.entry_count < ENTRY_SIZE) {
        entries[state.current_check.entry_count++] = (struct entry) {
            state.product_index, amount, amount * scanned_product->price
        };
        printf("Product %s - %s (amount - %d) added to the check.\n",
            scanned_product->barcode, scanned_product->name, amount);
        return 0;
    }
    printf("Too many entries! (1000)\n");
    return 1;
}

int count_total_cost(struct check *check) {
    int cost = 0, i;
    for (i = 0; i < check->entry_count; i++)
        cost += check->entries[i].entry_cost;
    return cost;
}

int count_absolute_discount(struct check *check) {
    int discount = 0, i;
    for (i = 0; i < check->entry_count; i++) {
        struct product *p = &products[check->entries[i].product_index];
        discount += check->entries[i].entry_amount *
                p->price * p->relative_discount / 100;
    }
    return discount;
}

int cmd_check(char *arg) {
    struct check *cur = &state.current_check;

    cur->total_cost =
        count_total_cost(cur);
    cur->absolute_discount =
        count_absolute_discount(cur);
    cur->final_cost =
        cur->total_cost - cur->absolute_discount;
    state.final_check = state.current_check;
    state.has_check = true;
    printf("Check formed. Use TOTAL to print it out.\n");
    return 0;
}

int cmd_total(char *arg) {
    int i;
    struct check *fin = &state.final_check;

    if (!state.has_check) {
        printf("Check has not been formed yet. Use CHECK.\n");
        return 1;
    }

    for (i = 0; i < state.final_check.entry_count; i++) {
        struct entry entry = fin->entries[i];
        struct product *p = &products[entry.product_index];
        printf("%s - %s - %d - %d\n",
            p->barcode, p->name, entry.entry_amount, entry.entry_cost);
    }
    printf("-----------------\n");
    printf("TOTAL: %d\nDISCOUNT: %d\nFINAL: %d\n",
        fin->total_cost, fin->absolute_discount, fin->final_cost);
    return 1;
}

int cmd_quit(char *arg) {
    exit(0);
}
