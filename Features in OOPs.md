### __Encapsulation in C++__
In normal terms Encapsulation is defined as wrapping up of data and information under a single unit. In Object Oriented Programming,
Encapsulation is defined as binding together the data and the functions that manipulates them.
Consider a real life example of encapsulation, in a company there are different sections like the accounts
section, finance section, sales section etc. The finance section handles all the financial transactions and 
keep records of all the data related to finance. Similarly the sales section handles all the sales related 
activities and keep records of all the sales. Now there may arise a situation when for some reason an official 
from finance section needs all the data about sales in a particular month. In this case, he is not allowed to
directly access the data of sales section. He will first have to contact some other officer in the sales section
and then request him to give the particular data. This is what encapsulation is. Here the data of sales section 
and the employees that can manipulate them are wrapped under a single name “sales section”.

Encapsulation also lead to data abstraction or hiding. As using encapsulation also hides the data. In
the above example the data of any of the section like sales, finance or accounts is hidden from any other section.

In C++ encapsulation can be implemented using Class and access modifiers. Look at the below program:
```cpp
// c++ program to explain
// Encapsulation
  
#include<iostream>
using namespace std;
  
class Encapsulation
{
    private:
        // data hidden from outside world
        int x;
          
    public:
        // function to set value of 
        // variable x
        void set(int a)
        {
            x =a;
        }
          
        // function to return value of
        // variable x
        int get()
        {
            return x;
        }
};
  
// main function
int main()
{
    Encapsulation obj;
      
    obj.set(5);
      
    cout<<obj.get();
    return 0;
}
output:

5
```
In the above program the variable x is made private. This variable can be accessed and manipulated only using
the functions get() and set() which are present inside the class. Thus we can say that here, the variable x
and the functions get() and set() are binded together which is nothing but encapsulation.

Role of access specifiers in encapsulation

As we have seen in above example, access specifiers plays an important role in implementing encapsulation in C++.
The process of implementing encapsulation can be sub-divided into two steps:

- The data members should be labeled as private using the private access specifiers
- The member function which manipulates the data members should be labeled as public using the public access specifier

### __Abstraction in C++__
Data abstraction is one of the most essential and important feature of object oriented programming in C++.
Abstraction means displaying only essential information and hiding the details. Data abstraction refers to
providing only essential information about the data to the outside world, hiding the background details or 
implementation.

Consider a real life example of a man driving a car. The man only knows that pressing the accelerators will
increase the speed of car or applying brakes will stop the car but he does not know about how on pressing accelerator
the speed is actually increasing, he does not know about the inner mechanism of the car or the implementation of accelerator,
brakes etc in the car. This is what abstraction is.

__Abstraction using Classes__: We can implement Abstraction in C++ using classes. Class helps us to group data members
and member functions using available access specifiers. A Class can decide which data member will be visible to
outside world and which is not.

__Abstraction in Header files:__ One more type of abstraction in C++ can be header files. For example, consider
the pow() method present in math.h header file. Whenever we need to calculate power of a number, we simply call 
the function pow() present in the math.h header file and pass the numbers as arguments without knowing the underlying
algorithm according to which the function is actually calculating power of numbers.

__Abstraction using access specifiers__

Access specifiers are the main pillar of implementing abstraction in C++. We can use access specifiers to enforce restrictions on class members. For example:

- Members declared as public in a class, can be accessed from anywhere in the program.
- Members declared as private in a class, can be accessed only from within the class. They are not allowed 
to be accessed from any part of code outside the class.
We can easily implement abstraction using the above two features provided by access specifiers. Say,
the members that defines the internal implementation can be marked as private in a class. And the important 
information needed to be given to the outside world can be marked as public. And these public members can access
the private members as they are inside the class.
```cpp
#include <iostream>
using namespace std;
  
class implementAbstraction
{
    private:
        int a, b;
  
    public:
      
        // method to set values of 
        // private members
        void set(int x, int y)
        {
            a = x;
            b = y;
        }
          
        void display()
        {
            cout<<"a = " <<a << endl;
            cout<<"b = " << b << endl;
        }
};
  
int main() 
{
    implementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}
Output:

a = 10
b = 20
```
You can see in the above program we are not allowed to access the variables a and b directly, however one
can call the function set() to set the values in a and b and the function display() to display the values of a and b.

Advantages of Data Abstraction:

