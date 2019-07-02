# Ch1 K&R

Compiling C code generally

`gcc -o binary_name sourcefile.c`

*statements* specify the computing operations to be done
*variables* store values used during the computation

C programs begin executution at the *main* function.

`#include <stdio.h>`
tells the compiler to include information about the standard 
input/output library

[Hello World](hello.c)

The range of both int and float depends on the machine that you are 
using. C provides several other basic data types including char, short, 
long, and double. There are also arrays, structures and unions of these 
basic types, and pointers to them

[Fahrenheit to Celsius](fahrtocelsius.c)

It's bad practice to bury magic numbers into a program. Define some *symbolic constants*.

```
#define LOWER 0
#define UPPER 300
#define STEP  20
```

[Use constants and for loop](fahrtocelsiusforloop.c)