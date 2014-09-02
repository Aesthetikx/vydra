#ifndef OBJECT_H
#define OBJECT_H

// Applier flags
const int APPLY = 1;
const int APPLY_PREFIX = 2;
const int APPLY_INFIX = 4;
const int APPLY_POSTFIX = 8;

typedef struct object object;

struct object {
  object *class;
  char *name;
  int type;

  member_table *members;

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

#endif
