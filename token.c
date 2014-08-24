#include "token.h"

void
tokenize(FILE *file, int *line_count, struct line **lines)
{
  *line_count = 0;

  char str[255];

  while (fgets(str, sizeof str, file)) {
    struct line *l = malloc(sizeof(struct line));

    l->tokens = malloc(64 * sizeof(char*));

    static char *delim = " .\n";
    char *token = strtok(str, delim);

    int c = 0;
    while (token) {
      l->tokens[c] = malloc(strlen(token) * sizeof(char) + 1);
      strcpy(l->tokens[c], token);
      ++c;
      token = strtok(0x0, delim);
    }

    l->token_count = c;

    lines[*line_count] = l;
    ++(*line_count);
  }
}
