Exercise 06 - Harl filter

This exercise implements a filtered Harl that prints messages at the provided log level and above.

Behavior
- The program takes one parameter: a log level string (`DEBUG`, `INFO`, `WARNING`, `ERROR`).
- It prints the messages for that level and for all higher-severity levels (e.g., `WARNING` prints `WARNING` and `ERROR`).
- If the level is unknown it prints a short default message.

Implementation notes
- Object-oriented C++98: `Harl` class with private message methods and a public `filter()`.
- Pointers-to-member: an array `HarlMem funcs[]` maps indices to member functions; invoked via `(this->*funcs[i])()`.
- `switch` used with fall-through to cascade messages from the matched level upwards (this satisfies the exercise requirement to use `switch`).

Build
```
make
```

Usage
```
./harlFilter WARNING
```

This prints `WARNING` and `ERROR` messages. The program compiles with `-std=c++98`.
