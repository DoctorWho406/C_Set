#include <stddef.h>
#include "Item.h"

set_table_t *set_table_new(const size_t hasmap_size);

set_node_t *set_table_insert(set_table_t *table, const char *key, const size_t key_len);

set_node_t *set_table_search(set_table_t *table, const char *key,  const size_t key_len);

struct set_node *set_table_remove(struct set_table *table, const char *key,  const size_t key_len);