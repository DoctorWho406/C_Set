#include <stdlib.h>
#include "StringItem.h"

string_item_t *string_item_new(const char *string) {
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item) {
        return NULL;
    }
    item->string = string;
    return item;
}