# Class Activity 1 — System Calls in Practice

## Overview
This activity explores Linux system calls, file operations, directory listing, system-call tracing, and basic operating-system information.

## Warm-up Programs
- `hello_syscall.c`: Uses `write()` to print a message.
- `copyfilesyscall.c`: Copies a file using `open()`, `read()`, `write()`, and `close()`.

## Task 1 — File Operations
- `task1/file_creator_sys.c`: Creates a file using system-call interfaces.
- `task1/file_reader_sys.c`: Reads a file and prints its contents.
- `task1/answers.txt`: Answers to Task 1 questions.

## Task 2 — Directory Listing
- `task2/dir_list_sys.c`: Lists directory entries and their sizes.
- `task2/answers.txt`: Answers to Task 2 questions.

## Task 3 — System Call Tracing
- `task3_strace/hello_trace.txt`: Trace of `hello_syscall`.
- `task3_strace/copy_trace.txt`: Trace of `copyfilesyscall`.
- `task3_strace/answers.txt`: Answers to Task 3 questions.

## Task 4 — System Information
- `task4_notes.txt`: Linux, CPU, memory, and disk information.
- `os_layers.txt`: Basic operating-system layers diagram.

## Screenshots
The `screenshots/` folder is reserved for screenshots showing compilation, program execution, and system-call traces.
