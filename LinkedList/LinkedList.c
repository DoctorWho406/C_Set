#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

#include <stddef.h>
#include "ListItem.h"

LIST_NODE {
    struct list_node *next;
};

EXPORTFUNC LIST_NODE *list_get_tail(LIST_NODE **head) {
    LIST_NODE *current_node = *head;
    LIST_NODE *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

EXPORTFUNC LIST_NODE *list_append(LIST_NODE **head, LIST_NODE *item) {
    LIST_NODE *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

EXPORTFUNC LIST_NODE *list_pop(LIST_NODE **head) {
    LIST_NODE *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

EXPORTFUNC LIST_NODE *list_remove(LIST_NODE **head, LIST_NODE *item) {
    LIST_NODE *current_node = *head;
    while(current_node->next != item) {
        current_node = current_node->next;
    }
    if(!current_node) { // scroll all and not find item
        return NULL;
    }
    LIST_NODE *removed = current_node->next;
    current_node->next = current_node->next->next;
    removed->next = NULL;
    return removed;
}


EXPORTFUNC LIST_NODE *list_reverse(LIST_NODE **head) {
    LIST_NODE *curr_node = *head;
    LIST_NODE *prev_node = NULL;
    LIST_NODE *next_node = NULL;

    while(curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    return prev_node;
}