#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

#include <stddef.h>
#include "ListItem.h"

EXPORTFUNC list_node_t *list_get_tail(list_node_t **head) {
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

EXPORTFUNC list_node_t *list_append(list_node_t **head, list_node_t *item) {
    list_node_t *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

EXPORTFUNC list_node_t *list_pop(list_node_t **head) {
    list_node_t *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

EXPORTFUNC list_node_t *list_remove(list_node_t **head, list_node_t *item) {
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


EXPORTFUNC list_node_t *list_reverse(list_node_t **head) {
    list_node_t *curr_node = *head;
    list_node_t *prev_node = NULL;
    list_node_t *next_node = NULL;

    while(curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;
}