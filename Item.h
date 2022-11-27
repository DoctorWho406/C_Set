#include <stdio.h>
#include "ListItem.h"

#define SET_NODE struct set_node
#define SET_TABLE struct set_table

SET_NODE {
    LIST_NODE *next;
    size_t key_len;
    const char *key;
};

SET_TABLE {
    SET_NODE **nodes;
    size_t hashmap_size;
};