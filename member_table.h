#ifndef MEMBER_TABLE_H
#define MEMBER_TABLE_H

#include "hash_table.h"

typedef struct member_table member_table;

struct member_table {
  member_table *parent;
  struct hash_table *members;
};

member_table*
new_member_table(member_table *parent, int size);

#endif
