#ifndef __AUXILIARY_H
#define __AUXILIARY_H

typedef struct _csv {
	char   *str;
	char ***cells;
	int     lines_cnt;
	int    *cells_cnt;
} csv;

int read_csv(FILE *file, csv *tbl);

#endif