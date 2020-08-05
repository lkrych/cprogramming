# Pointers in C - Dynamic Memory Management

## Table of Contents

* [Introduction](#introduction)
* [Dynamic Memory Management](#dynamic-memory-management)
    * [Memory Leaks](#memory-leaks)

## TLDR

## Introduction

Much of the **power of pointers stems from their ability to track dynamically allocated memory**.

A C program executes within a **runtime system**, this is typically the environment provided by the operating system. The runtime supports **the stack and heap** along with other program behavior.

C supports managing objects that are allocated **memory from the heap**. This is **done manually using functions to allocate and deallocate** the memory. This is called **dynamic memory management**.

## Dynamic Memory Allocation

The basic steps for dynamic memory allocation in C are:
1. Use a `malloc` type function to allocate memory.
2. Use the memory.
3. Deallocate the memory using the `free` function.

Seems easy right? 😝 Here is an example:

```c
int *pi = (int*) malloc(sizeof(int));
*pi = 5;
printf("*pi: %d\n", *pi);
free(pi);
```

<img src="2_resources/allocate_int.png">

The `malloc` functions **single argument** specifies the **number of bytes to allocate**. If successful, it will return a pointer to memory allocated from the heap. If it fails, it returns a null pointer. The `sizeof` operator makes the code above more portable.

Each time the `malloc` function is called, a **corresponding call to the `free` function must be made when the application is done with the memory to avoid memory leaks**.

Once memory has been freed, it should not be accessed again. A common practice is to **always assign NULL to a freed pointer**.

When memory is allocated, additional information is stored as part of a data structure maintained by the heap manager. This information includes, among other things, the block's size and is typically placed immediately adjacent to the allocated block. If the application writes outside of this block of memory, then the data structure can be corrupted. Let's look at an example:

```c
char *pc = (char*) malloc(6);
for(int i=0; i<8; i++) {
    *pc[i] = 0;
}
```

Notice we only allocate five characters plus the byte for the NUL termination character. The for loop writes extra memory and corrupts the data structure used for heap management.

<img src="2_resources/extra_memory.md">

### Memory Leaks