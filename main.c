#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_MAP_SIZE 10007 // A prime number for better hash distribution
#define BUFFER_SIZE 1024

// Node structure for the hash map
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

// Hash map structure
Node *hash_map[HASH_MAP_SIZE];

// Function to calculate hash value
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % HASH_MAP_SIZE;
}

// Function to insert a word into the hash map
void insert_to_hash_map(const char *word) {
    unsigned int index = hash(word);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->word = strdup(word);
    new_node->next = hash_map[index];
    hash_map[index] = new_node;
}

// Function to search for a word in the hash map
int search_in_hash_map(const char *word) {
    unsigned int index = hash(word);
    Node *current = hash_map[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to free the hash map
void free_hash_map() {
    for (int i = 0; i < HASH_MAP_SIZE; i++) {
        Node *current = hash_map[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
}

// Function to calculate elapsed time in seconds
double calculate_time(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to load words from a file into the hash map
void load_words_into_hash_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fscanf(file, "%1023s", buffer) != EOF) {
        insert_to_hash_map(buffer);
    }

    fclose(file);
}

// Function to search words from a file in the hash map
void search_words_in_hash_map(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening search file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int found_count = 0;
    int not_found_count = 0;

    while (fscanf(file, "%1023s", buffer) != EOF) {
        if (search_in_hash_map(buffer)) {
            found_count++;
        } else {
            not_found_count++;
        }
    }

    printf("Words found: %d\n", found_count);
    printf("Words not found: %d\n", not_found_count);

    fclose(file);
}

int main() {
    const char *input_file = "1.txt"; // File containing words to load into hash map
    const char *search_file = "2.txt"; // File containing words to search

    printf("Starting hash map loading...\n");
    clock_t start_time = clock();

    // Load words into hash map
    load_words_into_hash_map(input_file);

    clock_t end_time = clock();
    double load_time = calculate_time(start_time, end_time);
    printf("Hash map loading completed in %.6f seconds\n", load_time);

    printf("Starting word search...\n");
    start_time = clock();

    // Search words in the hash map
    search_words_in_hash_map(search_file);

    end_time = clock();
    double search_time = calculate_time(start_time, end_time);
    printf("Word search completed in %.6f seconds\n", search_time);

    // Free the hash map
    free_hash_map();

    return 0;
}
