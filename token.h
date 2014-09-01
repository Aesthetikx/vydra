#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const static int TOKEN_NUMBER = 1;
const static int TOKEN_SYMBOL = 2;

struct token {
  int type;
  int line_no;
  char *value;
};

struct token **tokens;
int token_count;
int tokens_size;

void
init_tokens();

void
new_token(int type, int line_no, char *value);

#endif
