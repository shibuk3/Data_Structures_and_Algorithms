### __Structure vs class in C++__

In C++, a structure is the same as a class except for a few differences. The most important of them is security.
A Structure is not secure and cannot hide its implementation details from the end-user while a class is secure and
can hide its programming and designing details. Following are some differences between a class and a structure.
| C ++       | C     |
|----------|---------|
| Members of a class are private by default.| Members of a structure are public by default. |
|   The class variables may have null values.       |   There can be no null values in any structure member.      |
|    It is a reference type data type.      |   It is a value type data type.      |
|    It is declared using the class keyword.      |   It is declared using the struct keyword      |
|     Member variables of a class can be initiated directly.     | Member variables of a structure cannot be initiated directly.        |

Some of the points that elaborate on these differences: 

1) Members of a class are private by default and members of a structure are public by default. 
For example, program 1 fails in compilation but program 2 works fine, 
```cpp
// Program 1
// CPP Program to demonstrate that Members of a class are
// private by default
#include <bits/stdc++.h>
using namespace std;
  
class Test {
    // x is private
    int x;
};
  
// Driver Code
int main()
{
    Test t;
    t.x = 20;
    // compiler error because x is private
    getchar();
    return 0;
}
Output

prog.cpp: In function ‘int main()’:
prog.cpp:8:9: error: ‘int Test::x’ is private
    int x;
        ^
prog.cpp:13:7: error: within this context
    t.x = 20;
      ^
```
```c
// Program 2
// CPP Program to demonstrate that members of a structure
// are public by default. 
#include <bits/stdc++.h>
using namespace std;
  
struct Test {
    // x is public
    int x;
};
int main()
{
    Test t;
    t.x = 20;
    // works fine because x is public
    cout << t.x;
    getchar();
    return 0;
}
Output
20
```
Inheritance is possible in class, but not in structures.

For example, program 3 works fine but program 4 fails, 

```cpp
// Program 3
// C++ program to demonstrate Inheritance in class
#include <bits/stdc++.h>
using namespace std;
  
// Base class
class Parent {
public:
    int x;
};
  
// Sub class inheriting from Base Class(Parent)
class Child : public Parent {
public:
    int y;
};
  
// Driver Code
int main()
{
  
    Child obj1;
    // An object of class child has all data members
    // and member functions of class parent
    obj1.y = 7;
    obj1.x = 91;
    cout << obj1.y << endl;
    cout << obj1.x << endl;
  
    return 0;
}
Output
7
91
```
```cpp
// Program 4
// C++ program to demonstrate Inheritance in structure
#include <iostream>
using namespace std;
  
struct Base {
public:
    int x;
};
  
struct Derived : Base {
public:
    int y;
}; // Is equivalent to struct Derived : public Base {}
  
int main()
{
    Derived d;
    d.x = 20; // Works fine because inheritance is public
    cout << d.x;
    getchar();
    return 0;
}
```
### __Difference Between C Structures and C++ Structures__
Although C++ is a subset of C but, what are the differences between structures in C and structures in C++? In C++,
structures are similar to classes. One major difference can be, that in C, members of the structure default to 
public visibility, however in C++, members of the structure default to private visibility. 

| C        | C++     |
|----------|---------|
| Only data members are allowed, it cannot have member functions.| Can hold both: member functions and data members.|
|   Only data members are allowed, it cannot have member functions.       |   Can hold both: member functions and data members.      |
|   Cannot have static members.       |   Can have static members.      |
|   Cannot have a constructor inside a structure.       |  Constructor creation is allowed.       |
|     Direct Initialization of data members is not possible.     |   Direct Initialization of data members is possible.      |
|    Writing the ‘struct’ keyword is necessary to declare structure-type variables.      |   Writing the ‘struct’ keyword is not necessary to declare structure-type variables.      |
|      Only pointers to structs are allowed.    |   Can have both pointers and references to the struct.      |
|   Sizeof operator will generate 0  for an empty structure.       | Sizeof operator will generate 1 for an empty structure.        |
| Data Hiding is not possible.|Data Hiding is possible.|

### __Why is the Size of an Empty Class Not Zero in C++?__

When the structure was introduced in C, there was no concept of Objects at that time. So, according to the C standard, it was decided to keep the size of the empty structure to zero. 

In C++, the Size of an empty structure/class is one byte as to call a function at least empty structure/class should have some size (minimum 1 byte is required ) i.e. one byte to make them distinguishable.

Now to understand the size of an empty class, let’s learn what is empty class is first!

Empty class: It is a class that does not contain any data members (e.g. int a, float b, char c, and string d, etc.) However, an empty class may contain member functions. 

Why actually an empty class in C++ takes one byte?
Simply a class without an object requires no space allocated to it. The space is allocated when the class is instantiated, so 1 byte is allocated by the compiler to an object of an empty class for its unique address identification. 

If a class has multiple objects they can have different unique memory locations. Suppose, if a class does not have any size, what would be stored on the memory location? That’s the reason when we create an object of an empty class in a C++ program, it needs some memory to get stored, and the minimum amount of memory that can be reserved is 1 byte. Hence, if we create multiple objects of an empty class, every object will have a unique address.


```md
Objects Memory Allocation in C++
The way memory is allocated to variables and functions of the class is
different even though they both are from the same class.

The memory is only allocated to the variables of the class when the object is created.
The memory is not allocated to the variables when the class is declared. At the same 
time, single variables can have different values for different objects, so every 
object has an individual copy of all the variables of the class. But the memory 
is allocated to the function only once when the class is declared. So the objects
don’t have individual copies of functions only one copy is shared among each object.



```
