#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "ListFunctions.h"
#include "Item.h"

SET_TABLE *set_table_new(const size_t hashmap_size) {
    SET_TABLE *table = malloc(sizeof(SET_TABLE));
    if(!table) {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    SET_NODE **nodes = calloc(hashmap_size, sizeof(SET_NODE *));
    if(!nodes) {
        free(table);
        return NULL;
    }
    table->nodes = nodes;
    return table;
}

struct set_node *set_table_search(struct set_table *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    SET_NODE *current_node = table->nodes[index];
    if(!current_node) {
        return NULL;
    }
    while(current_node->key != key && current_node->next) {
        current_node = (SET_NODE *)current_node->next;
    }
    if(current_node->key == key) {
        return current_node;
    }
    return NULL;
}

SET_NODE *set_table_insert(SET_TABLE *table, const char *key, const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    //Duplicate
    if(set_table_search(table, key, key_len)){
        return NULL;
    }

    SET_NODE *new_item = malloc(sizeof(SET_NODE));
    if(!new_item) {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;

    return (SET_NODE *)list_append((LIST_NODE **)table->nodes, (LIST_NODE *)new_item);
//     SET_NODE *head = table->nodes[index];
//     if(!head) {
//         SET_NODE *i_nodes = malloc(sizeof(SET_NODE));
//         if(!i_nodes) {
//             return NULL;
//         }
//         table->nodes[index] = i_nodes;
//         table->nodes[index]->key = key;
//         table->nodes[index]->key_len = key_len;
//         table->nodes[index]->next = NULL;
// 
//         return table->nodes[index];
//     }
// 
//     while(head->next) {
//         if(strcmp(head->key, key) == 0) {
//             return NULL;
//         }
//         head = head->next;
//     }
//     if(strcmp(head->key, key) == 0) {
//         return NULL;
//     }
// 
//     SET_NODE *new_item = malloc(sizeof(SET_NODE));
//     if(!new_item) {
//         return NULL;
//     }
//     new_item->key = key;
//     new_item->key_len = key_len;
//     new_item->next = NULL;
// 
//     head->next = new_item;
//     return head->next;
}

SET_NODE *set_table_remove(SET_TABLE *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    SET_NODE *current_node = table->nodes[index];
    while(current_node && current_node->key != key ) {
        current_node = (SET_NODE *)current_node->next;
    }
    if(current_node->key == key) {
        return (SET_NODE *)list_remove((LIST_NODE **)table->nodes[index], (LIST_NODE *)current_node);
        // SET_NODE *removed = current_node->next;
        // if(current_node->next->next) {
        //     current_node->next = current_node->next->next;
        // } else {
        //     current_node->next = NULL;
        // }
        // removed->next = NULL;
        // return removed;        
    }
    return NULL;
}