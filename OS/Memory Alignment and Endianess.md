[link](https://www.freecodecamp.org/news/what-is-endianness-big-endian-vs-little-endian/)

### __write a program to know the endianness of a machine__

Little and Big Endian Mystery

Little and big endian are two ways of storing multibyte data-types ( int, float, etc).
In little endian machines, last byte of binary representation of the multibyte 
data-type is stored first. On the other hand, in big endian machines, 
first byte of binary representation of the multibyte data-type is stored first. 
Suppose integer is stored as 4 bytes (For those who are using DOS-based compilers
such as C++ 3.0, integer is 2 bytes) then a variable x with value 0x01234567 will
be stored as following.

![image](https://user-images.githubusercontent.com/51910127/152698910-ec8c40a1-9f43-4e9b-980a-7b7424d20b80.png)

How to see memory representation of multibyte data types on your machine? 

Here is a sample C code that shows the byte representation of int, float and pointer. 
```c
#include <stdio.h>
  
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n) 
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}
  
/*Main function to call above function for 0x01234567*/
int main()
{
   int i = 0x01234567;
   show_mem_rep((char *)&i, sizeof(i));
   getchar();
   return 0;
}
```


When above program is run on little endian machine, gives “67 45 23 01” as output, 
while if it is run on big endian machine, gives “01 23 45 67” as output.

Is there a quick way to determine endianness of your machine? 
There are n no. of ways for determining endianness of your machine. Here is one quick way of doing the same. 

```c
#include <stdio.h>
int main() 
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)    
       printf("Little endian");
   else
       printf("Big endian");
   getchar();
   return 0;
}
```
In the above program, a character pointer c is pointing to an integer i. Since size of character 
is 1 byte when the character pointer is de-referenced it will contain only first byte of integer. 
If machine is little endian then *c will be 1 (because last byte is stored first)
and if the machine is big endian then *c will be 0. 

Does endianness matter for programmers? 

Most of the times compiler takes care of endianness, however, endianness becomes
an issue in following cases.
It matters in network programming: Suppose you write integers to file on a little 
endian machine and you transfer this file to a big-endian machine. Unless there is
little endian to big endian transformation, big endian machine will read the
file in reverse order. You can find such a practical example here.
Standard byte order for networks is big endian, also known as network byte order.
Before transferring data on network, data is first converted to network byte order (big endian).

__What are bi-endians?__ 

Bi-endian processors can run in both modes little and big endian.
What are the examples of little, big endian and bi-endian machines ? 
Intel based processors are little endians. ARM processors were little endians.
Current generation ARM processors are bi-endian.
Motorola 68K processors are big endians. PowerPC (by Motorola) and SPARK (by Sun)
processors were big endian. Current version of these processors are bi-endians. 
Does endianness affects file formats? 
File formats which have 1 byte as a basic unit are independent of endianness e.g.,
ASCII files. Other file formats use some fixed endianness format e.g, JPEG files
are stored in big endian format. 


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



```
// C Program to demonstrate the structure padding property
#include <stdio.h>
  
// Alignment requirements
// (typical 32 bit machine)
  
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes
  
// structure A
typedef struct structa_tag {
    char c;
    short int s;
} structa_t;
  
// structure B
typedef struct structb_tag {
    short int s;
    char c;
    int i;
} structb_t;
  
// structure C
typedef struct structc_tag {
    char c;
    double d;
    int s;
} structc_t;
  
// structure D
typedef struct structd_tag {
    double d;
    int s;
    char c;
} structd_t;
  
int main()
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));
  
    return 0;
}
Output
sizeof(structa_t) = 4
sizeof(structb_t) = 8
sizeof(structc_t) = 24
sizeof(structd_t) = 16
```

Structure C – Every structure will also have alignment requirements
Applying same analysis, structc_t needs sizeof(char) + 7-byte padding + sizeof(double) + sizeof(int) = 1 + 7 + 8 + 4 = 20 bytes. However, the sizeof(structc_t) is 24 bytes. It is because, along with structure members, structure type variables will also have natural alignment. Let us understand it by an example. Say, we declared an array of structc_t as shown below 

structc_t structc_array[3];
Assume, the base address of structc_array is 0x0000 for easy calculations. If the structc_t occupies 20 (0x14) bytes as we calculated, the second structc_t array element (indexed at 1) will be at 0x0000 + 0x0014 = 0x0014. It is the start address of the index 1 element of the array. The double member of this structc_t will be allocated on 0x0014 + 0x1 + 0x7 = 0x001C (decimal 28) which is not multiple of 8 and conflicts with the alignment requirements of double. As we mentioned at the top, the alignment requirement of double is 8 bytes.

In order to avoid such misalignment, the compiler introduces alignment requirements to every structure. It will be as that of the largest member of the structure. In our case alignment of structa_t is 2, structb_t is 4 and structc_t is 8. If we need nested structures, the size of the largest inner structure will be the alignment of an immediate larger structure.

In structc_t of the above program, there will be a padding of 4 bytes after the int member to make the structure size multiple of its alignment. Thus the size of (structc_t) is 24 bytes. It guarantees correct alignment even in arrays.
