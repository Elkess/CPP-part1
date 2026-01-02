Exercise 04 - Sed is for losers

Implemented in C++98 with a small object-oriented design. The program takes three arguments: a filename, `s1` and `s2`. It reads the whole file into a `std::string`, finds every occurrence of `s1` with `std::string::find`, and writes a new file named `<filename>.replace` where each occurrence of `s1` is replaced by `s2`. The forbidden `std::string::replace` is not used.

Concepts used
- Object-oriented design: `FileReplacer` class encapsulates inputs and the `process()` operation.
- Command-line arguments and validation: `int main(int ac, char **av)`.
- File I/O: `std::ifstream` and `std::ofstream` to read/write files.
- Reading whole file: `std::ostringstream` with `rdbuf()` to capture file contents simply.
- String search and slicing: `std::string::find` and `std::string::substr` for replacements.
- Simple error handling with clear messages and non-zero exit codes.

Build
- Run `make` in this directory; the target `replace_file` will be produced.

Usage
- `./replace_file filename s1 s2`
- Produces `filename.replace` with replacements applied.

Notes
- This keeps a simple OOP structure while remaining compact and C++98-compliant.