#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LEN 2
#define MAX_LEN 5

int gen(int guess);
int valid(int secret_number, int guess);
int get_cows(int secret_number, int guess, int len);
int get_bulls(int secret_number, int guess, int len);

int main()
{
    srand((unsigned int) time(NULL));
    int len;
    do {
        printf("Enter secret_number length: ");
        scanf_s("%d", &len);
    } while (len < MIN_LEN || len > MAX_LEN);
    int secret_number;
    do {
        secret_number = gen(len);
    } while (!valid(secret_number, len));
    int guess;
    do {
        do {
            printf("Enter your guess: ");
            scanf_s("%d", &guess);
        } while (guess < 0 || !valid(guess, len));
        printf("cows: %d, bulls: %d\n", get_cows(secret_number, guess, len), get_bulls(secret_number, guess, len));
    } while (secret_number != guess);
    printf("You win!");
}

int gen(int len) {
    int i;
    int res = 0;
    for (i = 0; i < len; i++) {
        res *= 10;
        res += rand() % 10;
    }
    return res;
}

int valid(int n, int len) {
    if (n < 0) return 0;

    int digits[10] = { 0 };
    int count = 0;

    while (n > 0) {
        int digit = n % 10;
        if (digits[digit] > 0) return 0;
        digits[digit]++;
        count++;
        n /= 10;
    }

    return count == len;
}

int get_cows(int secret_number, int guess, int len) {
    char secret_number_str[MAX_LEN +1];
    char tmp_str[MAX_LEN +1];
    sprintf_s(secret_number_str, MAX_LEN +1, "%d", secret_number);
    sprintf_s(tmp_str, MAX_LEN + 1, "%d", guess);
    int i, j, count = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (secret_number_str[i] == tmp_str[j]) {
                count++;
                break;
            }
        }
    }
    return count - get_bulls(secret_number, guess, len);
}

int get_bulls(int secret_number, int guess, int len) {
    char secret_number_str[MAX_LEN + 1];
    char tmp_str[MAX_LEN + 1];
    sprintf_s(secret_number_str, MAX_LEN + 1, "%d", secret_number);
    sprintf_s(tmp_str, MAX_LEN + 1, "%d", guess);
    int i, count = 0;
    for (i = 0; i < len; i++) {
        if (secret_number_str[i] == tmp_str[i]) {
            count++;
        }
    }
    return count;
}
