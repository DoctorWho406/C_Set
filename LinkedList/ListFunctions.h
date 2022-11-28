#include "ListItem.h"
#define INIT_LIST_NODE

list_node_t *list_get_tail(list_node_t **head);

list_node_t *list_append(list_node_t **head, list_node_t *item);

list_node_t *list_pop(list_node_t **head);

list_node_t *list_remove(list_node_t **head, list_node_t *item);

list_node_t *list_reverse(list_node_t **head);