- Helps the user to avoid writing the low level code
- Avoids code duplication and increases reusability.
- Can change internal implementation of class independently without affecting the user.
- Helps to increase security of an application or program as only important details are provided to the user.

### __Polymorphism in C++__
The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability 
of a message to be displayed in more than one form. A real-life example of polymorphism, a person at the same
time can have different characteristics. Like a man at the same time is a father, a husband, an employee. So
the same person posses different behavior in different situations. This is called polymorphism. Polymorphism 
is considered as one of the important features of Object Oriented Programming.

In C++ polymorphism is mainly divided into two types:
- Compile time Polymorphism
- Runtime Polymorphism

__Compile time polymorphism:__ This type of polymorphism is achieved by function overloading or operator overloading.
Function Overloading: When there are multiple functions with same name but different parameters then these functions are
said to be overloaded. Functions can be overloaded by change in number of arguments or/and change in type of arguments.

Rules of Function Overloading
- In C++ and Java, functions can not be overloaded if they differ only in the return type.

```cpp
// C++ program for function overloading
#include <bits/stdc++.h>
  
using namespace std;
class Geeks
{
    public:
      
    // function with 1 int parameter
    void func(int x)
    {
        cout << "value of x is " << x << endl;
    }
      
    // function with same name but 1 double parameter
    void func(double x)
    {
        cout << "value of x is " << x << endl;
    }
      
    // function with same name and 2 int parameters
    void func(int x, int y)
    {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};
  
int main() {
      
    Geeks obj1;
      
    // Which function is called will depend on the parameters passed
    // The first 'func' is called 
    obj1.func(7);
      
    // The second 'func' is called
    obj1.func(9.132);
      
    // The third 'func' is called
    obj1.func(85,64);
    return 0;
} 
Output:

value of x is 7
value of x is 9.132
value of x and y is 85, 64
```
In the above example, a single function named func acts differently in three different situations which is the property of polymorphism.

### __Function overloading and const keyword__
Predict the output of following C++ program.
```cpp
#include<iostream>
using namespace std;
  
class Test
{
protected:
    int x;
public:
    Test (int i):x(i) { }
    void fun() const
    {
        cout << "fun() const called " << endl;
    }
    void fun()
    {
        cout << "fun() called " << endl;
    }
};
  
int main()
{
    Test t1 (10);
    const Test t2 (20);
    t1.fun();
    t2.fun();
    return 0;
}
Output: The above program compiles and runs fine, and produces following output.

fun() called
fun() const called
```
The two methods ‘void fun() const’ and ‘void fun()’ have same signature except that one is const and other is not.
Also, if we take a closer look at the output, we observe that, ‘const void fun()’ is called on const object and ‘void fun()’ 
is called on non-const object.
C++ allows member methods to be overloaded on the basis of const type. Overloading on the basis of const type can be useful
when a function return reference or pointer. We can make one function const, that returns a const reference or const pointer,
other non-const function, that returns non-const reference or pointer. See this for more details.

What about parameters?
Rules related to const parameters are interesting. Let us first take a look at following two examples. The program 1 
fails in compilation, but program 2 compiles and runs fine.
```cpp
// PROGRAM 1 (Fails in compilation)
#include<iostream>
using namespace std;
  
void fun(const int i)
{
    cout << "fun(const int) called ";
}
void fun(int i)
{
    cout << "fun(int ) called " ;
}
int main()
{
    const int i = 10;
    fun(i);
    return 0;
}
Output:

Compiler Error: redefinition of 'void fun(int)'
```
```cpp
// PROGRAM 2 (Compiles and runs fine)
#include<iostream>
using namespace std;
  
void fun(char *a)
{
  cout << "non-const fun() " << a;
}
  
void fun(const char *a)
{
  cout << "const fun() " << a;
}
  
int main()
{
  const char *ptr = "GeeksforGeeks";
  fun(ptr);
  return 0;
}
Output:
const fun() GeeksforGeeks
```
C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a
reference or a pointer. That is why the program 1 failed in compilation, but the program 2 worked fine. This rule
actually makes sense. In program 1, the parameter ‘i’ is passed by value, so ‘i’ in fun() is a copy of ‘i’ in main().
Hence fun() cannot modify ‘i’ of main(). Therefore, it doesn’t matter whether ‘i’ is received as a const paramete
r or normal parameter. When we pass by reference or pointer, we can modify the value referred or pointed, 
so we can have two versions of a function, one which can modify the referred or pointed value, other which can not.

