#ifndef __HASH_H
#define __HASH_H
#include <stddef.h>

size_t hash_djb33x(void *key, const size_t keylen);

#ifdef HASH_IMPLEMENTATION
#include <stdio.h>

size_t hash_djb33x(void *key, const size_t keylen) {
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++) {
        hash = ((hash << 5) + hash) ^ (char)((char *)key)[i];
    }
    return hash;
}
#endif //HASH_IMPLEMENTATION

#endif //__HASH_H