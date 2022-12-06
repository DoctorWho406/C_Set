#include <stdio.h>
#include "Functions.h"

int main() {
    set_table_t *set = set_table_new(2);

    set_table_insert(set, "Hello", 5);
    set_table_insert(set, "World", 5);
    set_table_insert(set, "Hello World", 11);
    set_table_insert(set, "Good", 4);


    printf("==========SET==========\n");
    set_node_t **current_nodes = set->nodes;
    size_t index = 0;
    set_node_t *head_node;
    for (size_t index = 0; index < set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            set_node_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->key);
                current_node = (set_node_t *)current_node->next;
            }
        }
    }

    set_node_t *finded = set_table_search(set, "Good", 4);
    if (!finded) {
        printf("Node not founded\n");
    } else {
        printf("Founded %s\n", finded->key);
    }

    set_table_remove(set, "Hello World", 11);
    set_table_remove(set, "Goods", 5);
    printf("==========REMOVE FROM SET==========\n");
    index = 0;
    for (size_t index = 0; index < set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            set_node_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->key);
                current_node = (set_node_t *)current_node->next;
            }
        }
    }

    set_table_insert(set, "World", 5);
    printf("==========INSERT DUPLICATE SET==========\n");
    index = 0;
    for (size_t index = 0; index < set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            set_node_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->key);
                current_node = (set_node_t *)current_node->next;
            }
        }
    }
}