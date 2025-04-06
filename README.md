# 🧠 libft – A Custom C Standard Library

Welcome to **libft**, a personal implementation of many core functions from the C Standard Library.
This project was built from scratch for learning purposes — to better understand how these foundational utilities work under the hood.

---

## 🧠 Character Checks and Conversion

- `ft_isalnum` – Checks if a character is alphanumeric.
- `ft_isalpha` – Checks if a character is alphabetic.
- `ft_isascii` – Checks if a character is an ASCII character.
- `ft_isdigit` – Checks if a character is a digit.
- `ft_isprint` – Checks if a character is printable.
- `ft_isspace` – Checks if a character is whitespace.
- `ft_isnextline` – Checks if a character is a newline or carriage return.
- `ft_tolower` – Converts a character to lowercase.
- `ft_toupper` – Converts a character to uppercase.

---

## 🔢 Conversions

- `ft_atoi` – Converts a string to an integer.
- `ft_atol` – Converts a string to a long.
- `ft_atodbl` – Converts a string to a double.
- `ft_itoa` – Converts an integer to a string.

---

## 📋 Linked List Operations

- `ft_lstadd_back` – Adds a new node at the end of the list.
- `ft_lstadd_front` – Adds a new node at the beginning of the list.
- `ft_lstclear` – Clears and frees an entire list.
- `ft_lstdelone` – Deletes a single node from the list.
- `ft_lstiter` – Iterates over a list and applies a function.
- `ft_lstlast` – Returns the last node of the list.
- `ft_lstmap` – Applies a function to each node and returns a new list.
- `ft_lstnew` – Creates a new list node.
- `ft_lstsize` – Returns the number of nodes in a list.

---

## 🧠 Memory Management

- `ft_bzero` – Zeros out a block of memory.
- `ft_calloc` – Allocates memory and zeros it.
- `ft_memchr` – Searches for a byte in memory.
- `ft_memcmp` – Compares two memory areas.
- `ft_memcpy` – Copies memory from source to destination.
- `ft_memmove` – Safely copies memory with possible overlap.
- `ft_memset` – Fills memory with a constant byte.
- `ft_realloc` – Reallocates a memory block.
- `ft_free_strarray` – Frees an array of strings.

---

## 🧾 Input / Output

- `ft_printf` – Custom printf implementation.
- `put_chars` – Helper for printing characters.
- `put_numbers` – Helper for printing numbers.
- `ft_putbase` – Prints a number in a specified base.
- `ft_putchar` – Prints a character to stdout.
- `ft_putchar_fd` – Prints a character to a file descriptor.
- `ft_putendl_fd` – Prints a string followed by a newline to a file descriptor.
- `ft_putint` – Prints an integer.
- `ft_putnbr_fd` – Prints a number to a file descriptor.
- `ft_putptr` – Prints a memory address (pointer).
- `ft_putstr` – Prints a string to stdout.
- `ft_putstr_fd` – Prints a string to a file descriptor.

---

## 📖 File Reading (get_next_line)

- `get_next_line` – Reads a line from a file descriptor.
- `get_next_line_bonus` – Bonus version supporting multiple FDs.


---

## 🧵 String Functions

- `ft_split` – Splits a string by a delimiter.
- `ft_strdup` – Duplicates a string.
- `ft_strndup` – Duplicates a string up to a given length.
- `ft_striteri` – Applies a function to each character with its index.
- `ft_strjoin` – Concatenates two strings.
- `ft_strjoin_free` – Joins two strings and frees the originals.
- `ft_strlcat` – Concatenates strings with size limit.
- `ft_strlcpy` – Copies strings with size limit.
- `ft_strlen` – Returns the length of a string.
- `ft_strmapi` – Applies a function to each character, creating a new string.
- `ft_strcmp` – Compares two strings.
- `ft_strncmp` – Compares two strings up to `n` characters.
- `ft_strnstr` – Searches for a substring within a limited size.
- `ft_strchr` – Finds the first occurrence of a character.
- `ft_strrchr` – Finds the last occurrence of a character.
- `ft_strstr` – Locates a substring.
- `ft_strrstr` – Locates the last occurrence of a substring.
- `ft_strrev` – Reverses a string.
- `ft_strtrim` – Trims characters from the beginning and end.
- `ft_substr` – Extracts a substring.
- `ft_strtok` – Tokenizes a string (non-thread-safe).
- `ft_strspn` – Calculates the length of the initial segment containing only specified characters.
- `ft_strcspn` – Calculates the length of the initial segment without specified characters.

---

## 🧬 String Array Helpers

- `ft_strarray_dup` – Duplicates a string array.
- `ft_strarray_append` – Appends a string to a string array.
- `ft_strarray_len` – Returns the number of elements in a string array.
