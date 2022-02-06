[link](https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/)

### __Memory Alignment__

```
We often declare and use structures (or structs) in C mainly because of the flexibility
it provides in handling data. The C Programming Language by Kernighan & Ritchie defines 
structures as:

“A structure is a collection of one or more variables, possibly of different types, 
grouped together under a single name for convenient handling”


In this article, our focus will not be on how to define, declare, and initialize structures. 
If you are already familiar with structures and interested in learning how to use them in a
memory-efficient manner, you have found the right article. Let’s dive into the discussion!!

Consider the following structure.
```

```cpp
struct Node1 {
    uint8_t num1;
    uint64_t num2;
    uint8_t num3;
} node1;
```

What do you expect to be the size of node1? 10 bytes (1 + 8 + 1),
primary maths!!! Unfortunately, this is WRONG.

```
printf("Size of node1: %zu \n", sizeof(node1));
```

This printf statement would reveal that the actual size is 24 bytes (in a 64-bit system). 
Wait a minute!!! How is this possible?? To understand this, we should first
understand how does memory alignment and padding work.

### __Alignment and Padding__

The amount of data fetched and processed by the processor in a single instruction
is called the “word size”. Simply, the processor would read one word at a time. In a 32-bit
system, the word size is 32 bits (4 bytes) similarly in a 64-bit system, the word size is 64
bits (8 bytes). We will base the rest of the discussion on a 64-bit system.

![image](https://user-images.githubusercontent.com/51910127/152677690-2c502585-5f14-4e35-818b-8004d98fc2df.png)

Let’s have a look at Figure 1. Each square box represents 1 byte of memory. For simplicity, the
memory addresses are named 0–23. Since we are dealing with a 64-bit system, the processor 
would read memory locations 0–7 (blue segment) together, 8–15 (yellow segment) together, 
and 16–23 (green segment) together. Suppose, if we declare an integer like this:

```cpp
int var;
```
Generally, int datatype requires 32 bits or 4 bytes. You can allocate memory for
var anywhere between 0 and 23. Some of the possibilities are as follows.

![image](https://user-images.githubusercontent.com/51910127/152677727-f37cf4d3-f7e7-4450-a863-596dee9dc0ae.png)

One obvious but significant observation here is that Alignments 2, 3 and 4 force 
the processor to fetch our var in two cycles (processor should fetch blue segment 
in one cycle and yellow segment in the next cycle) whereas Alignments 1 and 5 require
only one cycle (only the blue segment for Alignment 1 and only the yellow segment for Alignment 5).
So it evident that Alignments 1 and 5 improve efficiency. Wait!! What does it have to
do with our problem?

Turns out that the system does not allocate memory randomly but has a data alignment
requirement. The variables in C are allocated memory in such a way that they start 
with a memory address which is a multiple of their size. For example, char which is
one byte long can start from anywhere, short which is 2 bytes long should start from
memory addresses which are multiples of 2, int which is 4 bytes long should start with
memory addresses which are multiples of 4, etc. If you consider Alignments 1 and 5, the 
allocated memories start with 4 and 8 which are multiples of 4.

Next, we have to understand what is padding, why is it required and how does it
work. Now we know that there is an alignment requirement for memory allocation. In 
order to ensure this alignment requirement, the system uses padding. Padding is simply
inserting empty bytes (sometimes leaving them empty). If we go back to our struct Node1
example,

![image](https://user-images.githubusercontent.com/51910127/152677766-fa1a6c26-3c66-4022-b1e1-de9f3720fe71.png)

This is how actual memory allocation looks like. To make it even more clear,
if we look at ourstruct declaration, what actually happens is,

```md
struct Node1 {
    uint8_t num1;
    char padding[7];     //padding
    uint64_t num2;
    uint8_t num3;
    char padding[7];     //padding
}
```
This is the reason why it consumes 24 bytes of memory instead of 10 bytes.

However, we can work around and reduce the amount of memory consumed from 24 to 16 bytes.

![image](https://user-images.githubusercontent.com/51910127/152677789-1d76fc75-2cde-4be9-9121-cc7e32fbed6c.png)

```cpp
struct Node1 {
    uint8_t num1;
    uint8_t num3;
    char padding[6];
    uint64_t num2;
}
```

In this example, we are saving only a byte, which is negligible compared to the amount of 
memory available in a typical machine of this era (which often contains gigabytes of memory).
However, when the structure has a large number of variables and/or when you create a large
number of struct variables you can save a considerable amount of memory. Further, not all 
systems have gigabytes of memory. Especially people who work with embedded systems have to
manage with a very small amount of memory. I will leave the discussion on such 
applications to a different article.
