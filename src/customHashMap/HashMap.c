#include "HashMap.h"
#include "../utils/helper.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Hash function
static unsigned long hash_function(const char *key, size_t capacity) {
    unsigned long hash = 5381;
    while (*key) {
        hash = (hash * 33) + *key++;
    }
    return hash % capacity;
}

// Create a new HashMap
HashMap *create_hashmap(size_t capacity) {
    HashMap *map = malloc(sizeof(HashMap));
    map->entries = calloc(capacity, sizeof(HashMapEntry));
    map->capacity = capacity;
    map->size = 0;
    return map;
}

// Free the HashMap
void free_hashmap(HashMap *map) {
    for (int i = 0; i < map->capacity; i++) {
        if (map->entries[i].key != NULL) {
            free(map->entries[i].key);
            free(map->entries[i].value);
        }
    }
    free(map->entries);
    map->entries = NULL;
}

// Insert into the HashMap
int insert_hashmap(HashMap *map, const char *key, const char *value) {
    unsigned long index = hash_function(key, map->capacity);

    for (size_t i = 0; i < map->capacity; ++i) {
        size_t try = (index + i) % map->capacity;

        if (map->entries[try].key == NULL) {
            map->entries[try].key = custom_strdup(key);
            map->entries[try].value = custom_strdup(value);
            map->size++;
            return 0;
        }

        if (strcmp(map->entries[try].key, key) == 0) {
            free(map->entries[try].value);
            map->entries[try].value = custom_strdup(value);
            return 0;
        }
    }

    return -1; // HashMap is full
}

// Get from the HashMap
const char *get_hashmap(HashMap *map, const char *key) {
    unsigned long index = hash_function(key, map->capacity);

    for (size_t i = 0; i < map->capacity; ++i) {
        size_t try = (index + i) % map->capacity;

        if (map->entries[try].key == NULL) {
            return NULL; // Key not found
        }

        if (strcmp(map->entries[try].key, key) == 0) {
            return map->entries[try].value;
        }
    }

    return NULL; // Key not found
}

// Print the HashMap
void print_hashmap(HashMap *map) {
    for (size_t i = 0; i < map->capacity; ++i) {
        if (map->entries[i].key != NULL) {
            printf("Key: %s, Value: %s\n", map->entries[i].key, map->entries[i].value);
        }
    }
}
void init_hashmap(HashMap *map, int capacity) {
    map->capacity = capacity;
    map->size = 0;
    map->entries = calloc(capacity, sizeof(HashMapEntry));
}
