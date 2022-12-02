#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Item.h"
#include "ListFunctions.h"

set_table_t *set_table_new(const size_t hashmap_size) {
    set_table_t *table = malloc(sizeof(set_table_t));
    if(!table) {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    set_node_t **nodes = calloc(hashmap_size, sizeof(set_node_t *));
    if(!nodes) {
        free(table);
        return NULL;
    }
    table->nodes = nodes;
    return table;
}

set_node_t *set_table_search(set_table_t *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    set_node_t *current_node = table->nodes[index];
    if(!current_node) {
        return NULL;
    }
    while(current_node->key != key && current_node->next) {
        current_node = (set_node_t *)current_node->next;
    }
    if(current_node->key == key) {
        return current_node;
    }
    return NULL;
}

set_node_t *set_table_insert(set_table_t *table, const char *key, const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    //Duplicate
    if(set_table_search(table, key, key_len)){
        return NULL;
    }

    set_node_t *new_item = malloc(sizeof(set_node_t));
    if(!new_item) {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;

    return (set_node_t *)list_append((list_node_t **)(&table->nodes[index]), (list_node_t *)new_item);
}

set_node_t *set_table_remove(set_table_t *table, const char *key,  const size_t key_len) {
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;

    set_node_t *current_node = set_table_search(table, key, key_len);
    if(!current_node) {
        return NULL;
    }
    return (set_node_t *)list_remove((list_node_t **)(&table->nodes[index]), (list_node_t *)current_node);
}