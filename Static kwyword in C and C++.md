### __Static Variables in C__
Static variables have a property of preserving their value even after they are out of their scope! Hence, 
static variables preserve their previous value in their previous scope and are not initialized again in
the new scope. 

Following are some interesting facts about static variables in C.
- A static int variable remains in memory while the program is running. A normal or auto variable is 
 destroyed when a function call where the variable was declared is over. 
For example, we can use static int to count a number of times a function is called, but an auto variable
can’t be used for this purpose.
```c
#include<stdio.h>
int fun()
{
  static int count = 0;
  count++;
  return count;
}
  
int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
Output: 
1 2
```
```c
#include<stdio.h>
int fun()
{
  int count = 0;
  count++;
  return count;
}
  
int main()
{
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}
Output: 

1 1
```
- Static variables are allocated memory in data segment, not stack segment. See memory layout of C programs for details.
- Static variables (like global variables) are initialized as 0 if not initialized explicitly. For example in the
 below program, value of x is printed as 0, while value of y is something garbage.
 ```c
 #include <stdio.h>
int main()
{
    static int x;
    int y;
    printf("%d \n %d", x, y);
}

Output: 
0 
[some_garbage_value] 
 ```
 
What are the default values of static variables in C ?
In C, if an object that has static storage duration is not initialized explicitly, then:
- if it has pointer type, it is initialized to a NULL pointer;
- if it has arithmetic type, it is initialized to (positive or unsigned) zero;
- if it is an aggregate, every member is initialized (recursively) according to these rules;
- if it is a union, the first named member is initialized (recursively) according to these rules.

For example, following program prints:
Value of g = 0
Value of sg = 0
Value of s = 0
```c
#include<stdio.h>
int g;  //g = 0, global objects have static storage duration
static int gs; //gs = 0, global static objects have static storage duration
int main()
{
  static int s; //s = 0, static objects have static storage duration
  printf("Value of g = %d", g);
  printf("\nValue of gs = %d", gs);
  printf("\nValue of s = %d", s);
  
  getchar();
  return 0;
}
```

- In C, static variables can only be initialized using constant literals. For example, following program fails in compilation. 
```c
#include<stdio.h>
int initializer(void)
{
    return 50;
}
  
int main()
{
    static int i = initializer();
    printf(" value of i = %d", i);
    getchar();
    return 0;
}
Output 

 In function 'main':
9:5: error: initializer element is not constant
     static int i = initializer();
     ^
```
If we change the program to following, then it works without any error.
```c
#include<stdio.h>
int main()
{
    static int i = 50;
    printf(" value of i = %d", i);
    getchar();
    return 0;
}
```
The reason for this is simple: All objects with static storage duration must be initialized (set to their initial values)
before execution of main() starts. So a value which is not known at translation time cannot be used for initialization
of static variables.

__Please note that this condition doesn’t hold in C++. So if you save the program as a C++ program, it would compile and run fine.__

- Static global variables and functions are also possible in C/C++. The purpose of these is to limit scope of a variable or
 function to a file. Please refer Static functions in C for more details.
- Static variables should not be declared inside structure. The reason is C compiler requires the entire structure elements 
to be placed together (i.e.) memory allocation for structure members should be contiguous. It is possible to declare structure
inside the function (stack segment) or allocate memory dynamically(heap segment) or it can be even global (BSS or data segment).
Whatever might be the case, all structure members should reside in the same memory segment because the value for the structure
element is fetched by counting the offset of the element from the beginning address of the structure. Separating out one membe
r alone to data segment defeats the purpose of static variable and it is possible to have an entire structure as static.

### __Static functions in C__

In C, functions are global by default. The “static” keyword before a function name makes it static. For example, below function fun() is static.
```c
static int fun(void)
{
  printf("I am a static function ");
}
```
Unlike global functions in C, access to static functions is restricted to the file where they are declared. Therefore, when we want to restrict access to functions, we make them static. Another reason for making functions static can be reuse of the same function name in other files.

For example, if we store following program in one file file1.c
```c
/* Inside file1.c */ 
static void fun1(void)
{
  puts("fun1 called");
}
```
```c
And store following program in another file file2.c


/* Inside file2.c  */ 
int main(void)
{
  fun1(); 
  getchar();
  return 0;  
}
```
Now, if we compile the above code with command “gcc file2.c file1.c”, we get the error “undefined reference to 
`fun1’” . This is because fun1() is declared static in file1.c and cannot be used in file2.c.

Please write comments if you find anything incorrect in the above article, or want to share more information 
about static functions in C.

### __Static Keyword in C++__
Static keyword has different meanings when used with different types. We can use static keyword with:

Static Variables : Variables in a function, Variables in a class
Static Members of Class : Class objects and Functions in a class

Let us now look at each one of these use of static in details:

Static Variables

Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime
of the program. Even if the function is called multiple times, space for the static variable is allocated only once 
and the value of variable in the previous call gets carried through the next function call. This is useful for implementing
coroutines in C/C++ or any other application where previous state of function needs to be stored.
```c++
// C++ program to demonstrate 
// the use of static Static 
// variables in a Function
#include <iostream>
#include <string>
using namespace std;
  
void demo()
{ 
    // static variable
    static int count = 0;
    cout << count << " ";
      
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}
  
int main()
{
    for (int i=0; i<5; i++)    
        demo();
    return 0;
}
Output:

0 1 2 3 4 
```
You can see in the above program that the variable count is declared as static. So, its value is carried through 
the function calls. The variable count is not getting initialized for every time the function is called.

- Static variables in a class: As the variables declared as static are initialized only once as they are allocated
space in separate static storage so, the static variables in a class are shared by the objects. There can not be
multiple copies of same static variables for different objects. Also because of this reason static variables can not
be initialized using constructors.
```c++
// C++ program to demonstrate static
// variables inside a class
  
#include<iostream>
using namespace std;
  
class GfG
{
   public:
     static int i;
      
     GfG()
     {
        // Do nothing
     };
};
  
int main()
{
  GfG obj1;
  GfG obj2;
  obj1.i =2;
  obj2.i = 3;
    
  // prints value of i
  cout << obj1.i<<" "<<obj2.i;   
}
```
You can see in the above program that we have tried to create multiple copies of the static variable i for multiple objects.
But this didn’t happen. So, a static variable inside a class should be initialized explicitly by the user using the class
name and scope resolution operator outside the class as shown below:
```cpp
// C++ program to demonstrate static
// variables inside a class
  
#include<iostream>
using namespace std;
  
class GfG
{
public:
    static int i;
      
    GfG()
    {
        // Do nothing
    };
};
  
int GfG::i = 1;
  
int main()
{
    GfG obj;
    // prints value of i
    cout << obj.i; 
}
Output:

1
```
