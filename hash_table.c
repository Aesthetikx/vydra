#include "hash_table.h"

uint32_t
hash(char *value)
{
  uint32_t hash = 5381;

  int c;

  while (c = *value++)
  {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}

hash_table*
new_hash_table(int size)
{
  hash_table *table = malloc(sizeof(hash_table));
  if (!table) {
    return 0x0;
  }

  table->entries = calloc(size, sizeof(hash_table_entry*));
  if (!table->entries) {
    return 0x0;
  }

  table->size = size;

  return table;
}

hash_table_entry*
new_entry(char *key, object *value)
{
  hash_table_entry *entry = malloc(sizeof(hash_table_entry));
  if (!entry) {
    return 0x0;
  }

  entry->key = strdup(key);
  entry->value = value;
  entry->next = 0x0;

  return entry;
}

object*
hash_table_get(hash_table *table, char *key)
{
  hash_table_entry *entry;
  uint32_t bin = hash(key) % table->size;

  entry = table->entries[bin];
  while (entry && strcmp(key, entry->key) > 0) {
    entry = entry->next;
  }

  if (entry == 0x0 || strcmp(key, entry->key) != 0) {
    return 0x0;
  }

  return entry->value;
}

void
hash_table_set(hash_table *table, char *key, object *value)
{
  uint32_t bin = hash(key) % table->size;

  hash_table_entry *next = 0x0;
  hash_table_entry *last = 0x0;

  next = table->entries[bin];

  while (next && strcmp(key, next->key) > 0) {
    last = next;
    next = next->next;
  }

  if (next && strcmp(key, next->key) == 0) {
    // Existing entry
    next->value = value;

  } else {
    // New entry
    hash_table_entry *new = new_entry(key, value);

    if (next == table->entries[bin]) {
      // We're at the start of the linked list in this bin.
      new->next = next;
      table->entries[bin] = new;

    } else if (next == 0x0) {
      // We're at the end of the linked list in this bin.
      last->next = new;

    } else {

      // We're in the middle of the list.
      new->next = next;
      last->next = new;
    }
  }
}
