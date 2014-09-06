#include "io.h"

static
object*
io_puts_apply()
{
  printf("\n");
  return nil_object;
}

static
object*
io_puts_apply_prefix(object *right)
{
  //printf("%s\n", right->call("to_s")->string_value);
  printf("%s\n", right->string_value);
  return nil_object;
}

void
init_io()
{
  // puts
  io_puts = calloc(1, sizeof(object));
  io_puts->class = basic_class;
  io_puts->name = "puts";
  io_puts->type = TYPE_FUNCTION;
  io_puts->apply_mode = APPLY | APPLY_PREFIX;
  io_puts->apply = &io_puts_apply;
  io_puts->apply_prefix = &io_puts_apply_prefix;
}
