#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"
#include "library.h"

int *search_by_author(book* books, int book_cnt, int *found_cnt, char *author) {
	int i, j, *found_book_ids = (int *) malloc(book_cnt * sizeof(int));
	*found_cnt = 0;
	if (found_book_ids == NULL) {
		printf("malloc error while searching\n");
		return;
	}

	for (i = 0; i < book_cnt; i++) 
		if (strstr(books[i].authors, author) != NULL)
			found_book_ids[(*found_cnt)++] = i;
	
	found_book_ids = (int *) realloc(found_book_ids, *found_cnt * sizeof(int));
	return found_book_ids;
}

book *csv_to_books(csv tbl, int *book_cnt) {
	int i;
	book *books;
	*book_cnt = tbl.lines_cnt;
	books = (book *) malloc(tbl.lines_cnt * sizeof(book));
	for (i = 0; i < tbl.lines_cnt; i++) {
		books[i] = (book) {tbl.cells[i][0], tbl.cells[i][1], tbl.cells[i][2], atoi(tbl.cells[i][3])};
	}
	return books;
}

void print_book(book *book) {
	printf("\"%s\" authored by %s. ", book->title, book->authors);
	printf("Published by %s in the year %d.\n", book->publisher, book->year_published);
}