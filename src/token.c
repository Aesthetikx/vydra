#include "token.h"

void
init_tokens() {
  tokens = malloc(64 * sizeof(token*));
  tokens_size = 64;
  token_count = 0;
}

void
new_token(int type, int line_no, char *value)
{
  if (token_count <= tokens_size) {
    tokens_size *= 1.5;
    tokens = realloc(tokens, (tokens_size) * sizeof(token*));
  }

  tokens[token_count] = malloc(sizeof(token));

  token* t = tokens[token_count];
  t->type = type;
  t->line_no = line_no;
  t->value = malloc(strlen(value) * sizeof(char) + 1);
  strcpy(t->value, value);

  token_count++;
}
