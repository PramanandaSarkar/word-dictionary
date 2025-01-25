#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <ctime>

extern "C" void library_hashmap_benchmark(const char *file_path) {
    std::unordered_map<std::string, std::string> hashmap;
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    size_t count = 0;

    // Measure insertion time
    clock_t start = clock();
    while (std::getline(file, line)) {
        hashmap[line] = "1"; // Simple value for benchmarking
        count++;
    }
    clock_t end = clock();
    double insertion_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    // Measure search time
    start = clock();
    for (size_t i = 0; i < count; i++) {
        hashmap.find("example_key");
    }
    end = clock();
    double search_time = static_cast<double>(end - start) / CLOCKS_PER_SEC / count;

    // Memory usage estimate (rough)
    size_t memory_usage = count * (sizeof(std::string) + sizeof(std::string));

    std::cout << "Library HashMap:\n";
    std::cout << "memory usage: " << static_cast<double>(memory_usage) / (1024 * 1024) << " MB\n";
    std::cout << "data Insertion Time: " << insertion_time << " seconds\n";
    std::cout << "search time: " << search_time << " seconds\n";
}
