#include "object.h"

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

  // BasicClass
  basic_class->class = basic_class;
  basic_class->name = "Class";
  basic_class->member_table = new_member_table(basic_object->member_table, 4);

  // NilClass
  nil_class->class = basic_class;
  nil_class->name = "NilClass";
  nil_class->member_table = new_member_table(basic_class->member_table, 4);

  // NilObject
  nil_object->class = nil_class;
  nil_object->name = "NilObject";
  nil_object->member_table = new_member_table(basic_object->member_table, 4);
}
