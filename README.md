*This project has been created as part of the 42 curriculum by abenameu.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. It is built as a static library, `libftprintf.a`, and exposes a single function:

```c
int	ft_printf(const char *format, ...);
```

The goal of the project is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`) and to write well-structured, extensible code.

Supported conversions:

| Conversion | Output |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a NULL pointer) |
| `%p` | a pointer in hexadecimal, prefixed with `0x` (`(nil)` for NULL) |
| `%d`, `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x`, `%X` | an unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | a percent sign |

Like the original, `ft_printf` returns the number of characters written. It does not reproduce the buffer management of the original `printf()`: every piece of output is written directly with `write`.

## Instructions

Build the library:

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # rebuilds from scratch
```

Use it in a program:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%s is %d years old\n", "Alea", 18);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -I. -o main
```

## Algorithm and data structure

The implementation is a single linear pass over the format string, with no intermediate buffer and no allocated memory.

- **Main loop (`ft_printf`).** It walks the format string character by character. A regular character is written immediately and counts as 1. On a `%`, the character that follows is handed to the dispatcher, and the loop skips both the `%` and the conversion letter. The loop keeps two separate counters: the position in the format string, and the total number of characters written, which is the return value.
- **Dispatcher.** It reads the conversion letter, fetches the next argument with `va_arg` using the type that letter implies (`int` for `%c`, `%d`, `%i` because of default argument promotion, `unsigned int` for `%u`, `%x`, `%X`, `char *` for `%s`, a pointer-sized integer for `%p`), and passes the value to the matching print function. The `va_list` is passed by pointer, so the cursor advances in the caller as well, which is the behaviour the C standard guarantees.
- **Print functions.** Each one writes its output and returns how many characters it wrote, so the count travels back up to `ft_printf`.
- **One generic number printer.** `ft_putnbr_base` prints an unsigned value in any base, given the string of digits to use. The recursion prints the most significant digits first, so no buffer or reversal is needed. `%u`, `%x`, `%X` and `%p` all reuse it with a different digit string, which keeps the code small and makes adding a conversion such as octal or binary a one-line change.
- **Signed numbers.** `ft_putnbr_int` writes the minus sign, then delegates to `ft_putnbr_base`. `INT_MIN` is handled separately, because its opposite does not fit in an `int`.

No data structure is needed beyond the `va_list` cursor: the format string itself drives the whole process.

## Resources

- `man 3 printf` and `man 3 stdarg`
- The C standard (C99), section 7.15 on variable arguments
- [cppreference: variadic arguments](https://en.cppreference.com/w/c/variadic)

### Use of AI

Claude (Anthropic) was used during this project:

- to explain variadic functions, default argument promotion and the edge cases of `printf` (NULL strings and pointers, `INT_MIN`, return value);
- to review my code and point out bugs, without writing the logic for me; the conversion logic and the main loop are my own;
- to compare my output and return values against the real `printf` with a test program;
- to write the Makefile and this README, and to fix the Norm formatting (whitespace, splitting `%c` and `%p` into their own functions so the dispatcher fits in 25 lines).
