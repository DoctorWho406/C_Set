#ifndef __STRING_ITEM_H
#define __STRING_ITEM_H
#include "set.h"

typedef struct string_item {
    set_node_t node;
    const char *string;
} string_item_t;

string_item_t *string_item_new(const char *string);

#endif //__STRING_ITEM_H