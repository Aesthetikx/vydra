#include "object.h"

#include "env.h"

const int APPLY = 1;
const int APPLY_PREFIX = 2;
const int APPLY_INFIX = 4;
const int APPLY_POSTFIX = 8;

const int TYPE_OBJECT = 1;
const int TYPE_FUNCTION = 2;
const int TYPE_STRING = 4;
const int TYPE_INTEGER = 8;
const int TYPE_FLOAT = 16;

void
init_objects()
{
  basic_object = calloc(1, sizeof(object));
  basic_class = calloc(1, sizeof(object));
  nil_class = calloc(1, sizeof(object));
  nil_object = calloc(1, sizeof(object));

  // BasicObject
  basic_object->class = basic_class;
  basic_object->name = "Object";
  basic_object->member_table = new_member_table(0x0, 64);
  hash_table_set(root_symbol_table->members, basic_object->name, basic_object);

  // BasicClass
  basic_class->class = basic_class;
  basic_class->name = "Class";
  basic_class->member_table = new_member_table(basic_object->member_table, 4);
  hash_table_set(root_symbol_table->members, basic_class->name, basic_class);

  // NilClass
  nil_class->class = basic_class;
  nil_class->name = "NilClass";
  nil_class->member_table = new_member_table(basic_class->member_table, 4);
  hash_table_set(root_symbol_table->members, nil_class->name, nil_class);

  // NilObject
  nil_object->class = nil_class;
  nil_object->name = "NilObject";
  nil_object->member_table = new_member_table(basic_object->member_table, 4);
  hash_table_set(root_symbol_table->members, nil_object->name, nil_object);
}
