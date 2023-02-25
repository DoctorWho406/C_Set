#include <stdlib.h>
#include <string.h>
#define HASH_IMPLEMENTATION
#include "hash.h"
#include "set.h"

int set_table_create(set_table_t **table, const size_t hashmap_size) {
    *table = malloc(sizeof(set_table_t));
    if (!table) {
        return -1;
    }
    (*table)->hashmap_size = hashmap_size;
    (*table)->nodes = calloc(hashmap_size, sizeof(set_node_t *));
    if (!(*table)->nodes) {
        free(table);
        return -1;
    }
    return 0;
}

set_node_t *set_table_search(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = hash_djb33x(*((void **)(item + 1)), size_of_key);
    size_t index = hash % table->hashmap_size;

    set_node_t *current_node = table->nodes[index];
    while (current_node) {
        if (memcmp(*((void **)current_node + 1), *((void **)item + 1), size_of_key) == 0) {
            return current_node;
        }
        current_node = (set_node_t *)current_node->node.next;
    }
    return NULL;
}

int set_table_insert(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = hash_djb33x(*((void **)(item + 1)), size_of_key);
    size_t index = hash % table->hashmap_size;

    //Duplicate
    if (set_table_search(table, item, size_of_key)) {
        return -1;
    }

    linked_list_append((list_node_t **)(&table->nodes[index]), (list_node_t *)item);
    return 0;
}

set_node_t *set_table_remove(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = hash_djb33x(*((void **)(item + 1)), size_of_key);
    size_t index = hash % table->hashmap_size;

    set_node_t *current_node = set_table_search(table, item, size_of_key);
    if (!current_node) {
        return NULL;
    }

    return (set_node_t *)linked_list_remove((list_node_t **)(&table->nodes[index]), (list_node_t *)current_node, size_of_key);
}

void set_table_destroy(set_table_t* table) {
    free(table->nodes);
    free(table);
}