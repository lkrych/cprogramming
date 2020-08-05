# Pointers in C - Pointers and Functions

## Table of Contents


### Introduction

Pointers allow data to be passed and modified by a function. Complex data can also be passed and returned from a function in the form of a pointer to a struct. When pointers hold the address of a function they provide means to dynamically control a program's execution flow.

To understand functions and their use with pointers, we need to talk about the **program stack**. The program stack is used by most modern block-structured languages to support the execution of functions. When **a function is invoked, a stack frame is created and pushed onto the program stack**.  When the function returns, its stack frame is popped off.

## Program Stack and Heap

The **program stack** is **an area of memory** that **supports the execution of functions** and is normally **shared with the heap** (they share the same region of memory). The program stack tends to occupy the lower region, while the heap uses the upper part (and grows downward).

The **program stack holds stack frames**. Stack frames **hold the parameters and local variables** of a function.

```c
void function2() {
    Object *var1 = ...;
    int var2;
    printf("Program stack Example\n");
}

void function1() {
    Object *var3 = ...;
    function2();
}

int main() {
    int var4;
    function1();
}
```

As functions are called, their stack frames are pushed onto the stack and the stack grows "upward". When a function terminates, its stack frame is popped off the stack. **The memory used by the stack frame is not cleared and may eventually be overridden** by another stack frame.

When memory is **dynamically allocated**, it **comes from the heap**, which tends to grow "downward". The heap will fragment as memory is allocated and then deallocated. Although the heap tends to grow downward, this is a general direction. Memory can be allocated anywhere within the heap.

<img src="3_resources/stack_and_heap.png">

### Organization of a stack frame