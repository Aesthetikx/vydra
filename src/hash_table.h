#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "object.h"

uint32_t
hash(char *value);

typedef struct hash_table_entry hash_table_entry;
typedef struct hash_table hash_table;

typedef struct object object;

struct hash_table {
  int size;
  hash_table_entry **entries;
};

struct hash_table_entry {
  char *key;
  object *value;
  hash_table_entry *next;
};

hash_table*
new_hash_table(int size);

hash_table_entry*
new_entry(char *key, object *value);

object*
hash_table_get(hash_table *table, char *key);

void
hash_table_set(hash_table *table, char *key, object *value);

#endif
