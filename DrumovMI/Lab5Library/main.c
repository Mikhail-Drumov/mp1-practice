#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

int main() {
	csv cards_tbl;
	book *books;
	int book_cnt;
	FILE *cardfile;

	while (true) {
		char filename[512];
		printf("filename: ");
		fgets(filename, 512, stdin);
		filename[strcspn(filename, "\n")] = '\0';
		cardfile = fopen(filename, "r");
		if (cardfile == NULL) {
			printf("error opening file %s\n", filename);
		} else {
			printf("file %s opened successfully\n", filename);
			break;
		}
	}

	if (read_csv(cardfile, &cards_tbl)) {
		printf("error reading csv\n");
		return 1;
	}
	fclose(cardfile);
	books = csv_to_books(cards_tbl, &book_cnt);

	while (true) {
		char author[512];
		int *book_ids;
		int found_cnt;
		int i;

		printf("author: ");
		fgets(author, 512, stdin);
		author[strcspn(author, "\n")] = '\0';
		if (!strcmp(author, "exit"))
			break;
		book_ids = search_by_author(books, book_cnt, &found_cnt, author);
		if (found_cnt == 0) {
			printf("no books with this author\n");
		} else if (found_cnt == 1)  {
			printf("found %d book by %s:\n", found_cnt, author);
		} else {
			printf("found %d books by %s:\n", found_cnt, author);
		}
		
		for (i = 0; i < found_cnt; i++)
			print_book(books + book_ids[i]);
		free(book_ids);
	}
	
}