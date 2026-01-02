Exercise 05 - Harl 2.0

This exercise implements `Harl` in C++98 using a small object-oriented design and pointers-to-member functions.

What the program does
- The program expects a single command-line parameter: a log `LEVEL` (one of `DEBUG`, `INFO`, `WARNING`, `ERROR`).
- It constructs a `Harl` instance and calls `complain(level)`.
- `Harl::complain` compares the provided `level` against an internal array of level strings and, when matched, calls the corresponding private member function via a pointer-to-member.

Files
- `Harl.hpp`: class declaration and `typedef` for pointer-to-member.
- `Harl.cpp`: implementation of `debug`, `info`, `warning`, `error`, and `complain` using an array of `HarlMem` pointers.
- `main.cpp`: simple launcher parsing arguments and invoking `Harl::complain`.
- `Makefile`: builds the `harl2` executable with C++98 flags.

Concepts used
- Object-oriented programming: `Harl` class with private member functions and a public interface.
- Pointers to member functions: `typedef void (Harl::*HarlMem)(void);` and calling via `(this->*func)()`.
- Arrays and simple lookup: mapping level strings to member function pointers to avoid a forest of `if/else`.
- C++98 compliance: code compiles with `-std=c++98` and uses only C++98 features.

Build
Run:
```
make
```

Usage
```
./harl2 DEBUG
```

This will print the debug message to `stdout` when the level matches `DEBUG`.
