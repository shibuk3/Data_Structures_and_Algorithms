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
