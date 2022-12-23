#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "LinkedList.h"
#include "Set.h"

set_table_t *set_table_new(const size_t hashmap_size) {
    set_table_t *table = malloc(sizeof(set_table_t));
    if (!table) {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    set_node_t **nodes = calloc(hashmap_size, sizeof(set_node_t *));
    if (!nodes) {
        free(table);
        return NULL;
    }
    table->nodes = nodes;
    return table;
}

set_node_t *set_table_search(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = djb33x_hash(*((void **)(item + 1)), size_of_key);
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

set_node_t *set_table_insert(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = djb33x_hash(*((void **)(item + 1)), size_of_key);
    size_t index = hash % table->hashmap_size;

    //Duplicate
    if (set_table_search(table, item, size_of_key)) {
        return NULL;
    }

    return (set_node_t *)list_append((list_node_t **)(&table->nodes[index]), (list_node_t *)item);
}

set_node_t *set_table_remove(set_table_t *table, set_node_t *item, const size_t size_of_key) {
    size_t hash = djb33x_hash(*((void **)(item + 1)), size_of_key);
    size_t index = hash % table->hashmap_size;

    set_node_t *current_node = set_table_search(table, item, size_of_key);
    if (!current_node) {
        return NULL;
    }

    return (set_node_t *)list_remove((list_node_t **)(&table->nodes[index]), (list_node_t *)current_node, size_of_key);
}