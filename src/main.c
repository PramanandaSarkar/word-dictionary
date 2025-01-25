#include <stdio.h>
#include "benchmarks.h"

int main() {
    const char *file_path = "data/words_alpha.txt";

    printf("Benchmarking Library HashMap...\n");
    library_hashmap_benchmark(file_path);

    printf("\nBenchmarking Custom HashMap...\n");
    custom_hashmap_benchmark(file_path);

    return 0;
}
