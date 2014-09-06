#include "member_table.h"

member_table*
new_member_table(member_table *parent, int size)
{
  member_table *table = malloc(sizeof(member_table));
  table->parent = parent;
  table->members = new_hash_table(size);
  return table;
}
