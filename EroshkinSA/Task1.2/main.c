#include <stdio.h>
#include <math.h>
#include <new.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int castle(int x1, char y1, int x2, char y2) {
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2)) return 1;
	return 0;
}

int king(int x1, char y1, int x2, char y2) {
	if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1) return 1;
	return 0;
}

int bishop(int x1, char y1, int x2, char y2) {
	if (abs(x2 - x1) == abs(y2 - y1)) return 1;
	return 0;
}

int knight(int x1, char y1, int x2, char y2) {
	if ((abs(x2 - x1) == 1 && abs(y2 - y1) == 2) ||
		(abs(x2 - x1) == 2 && abs(y2 - y1) == 1)) return 1;
	return 0;
}

int queen(int x1, char y1, int x2, char y2) {
	if (castle(x1, y1, x2, y2) ||
		king(x1, y1, x2, y2) ||
		bishop(x1, y1, x2, y2)) return 1;
	return 0;
}

void reach(int x1, char y1, int x2, char y2) {
	if (king(x1, y1, x2, y2)) printf("king ");
	if (queen(x1, y1, x2, y2)) printf("queen ");
	if (bishop(x1, y1, x2, y2)) printf("bishop ");
	if (castle(x1, y1, x2, y2)) printf("castle ");
	if (knight(x1, y1, x2, y2)) printf("knight ");
}

int main() {
	int x1, x2, n = 0, i, a, b, c;
	char y1, y2, trash;
	char figure[50];
	char* fig;
	do {
		scanf_s("%c", &y1);
		scanf_s(" %d", &x1);
		scanf_s(" %c", &y2);
		scanf_s(" %d%c", &x2, &trash);
	} while (y1 < 'a' || y1 > 'h' || y2 < 'a' || y2 > 'h' ||
		x1 < 1 || x1 > 8 || x2 < 1 || x2 > 8);
	do {
		scanf_s("%c", &figure[n]);
	} while (figure[n++] != '\n');
	n--;
	fig = (char*)malloc(n * sizeof(char));
	for (i = 0; i < n; i++) {
		fig[i] = figure[i];
	}
	fig[n] = '\0';
	if (strcmp(fig, "king") == 0) {
		if (king(x1, y1, x2, y2)) {
			printf("Yes");
			return 0;
		}
		printf("No\n");
		reach(x1, y1, x2, y2);
		return 0;
	}
	if (strcmp(fig, "queen") == 0) {
		if (queen(x1, y1, x2, y2)) {
			printf("Yes");
			return 0;
		}
		printf("No\n");
		reach(x1, y1, x2, y2);
		return 0;
	}
	if (strcmp(fig, "bishop") == 0) {
		if (bishop(x1, y1, x2, y2)) {
			printf("Yes");
			return 0;
		}
		printf("No\n");
		reach(x1, y1, x2, y2);
		return 0;
	}
	if (strcmp(fig, "castle") == 0) {
		if (castle(x1, y1, x2, y2)) {
			printf("Yes");
			return 0;
		}
		printf("No\n");
		reach(x1, y1, x2, y2);
		return 0;
	}
	if (strcmp(fig, "knight") == 0) {
		if (knight(x1, y1, x2, y2)) {
			printf("Yes");
			return 0;
		}
		printf("No\n");
		reach(x1, y1, x2, y2);
		return 0;
	}
	printf("figure %s doesn't exist", fig);
	// CASTLE, KING, BISHOP, KNIGHT, QUEEN

	// Âñå ôèãóðû îòëè÷àþòñÿ ñâîåé ïîñëåäíåé áóêâîé, çíà÷èò ÿ ìîãó ñ÷èòûâàòü áóêâû ñòîëüêî ñêîëüêî çàõî÷ó è èíèöèàëèçèðîâàòü ôèãóðó ïî ïîñëåäíåé áóêâå
	// Åñëè ìíå ââîäÿò êàêóþ-òî ÷óõíþ, ïîñëåäíÿÿ áóêâà êîòîðîé ñîâïàäàåò ñ êàêîé òî èç "ôèãóðíûõ", òî ÿ ïðîèãðûâàþ!!
	return 0;
}
