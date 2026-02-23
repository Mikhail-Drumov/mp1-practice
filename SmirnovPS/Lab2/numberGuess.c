#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int num, guess = -1, mode, tries = 0, left = 1, right = 1000, symbol = '*';
	srand((unsigned int)time(0));
	printf("Select a mode: You guess (1) or computer guesses (2)\n");
	scanf_s("%d", &mode);


	if (mode == 1) {
		num = rand() % 1000 + 1;
		while (guess != num) {
			printf("Enter your guess:\n");
			scanf_s("%d", &guess);
			if (guess > num) {
				printf("The correct number is smaller\n");
			}


			if (guess < num) {
				printf("The correct number is bigger\n");
			}

			tries++;
		}

		printf("You guessed the number! Number of tries: %d", tries);
		return 0;
	}


	if (mode == 2) {
		while (symbol != '=') {
			guess = rand() % (right - left + 1)  + left;
			printf("I think your number is: %d\n", guess);
			scanf_s(" %c", &symbol);
			if (symbol == '>') {
				left = guess + 1;
			}

			if (symbol == '<') {
				right = guess - 1;
			}
			tries++;
		}

		printf("Your number is: %d! Number of tries: %d", guess, tries);
		return 0;

	}
}