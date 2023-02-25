#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "string_item.h"

#define to_table (set_table_t *)
#define to_node (set_node_t *)
#define to_string_item (string_item_t *)

int main() {
    set_table_t *my_set;
    if(set_table_create(&my_set, 2) != 0) {
        puts("Erorre nella creazione della tabella");
        return -1;
    }

    set_table_insert(my_set, to_node string_item_new("Hello"), 5);
    set_table_insert(my_set, to_node string_item_new("World"), 5);
    set_table_insert(my_set, to_node string_item_new("Hello World"), 11);
    set_table_insert(my_set, to_node string_item_new("Good"), 4);

    printf("==========SET==========\n");
    string_item_t **current_nodes = (string_item_t **)my_set->nodes;
    string_item_t *head_node;
    for (size_t index = 0; index < my_set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            string_item_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->string);
                current_node = to_string_item current_node->node.node.next;
            }
        }
    }

    string_item_t *item_to_search = string_item_new("Good");
    string_item_t *finded = to_string_item set_table_search(my_set, to_node item_to_search, 4);
    if (!finded) {
        puts("Node Good not founded");
    } else {
        printf("Founded %s\n", finded->string);
    }
    free(item_to_search);

    item_to_search = string_item_new("Better");
    finded = to_string_item set_table_search(my_set, to_node item_to_search, 6);
    if (!finded) {
        puts("Node Better not founded");
    } else {
        printf("Founded %s\n", finded->string);
    }
    free(item_to_search);

    item_to_search = string_item_new("Hello World");
    finded = to_string_item set_table_remove(my_set, to_node item_to_search, 11);
    if (!finded) {
        puts("Node Hello World not founded");
    } else {
        printf("Removed %s\n", finded->string);
        free(finded);
    }
    free(item_to_search);

    item_to_search = string_item_new("Goods");
    finded = to_string_item set_table_remove(my_set, to_node item_to_search, 5);
    if (!finded) {
        puts("Node Goods not founded");
    } else {
        printf("Removed %s\n", finded->string);
        free(finded);
    }
    free(item_to_search);

    printf("==========REMOVE FROM SET==========\n");
    for (size_t index = 0; index < my_set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            string_item_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->string);
                current_node = to_string_item current_node->node.node.next;
            }
        }
    }

    string_item_t *item_to_insert = string_item_new("World");
    if(set_table_insert(my_set, to_node item_to_insert, 5) != 0) {
        puts("Node World not inserted");
    } else {
        printf("Inserted %s\n", item_to_insert->string);
    }
    printf("==========INSERT DUPLICATE SET==========\n");

    for (size_t index = 0; index < my_set->hashmap_size; index++) {
        if ((head_node = current_nodes[index])) {
            printf("Index [%llu]:\n", index);
            string_item_t *current_node = head_node;
            while (current_node) {
                printf("\t%s\n", current_node->string);
                current_node = to_string_item current_node->node.node.next;
            }
        }
    }

    // Free Set
    item_to_search = string_item_new("Good");
    finded = to_string_item set_table_remove(my_set, to_node item_to_search, 4);
    free(item_to_search);
    free(finded);
    item_to_search = string_item_new("Hello");
    finded = to_string_item set_table_remove(my_set, to_node item_to_search, 5);
    free(item_to_search);
    free(finded);
    item_to_search = string_item_new("World");
    finded = to_string_item set_table_remove(my_set, to_node item_to_search, 5);
    free(item_to_search);
    free(finded);

    set_table_destroy(my_set);
    return 0;
}