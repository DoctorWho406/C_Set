#include <stddef.h>
#include "Item.h"

SET_TABLE *set_table_new(const size_t hasmap_size);

SET_NODE *set_insert(SET_TABLE *table, const char *key, const size_t key_len);

SET_NODE *set_search(SET_TABLE *table, const char *key,  const size_t key_len);

struct set_node *set_remove(struct set_table *table, const char *key,  const size_t key_len);