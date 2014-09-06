#include "string.h"

void
init_string()
{
  string_class = calloc(1, sizeof(object));
  string_class->class = basic_class;
  string_class->name = "StringClass";
  string_class->member_table = new_member_table(basic_class->member_table, 4);
}

object*
new_string(char *value)
{
  object *str = calloc(1, sizeof(object));
  str->class = string_class;
  str->type = TYPE_OBJECT | TYPE_STRING;
  str->string_value = strdup(value);
  return str;
}
