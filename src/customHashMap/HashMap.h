#ifndef HASHMAP_H
#define HASHMAP_H

#include <stddef.h>

// Structure for key-value pairs
typedef struct {
    char *key;
    char *value;
} HashMapEntry;

// HashMap structure
typedef struct {
    HashMapEntry *entries;
    size_t capacity;
    size_t size;
} HashMap;

// Function declarations
void init_hashmap(HashMap *map, int capacity);

HashMap *create_hashmap(size_t capacity);
void free_hashmap(HashMap *map);
int insert_hashmap(HashMap *map, const char *key, const char *value);
const char *get_hashmap(HashMap *map, const char *key);
void print_hashmap(HashMap *map);

#endif
