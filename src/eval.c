#include "eval.h"

int
eval(token **tokens)
{
  init_objects();
  init_io();
  init_string();

  //test
  object *string = new_string("Hello World");
  io_puts->apply_prefix(string);

  return 0;
}
