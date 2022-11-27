#include <stddef.h>
#include "ListItem.h"

LIST_NODE *list_get_tail(LIST_NODE **head);

LIST_NODE *list_append(LIST_NODE **head, LIST_NODE *item);

LIST_NODE *list_pop(LIST_NODE **head);

LIST_NODE *list_remove(LIST_NODE **head, LIST_NODE *item);

LIST_NODE *list_reverse(LIST_NODE **head);