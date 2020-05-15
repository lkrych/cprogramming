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

Unlike the abstractions provided by the OS for the CPU and memory (processes and address space/virtual memory), the OS does not create a private, virtualized disk for each application. Rather it is assumed that users will want to share information that is in files. 