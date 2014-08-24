#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
  int token_count;
  char **tokens;
};

void tokenize(FILE *file, int *line_count, struct line **lines);

#endif
