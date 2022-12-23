#include <stddef.h>
#include <stdio.h>
#include "LinkedList.h"

#ifndef __SET_H
#define __SET_H

typedef struct set_node {
    list_node_t node;
} set_node_t;

typedef struct set_table {
    set_node_t **nodes;
    size_t hashmap_size;
} set_table_t;

#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

EXPORTFUNC set_table_t *set_table_new(const size_t hasmap_size);

EXPORTFUNC set_node_t *set_table_insert(set_table_t *table, set_node_t *item, const size_t size_of_key);

EXPORTFUNC set_node_t *set_table_search(set_table_t *table, set_node_t *item, const size_t size_of_key);

EXPORTFUNC set_node_t *set_table_remove(set_table_t *table, set_node_t *item, const size_t size_of_key);

#endif //__SET_H