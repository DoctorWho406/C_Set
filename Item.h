#include <stdio.h>
#include "ListItem.h"

typedef struct set_node {
    list_node_t *next;
    size_t key_len;
    const char *key;
} set_node_t;

typedef struct set_table {
    set_node_t **nodes;
    size_t hashmap_size;
} set_table_t;