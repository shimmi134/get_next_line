In this small project, I have created a function named get_next_line, which reads from a file descriptor (fd) and returns a line from the file the fd is pointing to.

To compile, use:
`cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c your_other_files.c`

<ins>Be sure to have the header file when you compile!</ins>

The bonus part of this project is to be able to read from multiple fd's at once.
It compiles the same way, just remember to use the `_bonus{.c/.h}` files instead.
