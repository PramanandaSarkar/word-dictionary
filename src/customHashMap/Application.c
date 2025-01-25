#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "HashMap.h"

void custom_hashmap_benchmark(const char *file_path) {
    HashMap map;
    init_hashmap(&map, 500000);

    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    char line[256];
    size_t count = 0;

    // Measure insertion time
    clock_t start = clock();
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline
        insert_hashmap(&map, line, "1");
        count++;
    }
    clock_t end = clock();
    double insertion_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Measure search time
    start = clock();
    for (size_t i = 0; i < count; i++) {
        get_hashmap(&map, "example_key");
    }
    end = clock();
    double search_time = (double)(end - start) / CLOCKS_PER_SEC / count;

    // Memory usage
    size_t memory_usage = map.size * sizeof(HashMapEntry);

    printf("Custom HashMap:\n");
    printf("memory usage: %.1f MB\n", (double)memory_usage / (1024 * 1024));
    printf("data Insertion Time: %.2f seconds\n", insertion_time);
    printf("search time: %.4f seconds\n", search_time);

    fclose(file);
    free_hashmap(&map);
}
