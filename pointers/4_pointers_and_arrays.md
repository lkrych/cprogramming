# Arrays and Pointers

## Table of Contents

* [](#)

## Introduction

An **array** is a **contiguous** collection of elements of the **same type** that can be **accessed using an index**. Contiguous means that the elements are adjacent to one another with no gaps in between. 

Arrays can possess multiple dimensions. Two-dimensional arrays are common, and we typically use the terms rows and columns to describe the position of an array element.

Arrays have a **fixed size**. When we declare an array, we need to decided how big it should be. The `realloc()` function and variable length arrays provide techniques for dealing with arrays whose size needs to change.

## One-dimensional Arrays

A one-dimensional array is a linear structure. It uses a single index to access its members. 

```c
int vector[5];
```

<img src="4_resources/arr_alloc.png">

The array indexes start with 0, and ends at one less than the declared size. **C does not enforce the bounds of an array**. Using an invalid index can result in unpredictable behavior.

The internal representation of an array has **no information about the number of elements it contains**. The array name simply **references a block of memory**. Using the `sizeof()` operator with an array will return the number of bytes allocated to the array. To determine the number of elements in an array, divide the array's size by the element's size.

```c
int vector[5] = {1, 2, 3, 4, 5};
printf("%d\n", sizeof(vector)/sizeof(int));
```

## Two-Dimensional Arrays

Two-Dimensional arrays use rows and columns to identify array elements. This type of array needs to be **mapped to the one-dimension address space of main memory**. In C, this is achieved by using **row-column ordering sequence**. The array's **first row is placed in memory followed by the second row**, then the third row, and this ordering continues until the last row is placed in memory.

```c
int matrix[2][3] = {{1,2,3}, {4,5,6}};
```

The image below illustrates how memory is allocated for the array. The diagram on the left show show memory is mapped. The diagram on the right shows how it can be viewed conceptually.

<img src="4_resources/two_dimension.png">

A two-dimensional array is treated as an array of arrays. This is, when we access the array using only one subscript, we get a pointer to the corresponding row. 

```c
int matrix[2][3] = {{1,2,3}, {4,5,6}};

for( int i = 0; i < 2; i++) {
    printf("&matrix[%d]: %p sizzeof(matrix[%d]: %d\n", i, &matrix[i], i, sizeof(matrix[i]);
}
// &matrix[0]: 100 sizeof(matrix[0]): 12
// &matrix[1]: 112 sizeof(matrix[1]): 12
```

The size is twelve because each row has elements of four bytes each.

## Multidimensional Arrays

As with two-dimensional arrays, multiple sets of brackets define the array's type and size. Let's create a three dimensional array with three rows, two columns and a rank (term often used for the third dimension) of four.


```c
int arr3d[3][2][4] = {
    {{1, 2, 3, 4}, {5, 6, 7, 8}},
    {{9, 10, 11, 12}, {13, 14, 15, 16}}, {{17, 18, 19, 20}, {21, 22, 23, 24}}
};
```

<img src="4_resources/three_dimension.png">

## Pointer Notation and Arrays

When an array name is used by itself, the array's address is returned. This can be assigned to a pointer.

```c
int vector[5] = {1, 2, 3, 4, 5};
int *pv = vector;
```

The variable `pv` is a **pointer to the first element of the array and not the array itself**. When we first assigned a value to `pv`, we assigned the address of the array's first element.

The expression `&vector` is sometimes used to obtain the address of an array. It differs from other notations in that it returns a pointer to the entire array. The other two approaches, `vector/&vector[0]` yield a pointer to an integer. 

We can also use array subscripts with pointers. Effectively the notation: `pv[i] = *(pv + i);`

The pointer `pv` contains the address of a block of memory. The bracket notation will take the address contained in pv and add the value contained in the index `i` using pointer arithmetic.

## Differences Between Arrays and Pointers