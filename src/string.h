#ifndef STRING_H
#define STRING_H

#include <string.h>
#include "object.h"

void
init_string();

object*
new_string(char *value);

object *string_class;

#endif
