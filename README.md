*This project has been created as part of the 42 curriculum by absafi.*

# get_next_line

## Description

**get_next_line** is a project at 42 Amman whose goal is to write a function that reads a file descriptor and returns one line at a time, each time it is called. It can be used to read from a file, from standard input, or from any other valid file descriptor.

The project introduces static variables, dynamic memory allocation, and reading with a fixed-size buffer. The function is meant to be reused in later 42 projects.

## Project Description

The prototype of the function is:

```c
char *get_next_line(int fd);
```

It follows these rules:

- Each call returns the next line read from the file descriptor, including the terminating `\n` when there is one.
- It returns `NULL` when there is nothing more to read or when an error occurs.
- The last line is returned without a `\n` if the file does not end with one.
- It works with both files and standard input.
- The size of the read buffer is set at compile time with the `BUFFER_SIZE` macro, and the function must behave correctly for any positive value.

### Files

- `get_next_line.c` contains the main function.
- `get_next_line_utils.c` contains the helper functions.
- `get_next_line.h` contains the prototypes and the default `BUFFER_SIZE`.

### Design

The function reads from the file descriptor in chunks of `BUFFER_SIZE` bytes with `read`, appending each chunk to a static variable that keeps what has been read but not yet returned. Reading stops as soon as a newline is found in the stored data or the end of the file is reached. The stored data is then split: the part up to and including the first newline is returned as the line, and the remainder is kept in the static variable for the next call.

### Bonus

The bonus version handles several file descriptors at the same time, so alternating calls on different descriptors do not lose the reading position of any of them. It uses a single static variable and is provided in the files `get_next_line_bonus.c`, `get_next_line_utils_bonus.c` and `get_next_line_bonus.h`.

## Instructions

### Compilation

A C compiler is required. The function must be compiled with the flags `-Wall -Wextra -Werror` and with `BUFFER_SIZE` defined, for example:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

For the bonus version:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

### Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

The returned line is allocated with `malloc`, so the caller must free it.

## Prerequisites

- A C compiler (`cc`)
- Linux or another Unix-like environment

## Resources

- Linux manual pages.
- *The C Programming Language* by Brian W. Kernighan and Dennis M. Ritchie
- [get_next_line tester](https://github.com/Tripouille/gnlTester)

### AI Usage

**Google Gemini** was used as a supplementary learning and verification tool during the project.

It was used for:

- Clarifying concepts and information that were not fully explained in the 42 project manual.
- Providing additional examples to reinforce my understanding of static variables and file descriptors.
- Reviewing my reasoning about memory management, memory leaks and function behavior.
