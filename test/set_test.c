#define CLOVE_SUITE_NAME SetTest
#include "clove-unit.h"
#include "set.h"
#include "hash.h"
#include <stdlib.h>

set_table_t *set;

CLOVE_SUITE_SETUP() {
    set_table_create(&set, 5);
}

CLOVE_SUITE_TEARDOWN() {
    set_table_destroy(set);
}

typedef struct test_item {
    set_node_t node;
    const char *string;
} test_item_t;

test_item_t *new_test_item(const char *string) {
    test_item_t *item = malloc(sizeof(test_item_t));
    if (!item) {
        return NULL;
    }
    item->string = string;
    return item;
}

CLOVE_TEST(CreateSetWithOneItem) {
    CLOVE_NOT_NULL(set);
    test_item_t *first = new_test_item("First");

    CLOVE_NOT_NULL(first);

    set_table_insert(set, (set_node_t *)first, 6);

    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    CLOVE_PTR_EQ(first, set->nodes[first_index]);

    free(first);
}

CLOVE_TEST(CreateSetWithTwoItem) {
    test_item_t *first = new_test_item("First");
    test_item_t *second = new_test_item("Second");

    CLOVE_NOT_NULL(first);
    CLOVE_NOT_NULL(second);

    set_table_insert(set, (set_node_t *)first, 6);
    set_table_insert(set, (set_node_t *)second, 7);

    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    int second_index = hash_djb33x("Second", 7) % set->hashmap_size;
    CLOVE_PTR_EQ(first, set->nodes[first_index]);
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, set->nodes[first_index]->node.next);
    } else {
        CLOVE_PTR_EQ(second, set->nodes[second_index]);
    }

    free(first);
    free(second);
}

CLOVE_TEST(SearchFromSetWithZeroItem) {
    test_item_t *to_find = new_test_item("ToFind");

    set_node_t *finded = set_table_search(set, (set_node_t *)to_find, 7);

    CLOVE_NULL(finded);

    free(to_find);
}

CLOVE_TEST(SearchFromSetWithOneItem) {
    test_item_t *first = new_test_item("First");
    set_table_insert(set, (set_node_t *)first, 6);

    set_node_t *finded = set_table_search(set, (set_node_t *)first, 6);

    CLOVE_PTR_EQ(first, finded);

    free(first);
}

CLOVE_TEST(SearchNewItemFromSetWithOneItem) {
    test_item_t *first = new_test_item("First");
    set_table_insert(set, (set_node_t *)first, 6);

    test_item_t *to_find = new_test_item("First");

    set_node_t *finded = set_table_search(set, (set_node_t *)to_find, 6);

    CLOVE_PTR_EQ(first, finded);

    free(first);
    free(to_find);
}

CLOVE_TEST(SearchFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First");
    test_item_t *second = new_test_item("Second");
    set_table_insert(set, (set_node_t *)first, 6);
    set_table_insert(set, (set_node_t *)second, 7);

    set_node_t *finded = set_table_search(set, (set_node_t *)second, 7);

    CLOVE_PTR_EQ(second, finded);

    free(first);
    free(second);
}

CLOVE_TEST(SearchNewItemFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First");
    test_item_t *second = new_test_item("Second");
    set_table_insert(set, (set_node_t *)first, 6);
    set_table_insert(set, (set_node_t *)second, 7);

    test_item_t *to_find = new_test_item("Second");
    set_node_t *finded = set_table_search(set, (set_node_t *)to_find, 7);

    CLOVE_PTR_EQ(second, finded);

    free(first);
    free(second);
    free(to_find);
}

CLOVE_TEST(RemoveFromSetWithZeroItem) {
    test_item_t *to_remove = new_test_item("ToRemove");

    set_node_t *removed = set_table_remove(set, (set_node_t *)to_remove, 9);
    CLOVE_NULL(removed);

    free(to_remove);
}

CLOVE_TEST(RemoveFromSetWithOneItem) {
    test_item_t *first = new_test_item("First");
    set_table_insert(set, (set_node_t *)first, 6);

    set_node_t *removed = set_table_remove(set, (set_node_t *)first, 6);

    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(set->nodes[first_index]);

    free(first);
}

CLOVE_TEST(RemoveNewItemFromSettWithOneItem) {
    test_item_t *first = new_test_item("First");
    set_table_insert(set, (set_node_t *)first, 6);

    test_item_t *to_remove = new_test_item("First");
    set_node_t *removed = set_table_remove(set, (set_node_t *)to_remove, 6);

    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    CLOVE_PTR_EQ(first, removed);
    CLOVE_NULL(set->nodes[first_index]);

    free(first);
    free(to_remove);
}

CLOVE_TEST(RemoveFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First");
    test_item_t *second = new_test_item("Second");
    set_table_insert(set, (set_node_t *)first, 6);
    set_table_insert(set, (set_node_t *)second, 7);

    set_node_t *removed = set_table_remove(set, (set_node_t *)first, 6);

    CLOVE_PTR_EQ(first, removed);
    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    int second_index = hash_djb33x("Second", 7) % set->hashmap_size;
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, set->nodes[second_index]);
        CLOVE_NULL(set->nodes[first_index]->node.next);
    } else {
        CLOVE_NULL(set->nodes[first_index]);
    }

    free(first);
    free(second);
}

CLOVE_TEST(RemoveNewItemFromSetWithTwoItem) {
    test_item_t *first = new_test_item("First");
    test_item_t *second = new_test_item("Second");
    set_table_insert(set, (set_node_t *)first, 6);
    set_table_insert(set, (set_node_t *)second, 7);

    test_item_t *to_remove = new_test_item("First");
    set_node_t *removed = set_table_remove(set, (set_node_t *)to_remove, 6);

    CLOVE_PTR_EQ(first, removed);
    int first_index = hash_djb33x("First", 6) % set->hashmap_size;
    int second_index = hash_djb33x("Second", 7) % set->hashmap_size;
    if (first_index == second_index) {
        CLOVE_PTR_EQ(second, set->nodes[second_index]);
        CLOVE_NULL(set->nodes[first_index]->node.next);
    } else {
        CLOVE_NULL(set->nodes[first_index]);
    }

    free(first);
    free(second);
    free(to_remove);
}