#ifndef HELPER_H
#define HELPER_H

#include <stddef.h>

// Helper function declarations
char *read_file(const char *filename);
size_t count_lines(const char *content);
char *custom_strdup(const char *str); // Replacement for strdup

#endif
