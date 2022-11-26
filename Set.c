#include <stdio.h>
#include "Functions.h"

int main() {
    SET_TABLE *set = set_table_new(2);
    
    set_insert(set, "Hello", 5);
    set_insert(set, "World", 5);
    set_insert(set, "Hello World", 11);
    set_insert(set, "Good", 4);

    
    printf("==========SET==========\n");
    SET_NODE **current_nodes = set->nodes;
    size_t index = 0;
    SET_NODE *head_node;
    for (size_t index = 0; index < set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            SET_NODE *current_node = head_node;
            while(current_node) {
                printf("\t%s\n", current_node->key);
                current_node = current_node->next;
            }
        }
    }
    
    SET_NODE *finded = set_search(set, "Good", 4);
    if(!finded) {
        printf("Node not founded\n");
    } else {
        printf("Founded %s\n", finded->key);
    }

    set_remove(set, "Hello World", 11);
    printf("==========REMOVE FROM SET==========\n");
    index = 0;
    for (size_t index = 0; index < set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            SET_NODE *current_node = head_node;
            while(current_node) {
                printf("\t%s\n", current_node->key);
                current_node = current_node->next;
            }
        }
    }
}