As an exercise, predict the output of following program.
```cpp
#include<iostream>
using namespace std;
  
void fun(const int &i)
{
    cout << "fun(const int &) called ";
}
void fun(int &i)
{
    cout << "fun(int &) called " ;
}
int main()
{
    const int i = 10;
    fun(i);
    return 0;
}
```
### __Functions that cannot be overloaded in C++__
In C++, following function declarations cannot be overloaded.

- Function declarations that differ only in the return type. For example, the following program fails in compilation.
```cpp
#include<iostream>
int foo() { 
  return 10; 
}
  
char foo() { 
  return 'a'; 
}
  
int main()
{
   char x = foo();
   getchar();
   return 0;
}
```
- Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a
 static member function declaration. For example, following program fails in compilation.
```cpp
#include<iostream>
class Test {
   static void fun(int i) {}
   void fun(int i) {}   
};
  
int main()
{
   Test t;
   getchar();
   return 0;
}
```
- Parameter declarations that differ only in a pointer * versus an array [] are equivalent. That is, the array 
declaration is adjusted to become a pointer declaration. Only the second and subsequent array dimensions are 
significant in parameter types. For example, following two function declarations are equivalent.
```cpp
int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)
```
- Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent.
```cpp
void h(int ());
void h(int (*)()); // redeclaration of h(int())
```
- Parameter declarations that differ only in the presence or absence of const and/or volatile are equivalent. That is, 
- the const and volatile type-specifiers for each parameter type are ignored when determining which function is being 
- declared, defined, or called. For example, following program fails in compilation with error “redefinition of `int f(int)’ “
```cpp
#include<iostream>
#include<stdio.h>
   
using namespace std;
   
int f ( int x) {
    return x+10;
}
  
int f ( const int x) {
    return x+10;
}
  
int main() {     
  getchar();
  return 0;
}
```
Only the const and volatile type-specifiers at the outermost level of the parameter type specification are ignored in 
this fashion; const and volatile type-specifiers buried within a parameter type specification are significant and can 
be used to distinguish overloaded function declarations. In particular, for any type T,
“pointer to T,” “pointer to const T,” and “pointer to volatile T” are considered distinct parameter types, as are
“reference to T,” “reference to const T,” and “reference to volatile T.”

- Two parameter declarations that differ only in their default arguments are equivalent. For example, following program fails in compilation 
with error “redefinition of `int f(int, int)’ “

```cpp
#include<iostream>
#include<stdio.h>
   
using namespace std;
   
int f ( int x, int y) {
    return x+10;
}
  
int f ( int x, int y = 10) {
    return x+y;
}
  
int main() {     
  getchar();
  return 0;
}
```

### __Operator Overloading:__
C++ also provide option to overload operators. For example, we can make the operator (‘+’) for string class to 
concatenate two strings. We know that this is the addition operator whose task is to add two operands. So a 
single operator ‘+’ when placed between integer operands , adds them and when placed between string operands,
concatenates them.
```cpp
// CPP program to illustrate
// Operator Overloading
#include<iostream>
using namespace std;
   
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
       
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};
   
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
}
Output:

12 + i9
```
### __Runtime polymorphism: Function overriding__
- Function overriding on the other hand occurs when a derived class has a definition for one of the member functions of
 the base class. That base function is said to be overridden.
 ```cpp
 // C++ program for function overriding
  
#include <bits/stdc++.h>
using namespace std;
  
class base
{
public:
    virtual void print ()
    { cout<< "print base class" <<endl; }
   
    void show ()
    { cout<< "show base class" <<endl; }
};
   
class derived:public base
{
public:
    void print () //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
    { cout<< "print derived class" <<endl; }
   
    void show ()
    { cout<< "show derived class" <<endl; }
};
  
//main function
int main() 
{
    base *bptr;
    derived d;
    bptr = &d;
       
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 
       
    // Non-virtual function, binded at compile time
    bptr->show(); 
  
    return 0;
} 
Output:

print derived class
show base class
 ```
__Definitions:__
- A virtual function is a member function which is declared in the base class using the keyword virtual and is re-defined
 (Overriden) by the derived class.
- The term Polymorphism means the ability to take many forms. It occurs if there is a hierarchy of classes which are
 all related to each other by inheritance.
 
