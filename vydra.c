#include "token.h"

int
main(int argc, char **argv)
{
  FILE *file = fopen(argv[1], "r");

  int line_count;
  struct line* lines[255];

  tokenize(file, &line_count, lines);

  int i, t;
  for (i = 0; i < line_count; ++i) {
    struct line *l = lines[i];
    for (t = 0; t < l->token_count; t++) {
      printf("token %d, %d: %s\n", i, t, l->tokens[t]);
    }
  }

  return 0;
}
