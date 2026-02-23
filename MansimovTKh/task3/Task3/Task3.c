#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int len(int a);
void print(int b[], int n);

int main() {
    int n, i, j, digit, userGuess, endgame = 0;
    int number[5];
    srand((unsigned int)time(0));
    while (1) {
        int digits[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        printf("Input number from 2 to 5: "); scanf_s("%d", &n);
        while (n < 2 || n>5) {
            printf("\nInput correct number from 2 to 5: "); scanf_s("%d", &n);
        }
        digit = rand() % 10;
        if (digit == 0) {
            digit = 1 + rand() % 9;
        }
        digits[digit] = 1;
        number[0] = digit;
        for (i = 1; i < n; i++) {
            digit = rand() % 10;
           
            while (digits[digit] != 0) {
                digit = rand() % 10;
            }
            digits[digit] = 1;
            number[i] = digit;
        }
        print(number, n);
        printf("\nA number with length %d is hidden. Try to guess it\n", n);

        while (1) {
            printf("Input your guess with %d unique digits: ", n); scanf_s("%d", &userGuess);
            int userGuessNumber[5], cow, bull;
            int ds[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, flag = 0, userGuessForCheck = userGuess;  
            cow = 0; bull = 0;
            while (userGuessForCheck != 0) {
                int d = userGuessForCheck % 10;
                if ((ds[d] == 1) || (len(userGuess) != n)) {   
                    flag = 1;
                    break;
                }
                ds[d] = 1;
                userGuessForCheck /= 10;
            }

            if (flag == 0) {   
                i = n - 1;
                while (userGuess != 0) {
                    userGuessNumber[i--] = userGuess % 10;
                    userGuess /= 10;
                }
                
                cow = 0; bull = 0;
                for (i = 0; i < n; i++) {

                    if (number[i] == userGuessNumber[i]) bull++;

                    for (j = 0; j <= i - 1; j++) {
                        
                        if ((number[i] == userGuessNumber[j])) cow++;
                    }
                    for (j = i + 1; j < n; j++) {
                        if ((number[i] == userGuessNumber[j])) cow++;
                    }
                }
                printf("%d cow   %d bull\n", cow, bull);
                if (bull == n) {
                    printf("Congratulations! You guessed number right!\n");
                    endgame = 1;
                    break;
                }
            }

        }
        if (endgame) {
            break;
        }
    }
    return 0;
}


int len(int a) {
    if (a == 0) return 1;
    int l = 0;
    while (a) {
        l++;
        a /= 10;
    }
    return l;
}

void print(int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", b[i]);
    }
}