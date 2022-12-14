#ifdef _WIN32
#define EXPORTFUNC __declspec(dllexport)
#else
#define EXPORTFUNC
#endif

#include <stdio.h>

EXPORTFUNC size_t djb33x_hash(void *key, const size_t keylen) {
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++) {
        hash = ((hash << 5) + hash) ^ (char)((char *)key)[i];
    }
    return hash;
}