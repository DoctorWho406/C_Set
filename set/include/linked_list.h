#ifndef __LIKED_LIST_H
#define __LIKED_LIST_H

#include <stddef.h>
typedef struct list_node {
    struct list_node *next;
} list_node_t;

#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

EXPORTFUNC void linked_list_append(list_node_t **head, list_node_t *item);

EXPORTFUNC list_node_t *linked_list_get_tail(list_node_t **head);

EXPORTFUNC list_node_t *linked_list_pop(list_node_t **head);

EXPORTFUNC list_node_t *linked_list_remove(list_node_t **head, list_node_t *item, size_t size_of_value);

EXPORTFUNC void linked_list_reverse(list_node_t **head);

#endif //__LIKED_LIST_H