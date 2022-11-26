#include <stdlib.h>
#include "Functions.h"
#include "Hash.h"

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

SET_NODE *set_insert(SET_TABLE *table, const char *key, const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    SET_NODE *head = table->nodes[index];
    if(!head) {
        SET_NODE *i_nodes = malloc(sizeof(SET_NODE));
        if(!i_nodes) {
            return NULL;
        }
        table->nodes[index] = i_nodes;
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;

        return table->nodes[index];
    }

    SET_NODE *new_item = malloc(sizeof(SET_NODE));
    if(!new_item) {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;

    while(head->next) {
        head = head->next;
    }
    head->next = new_item;
    return head->next;
}


struct set_node *set_search(struct set_table *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    SET_NODE *current_node = table->nodes[index];
    if(!current_node) {
        return NULL;
    }
    while(current_node->key != key && current_node->next) {
        current_node = current_node->next;
    }
    if(current_node->key == key) {
        return current_node;
    }
    return NULL;
}

struct set_node *set_remove(struct set_table *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    SET_NODE *current_node = table->nodes[index];
    if(!current_node) {
        return NULL;
    }
    while(current_node->next && current_node->next->key != key ) {
        current_node = current_node->next;
    }
    if(current_node->next->key == key) {
        SET_NODE *removed = current_node->next;
        if(current_node->next->next) {
            current_node->next = current_node->next->next;
        } else {
            current_node->next = NULL;
        }
        removed->next = NULL;
        return removed;        
    }
    return NULL;
}