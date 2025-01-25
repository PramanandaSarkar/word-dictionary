# Word Dictionary

A simple **Word Dictionary** application written in pure **C** that allows users to store, search, and manage words with their definitions. This project is built with manual memory management and pointers, focusing on the fundamentals of C programming.

---

## Features



---

## Requirements

- **C Compiler**: Any modern C compiler (e.g., GCC).
- **Operating System**: Cross-platform (Linux, macOS, Windows).

---

## Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/PramanandaSarkar/word-dictionary.git
cd word-dictionary
```

### 2. Build the Application
Ensure you have a C compiler installed (e.g., GCC). Use the provided `Makefile` to build the application:
```bash
make
```

This will compile the source code and generate an executable in the `bin/` directory.

### 3. Run the Application
Run the executable using the command:
```bash
./bin/dictionary
```
or
```bash
make run
```

---

## How to Use



## Implementation Details

- **Dynamic Memory Management**:
  - All word data and definitions are stored in dynamically allocated memory using `malloc` and `free`.
  - The dictionary grows as new words are added.

- **Pointer Usage**:
  - Pointers are used for managing word storage, navigating the dictionary, and linking data structures.

- **Error Handling**:
  - The application includes basic error handling for memory allocation and user inputs.

---

## Files and Structure

```
word-dictionary-c/
├── Makefile          # Build automation script
├── main.c            # Entry point of the program
├── dictionary.c      # Core functionality (add/search/delete/display)
├── dictionary.h      # Header file for dictionary.c
├── bin/              # Output directory for the compiled executable
└── README.md         # Project documentation
```

---

## Example Run

```bash
$ ./bin/dictionary


```

---

## Future Improvements

- Implement sorting for displayed words.
- Add file-based storage to save and load words between sessions.
- Enhance the CLI with better input validation and error messages.

---

## License

This project is licensed under the **MIT License**. Feel free to use, modify, and distribute it.

---


