#ifndef __LIBRARY_H
#define __LIBRARY_H

#include "auxiliary.h"

typedef struct _book {
    char   *authors;
    char   *title;
    char   *publisher;
    int     year_published;
} book;

int *search_by_author(book* books, int book_cnt, int* found_cnt, char* author);
book *csv_to_books(csv tbl, int *book_cnt);
void print_book(book *book);

#endif