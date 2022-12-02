
#include <stddef.h>
#include "ListFunctions.h"

list_node_t *list_get_tail(list_node_t **head) {
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item) {
    list_node_t *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

list_node_t *list_remove(list_node_t **head, list_node_t *item) {
    list_node_t *current_node = *head;
    while(current_node->next != item) {
        current_node = current_node->next;
    }
    if(!current_node) { // scroll all and not find item
        return NULL;
    }
    list_node_t *removed = current_node->next;
    current_node->next = current_node->next->next;
    removed->next = NULL;
    return removed;
}