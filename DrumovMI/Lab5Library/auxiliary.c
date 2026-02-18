#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

int read_csv(FILE *file, csv *tbl) {
	int i, line;
	char *start;
	int len = 0;
	if (tbl == NULL || file == NULL)
		return 1;
	tbl->str = NULL;
	if (fseek(file, 0L, SEEK_END) == 0) {
		long bufsize = ftell(file);
		tbl->str = (char *) malloc((bufsize + 1) * sizeof(char));
		if (tbl->str == NULL)
			return 1;
		fseek(file, 0L, SEEK_SET);
		len = fread(tbl->str, sizeof(char), bufsize, file);
		tbl->str[len++] = '\0';
	}

	// parse
	tbl->lines_cnt = 0;
	for (i = 0; i < len; i++) {
		if (tbl->str[i] == '\n' || tbl->str[i] == '\0')
			tbl->lines_cnt++;
	}
	tbl->cells_cnt = (int *) malloc(tbl->lines_cnt * sizeof(int));
	tbl->cells = (char ***) malloc(tbl->lines_cnt * sizeof(char **));

	for (i = 0; i < tbl->lines_cnt; i++)
		tbl->cells_cnt[i] = 1;

	start = tbl->str;
	for (line = 0; line < tbl->lines_cnt; line++) {
		char *ch, *pcell;
		int cell = 0;
		
		for (ch = start; *ch != '\n' && *ch != '\0'; ch++)
			if (*ch == ';')
				tbl->cells_cnt[line]++;
		*ch = '\0';

		tbl->cells[line] = (char **) malloc(tbl->cells_cnt[line] * sizeof(char*));
		pcell = start;
		pcell = strtok(pcell, ";");
		for (i = 0; i < tbl->cells_cnt[line]; i++) {
			tbl->cells[line][i] = pcell;
			pcell = strtok(NULL, ";");
		}
		start = ch + 1;
	}
	return 0;
}
