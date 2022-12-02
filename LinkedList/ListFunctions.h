#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

#define INIT_LIST_NODE

#include "ListItem.h"

EXPORTFUNC list_node_t *list_get_tail(list_node_t **head);

EXPORTFUNC list_node_t *list_append(list_node_t **head, list_node_t *item);

EXPORTFUNC list_node_t *list_pop(list_node_t **head);

EXPORTFUNC list_node_t *list_remove(list_node_t **head, list_node_t *item);

EXPORTFUNC list_node_t *list_reverse(list_node_t **head);