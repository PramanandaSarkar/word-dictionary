#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read a file into a string
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    char *content = malloc(size + 1);
    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}

// Count the number of lines in a string
size_t count_lines(const char *content) {
    size_t lines = 0;
    const char *p = content;

    while (*p != '\0') {
        if (*p == '\n') {
            lines++;
        }
        p++;
    }

    return lines;
}

// Custom implementation of strdup
char *custom_strdup(const char *str) {
    size_t len = strlen(str);
    char *copy = malloc(len + 1);
    if (copy != NULL) {
        strcpy(copy, str);
    }
    return copy;
}
