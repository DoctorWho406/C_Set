#include <stdio.h>

#define SET_NODE struct set_node
#define SET_TABLE struct set_table

SET_NODE {
    const char *key;
    size_t key_len ;
    SET_NODE *next;
};

SET_TABLE {
    SET_NODE **nodes;
    size_t hashmap_size;
};