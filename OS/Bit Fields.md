### __Bit fields__

Let me use an example to demonstrate some advanced memory alignment concepts
and to introduce bit-fields and their usefulness. Suppose you have been hired 
by an organization to write a piece of software in which the first step is
to store the employee details. The requirement is to store employeeID, gender,

Step 1: You decide to create a struct

Let’s assume that employeeId is only 5 characters long and 2 bytes are
enough to hold the salary values.

```cpp
typedef struct employee {
    char employeeId[5];
    bool isMale;
    uint8_t age;
    uint16_t salary;
} Employee;
```

If you print the size of this struct using,

```cpp
Employee employee1;
printf("Size of struct employee is %zu \n", sizeof(employee1));
```
the size of the struct would be 10 bytes.

employeeId -> 5 bytes, isMale -> 1 byte, age -> 1 byte, salary -> 2 bytes.

Total of 9 bytes (5 + 1 + 1 + 2). Wait, what!!!!

Step 2: You check the memory alignment

![image](https://user-images.githubusercontent.com/51910127/152679542-429bf861-430e-4f64-8cf7-d4199c39be16.png)

Since salary is 2 bytes long, its memory address should be a multiple of two
detailed explanation of this concept. Hence you modify your struct as follows

```cpp
typedef struct employee {
    char employeeId[5];
    bool isMale;
    uint16_t salary;
    uint8_t age;
} Employee;

```

![image](https://user-images.githubusercontent.com/51910127/152679569-6e1e9e8a-a1eb-46af-bed7-607d4a98439d.png)

If you print the size again, you would be left in awe as the size would still be 10. Why is that?

Step 3: You dig deeper

According to the GCC Documentation,

Note that the alignment of any given struct or union type is required by the ISO C standard
to be at least a perfect multiple of the lowest common multiple of the alignments of all 
of the members of the struct or union in question.

In out struct design, the lowest common multiple of
[sizeof(char), sizeof(bool), sizeof(uint16_t) , sizeof(uint8_t)]
is 2 (as uint16_t occupies 2 bytes), which forces the size of our struct to be 10.

What actually happens is, 1-byte padding has been added to the end as shown in the diagram below.

![image](https://user-images.githubusercontent.com/51910127/152679602-2f4d657a-7720-440e-a3c0-24e9f480e2ff.png)

### __Bit-Fields__

Can we do further modifications to reduce memory consumption? YES, WE CAN!!!
To represent gender, we only need a single bit (1=male and 0=female) (only male and female
are considered just for the sake of giving an example). And you do not need 8 bits to
represent age. Nobody has ever lived for 256 (2⁸) years :-). This is where bit-fields
are useful. Have a look at the following struct design.

```cpp
typedef struct employee {
    char employeeId[5];
    bool isMale : 1;
    uint8_t age : 7;
    uint16_t salary;
} Employee;
```

Using bit-fields, you can let the compiler know how many bits you want to use 
for each variable. In our example, isMale would take only 1 bit and the age
would take 7 bits. Now the memory alignment would look like this,

![image](https://user-images.githubusercontent.com/51910127/152679638-c8447d15-0054-4fb9-82a7-0a9800755b9f.png)

If you print the size of our struct , it would only be 8 bytes.
Other Applications of Bit-fields
Assume that you have to create a struct with 10 integer variables, where each 
variable requires only 40 bits. However, there is no standard C data type for 40-bit 
integers. Hence, the only option left is to go for 64-bit integers.

```md
struct sample {
    long integer1;
    long integer2;
    //....
    long integer10;
};
```
We would be using 640 bits (10 x 64) where only 400 bits are required. Using bit-fields would solve the problem.

```
struct sample2 {
    long integer1 : 40;
    long integer2 : 40;
    //....
    long integer10 : 40;
};

```
Now, the size of the struct is only 400bits.
Limitations in using bit-fields
The major limitation is that you cannot create arrays using bit-fields. 
For example, you cannot create an array where each element is 40 bits.

If you print the size of our struct , it would only be 8 bytes.
Other Applications of Bit-fields
Assume that you have to create a struct with 10 integer variables, where
each variable requires only 40 bits. However, there is no standard C data 
type for 40-bit integers. Hence, the only option left is to go for 64-bit
integers.
```cpp
struct sample {
    long integer1;
    long integer2;
    //....
    long integer10;
};

```
We would be using 640 bits (10 x 64) where only 400 bits are required.
Using bit-fields would solve the problem.

```cpp
struct sample2 {
    long integer1 : 40;
    long integer2 : 40;
    //....
    long integer10 : 40;
};
```

Now, the size of the struct is only 400bits.

__Limitations in using bit-fields__
The major limitation is that you cannot create arrays using bit-fields.
For example, you cannot create an array where each element is 40 bits.