The idea is that virtual functions are called according to the type of the object instance pointed to or referenced, not according to the type of the pointer or reference.
In other words, virtual functions are resolved late, at runtime.
 
Now, we’ll look at an example using both these concepts to clarify your understanding.
```cpp
#include <iostream>
using namespace std;
 
// Base class
class Shape
{
public:
    Shape(int l, int w)
    {
        length = l;
        width = w;
    } // parameterized constructor
    int get_Area()
    {
        cout << "This is call to parent class area" << endl;
          return 1;
    }
 
protected:
    int length, width;
};
 
// Derived class
class Square : public Shape
{
public:
    Square(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
      // constructor
    int get_Area()
    {
        cout << "Square area: " << length * width << endl;
        return (length * width);
    }
};
// Derived class
class Rectangle : public Shape
{
public:
    Rectangle(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
      // constructor
    int get_Area()
    {
        cout << "Rectangle area: " << length * width
             << endl;
        return (length * width);
    }
};
 
int main(void)
{
    Shape* s;
    Square sq(5, 5); // making object of child class Square
    Rectangle rec(
        4, 5); // making object of child class Rectangle
 
    s = &sq;
    s->get_Area();
    s = &rec;
    s->get_Area();
 
    return 0;
}
Output
This is call to parent class area
This is call to parent class area
```
 In the above function:

- we store the address of each child class Rectangle and Square object in s and
- then we call the get_Area() function on it,
- ideally, it should have called the respective get_Area() functions of the child classes but
- instead it calls the get_Area() defined in the base class.
- This happens due static linkage which means the call to get_Area() is getting set only once by the compiler which
 is in the base class.

Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes
without even knowing kind of derived class object. 
For example: Consider an employee management software for an organization. 
Let the code has a simple base class Employee , the class contains virtual functions like raiseSalary(), transfer(),
promote(), etc. Different types of employees like Manager, Engineer, etc. may have their own implementations of the
virtual functions present in base class Employee. 
In our complete software, we just need to pass a list of employees everywhere and call appropriate functions without 
even knowing the type of employee. For example, we can easily raise the salary of all employees by iterating through the
list of employees. Every type of employee may have its own logic in its class, but we don’t need to worry about them 
because if raiseSalary() is present for a specific employee type, only that function would be called.
```cpp
class Employee {
public:
    virtual void raiseSalary()
    {
        /* common raise salary code */
    }
 
    virtual void promote() { /* common promote code */ }
};
 
class Manager : public Employee {
    virtual void raiseSalary()
    {
        /* Manager specific raise salary code, may contain
          increment of manager specific incentives*/
    }
 
    virtual void promote()
    {
        /* Manager specific promote */
    }
};
 
// Similarly, there may be other types of employees
 
// We need a very simple function
// to increment the salary of all employees
// Note that emp[] is an array of pointers
// and actual pointed objects can
// be any type of employees.
// This function should ideally
// be in a class like Organization,
// we have made it global to keep things simple
void globalRaiseSalary(Employee* emp[], int n)
{
    for (int i = 0; i < n; i++)
 
        // Polymorphic Call: Calls raiseSalary()
        // according to the actual object, not
        // according to the type of pointer
        emp[i]->raiseSalary();
}
```
Like globalRaiseSalary(), there can be many other operations that can be performed on a list of employees without even
knowing the type of the object instance. 
Virtual functions are so useful that later languages like Java keep all methods as virtual by default.
How does the compiler perform runtime resolution?
The compiler maintains two things to serve this purpose:

- vtable: A table of function pointers, maintained per class. 
- vptr: A pointer to vtable, maintained per object instance

Compiler adds additional code at two places to maintain and use vptr.
- Code in every constructor. This code sets the vptr of the object being created. This code sets vptr to point 
to the vtable of the class. 
- Code with polymorphic function call (e.g. bp->show() in above code). Wherever a polymorphic call is 
made, the compiler inserts code
 to first look for vptr using base class pointer or reference (In the above example, since pointed or referred 
 object is of derived type, vptr of derived class is accessed). Once vptr is fetched, vtable of derived class
 can be accessed. Using vtable, address of derived class function show() is accessed and called. 
 
Is this a standard way for implementation of run-time polymorphism in C++? 
The C++ standards do not mandate exactly how runtime polymorphism must be implemented, but compilers generally use minor variations on the same basic model.
