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
###  __Static Members of Class__
- Class objects as static: Just like variables, objects also when declared as static have a scope till the lifetime of program.
Consider the below program where the object is non-static.
```cpp
// CPP program to illustrate
// when not using static keyword
#include<iostream>
using namespace std;
  
class GfG
{
    int i;
    public:
        GfG()
        {
            i = 0;
            cout << "Inside Constructor\n";
        }
        ~GfG()
        {
            cout << "Inside Destructor\n";
        }
};
  
int main()
{
    int x = 0;
    if (x==0)
    {
        GfG obj;
    }
    cout << "End of main\n";
}
Output:



Inside Constructor
Inside Destructor
End of main
```
In the above program the object is declared inside the if block as non-static. So, the scope of variable is inside
the if block only. So when the object is created the constructor is invoked and soon as the control of if block
gets over the destructor is invoked as the scope of object is inside the if block only where it is declared.

Let us now see the change in output if we declare the object as static.
```cpp
// CPP program to illustrate
// class objects as static
#include<iostream>
using namespace std;
  
class GfG
{
    int i = 0;
      
    public:
    GfG()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }
      
    ~GfG()
    {
        cout << "Inside Destructor\n";
    }
};
  
int main()
{
    int x = 0;
    if (x==0)
    {
        static GfG obj;
    }
    cout << "End of main\n";
}
Output:

Inside Constructor
End of main
Inside Destructor
```
You can clearly see the change in output. Now the destructor is invoked after the end of main. This happened 
because the scope of static object is through out the life time of program.

### __Static functions in a class__
Just like the static data members or static variables inside the class, static member functions also does not depend 
on object of class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it 
is recommended to invoke the static members using the class name and the scope resolution operator.
Static member functions are allowed to access only the static data members or other static member functions, they can
not access the non-static data members or member functions of the class.
```cpp
// C++ program to demonstrate static
// member function in a class
#include<iostream>
using namespace std;
  
class GfG
{
   public:
      
    // static member function
    static void printMsg()
    {
        cout<<"Welcome to GfG!";
    }
};
  
// main function
int main()
{
    // invoking a static member function
    GfG::printMsg();
}
Output:

Welcome to GfG!
```
### __Static data members in C++__
Static data members are class members that are declared using static keywords. A static member has certain special characteristics. These are:

- Only one copy of that member is created for the entire class and is shared by all the objects of that class,
 no matter how many objects are created.
- It is initialized before any object of this class is being created, even before main starts.
- It is visible only within the class, but its lifetime is the entire 
```cpp
#include <iostream>
using namespace std;
 
class A
{
public:
    A() { cout << "A's Constructor Called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's Constructor Called " << endl; }
};
 
int main()
{
    B b;
    return 0;
}
Output: B's Constructor Called
```
The above program calls only B’s constructor, it doesn’t call A’s constructor. The reason for this is simple,
static members are only declared in a class declaration, not defined. They must be explicitly defined outside
the class using the scope resolution operator. 
If we try to access static member ‘a’ without an explicit definition of it, we will get a compilation error. For example,
the following program fails in the compilation.
```cpp
#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
 
int main()
{
    B b;
    A a = b.getA();
    return 0;
}
Output: 

Compiler Error: undefined reference to `B::a' 
```
If we add the definition of a the program will work fine and will call A’s constructor. See the following program.

```
#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
 
A B::a;  // definition of a
 
int main()
{
    B b1, b2, b3;
    A a = b1.getA();
 
    return 0;
}
Output: 

A's constructor called
B's constructor called
B's constructor called
B's constructor called
 ```
Note that the above program calls B’s constructor 3 times for 3 objects (b1, b2, and b3), but calls A’s constructor only
once. The reason is, static members are shared among all objects. That is why they are also known as class members or class
fields. Also, static members can be accessed without any object, see the below program where static member ‘a’ is 
accessed without any object.

```cpp
#include <iostream>
using namespace std;
 
class A
{
    int x;
public:
    A() { cout << "A's constructor called " << endl;  }
};
 
class B
{
    static A a;
public:
    B() { cout << "B's constructor called " << endl; }
    static A getA() { return a; }
};
 
A B::a;  // definition of a
 
int main()
{
    // static member 'a' is accessed without any object of B
    A a = B::getA();
 
    return 0;
}
Output: 
A's constructor called
```

### __Some facts__

- function can only be declared inside sturctures in C and should be defined outside structures
- function can be defined inside sturctures in C++
- static function of course , can only be declared inside sturctures in C and should be defined outside structures
- static function can be defined inside sturctures in C++
- static variable can only be declared and must be defined outside structures/class in C/C++
- global varible can be accessed anywhere from the program in a file and also from another file
- to limit the scope of global variable to a specific file , we can declare it static to limit
 the scope to that file only
- similiarly we can also do for function as function in c++/c are global and can be acessed from anywhere in the program 
and other file also, so to make it private to taht file we can make it static function
- constructor and desctructor can never be static and they dio not have return type
- static member function in a class can only acces static member(data/variable/function) of a class 
- when an object is created , two types of constructor is created implicitly
1. copy constructor- if this cosntructor is created by user explicitly, compiler will not create any type of constructor(nor copy neither default)
2. default constructor(non parameterzied)- this is creted by compiler. if this is created by user , only copy constructor will be ccreated
- parameterized constructor is created by user explicitly , and if this is created compiler will not create default constructor and willc create only copy constructor
