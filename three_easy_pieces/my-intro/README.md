# Introduction to OS

## Table of Contents
* [Thinking about concurrency](#thinking-about-concurrency)
* [Thinking about persistence](#thinking-about-persistence)
* [Design goals](#design-goals-of-an-operating-system)

### Thinking about concurrency

Let's look at the code in threads.c

```bash
gcc -o threads threads.c -Wall -pthread
./threads 1000                                               
Initial value: 0
Final value: 2000
```

That's probably what we would've guessed would happen. But what happens when we use higher values for the loops variable?

```bash
./threads 100000                                               
Initial value: 0
Final value: 157824

./threads 100000                                               
Initial value: 0
Final value: 119402
```

To put it politely, wtf? We not only get the wrong value, but we get a different wrong value each time! What is going on here?

The reason for these odd and unusual outcomes **relate to how instructions are executed**, which is one at a time.  Unfortunately, a key part of the program above, where the shared counter is incremented, takes three instructions:

1. One to load the value of the counter from memory into register.
2. One to increment it.
3. One to store it back into memory.

Because these instructions do not execute **atomically** (all at once), strange things can happen. 

### Thinking about Persistence

In system memory, data can be easily lost, as devices such as DRAM store values in a volatile manner (when power goes away or the system crashes, any data in memory is lost).

Thus, we need hardware and software to be able to store data **persistently**. 

The hardware comes in the form of some kind of **input/output (I/O) device**. The software in the operating system that usually manages the disk is called the **file system**.

Unlike the abstractions provided by the OS for the CPU and memory (processes and address space/virtual memory), the OS does not create a private, virtualized disk for each application. Rather it is assumed that users will want to *share* information that is in files. 

The code in `io.c` creates a file that contains the string "hello world".

To accomplish this task, the program makes three calls into the operating system:
    1. **open** - which opens the file and creates it
    2. **write** -  which writes the data to the file
    3. **close** - which closes the file, indicating the program won't be writing any more data to it. 

These calls are **system calls** which are part of the API the operating system exposes to programmers.

For performance reasons, most file systems first delay writes for a while, hoping to batch them into larger groups. To handle the problems of system crashes during writes, most file systems incorporate some kind of intricate write protocol, such as journaling, or copy-on-write, which carefully orders writes to disk to ensure that if a failure occurs during the write sequence, the system can recover afterwards. 

### Design Goals of an Operating System

The three easy pieces of operating systems are:
1. It takes physical resources, such as CPU, memory, or disk, and **virtualizes** them.
2. It handles tough and tricky issues related to **concurrency**.
3. It stores files **persistently**, making them safe over the long term. 

One of the most basic goals is to build up some **abstractions** in order to make the system convenient and easy to use.

Another sometimes conflicting goal is to provide **high performance**, minimizing the overhead of the OS.  We'll seek solutions that improve usability, but not at any cost. 

Another goal is **protection** between applications because we wish to allow many programs to run at the same time. 