#ifndef __SET_H
#define __SET_H

#include <stddef.h>
#include "linked_list.h"

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

EXPORTFUNC int set_table_create(set_table_t **, const size_t hashmap_size);

EXPORTFUNC int set_table_insert(set_table_t *, set_node_t *item, const size_t size_of_key);

EXPORTFUNC set_node_t *set_table_search(set_table_t *, set_node_t *item, const size_t size_of_key);

EXPORTFUNC set_node_t *set_table_remove(set_table_t *, set_node_t *item, const size_t size_of_key);

EXPORTFUNC void set_table_destroy(set_table_t *);
#endif //__SET_H