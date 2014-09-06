#ifndef OBJECT_H
#define OBJECT_H

#include "member_table.h"

// Applier flags
extern const int APPLY;
extern const int APPLY_PREFIX;
extern const int APPLY_INFIX;
extern const int APPLY_POSTFIX;

extern const int TYPE_OBJECT;
extern const int TYPE_FUNCTION;
extern const int TYPE_STRING;
extern const int TYPE_INTEGER;
extern const int TYPE_FLOAT;

typedef struct object object;

struct object {
  object *class;
  char *name;
  int type;

  struct member_table *member_table;

  int apply_mode;
  object* (*apply)();
  object* (*apply_prefix)(object *);
  object* (*apply_infix)(object *, object *);
  object* (*apply_postfix)(object *);

  object* (*call)(char *);

  char *string_value;
  int int_value;
  double double_value;
};

void
init_objects();

object *basic_object;
object *basic_class;
object *nil_class;
object *nil_object;

#endif
