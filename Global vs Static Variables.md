### __

- Global variables are variables which are defined outside the function. The scope of global variables
begins at the point where they are defined and lasts till the end of the file/program. They have external 
linkage, which means that in other source files, the same name refers to the same location in memory.

- Static global variables are private to the source file where they are defined and do not conflict with
 other variables in other source files which would have the same name.

- Both global, as well as static variables, have static initialization, which means that if you don't
assign them a value, they will get initialized to 0 (common variables) or NULL (pointers).

- Static global variables: Variables declared as static at the top level of a source file 
(outside any function definitions) are only visible throughout that file.

- Static local variables: Variables declared as static inside a function are statically allocated,
 thereby keeping their memory cell throughout all program execution, while also having the same scope of
 visibility as automatic local variables. Hence whatever values the function puts into its static local
 variables during one call will remain the same whenever the function is called again.
 
 ### __What is a Static Variable?__
 - A static keyword serves a different purpose depending on where it has been declared.

- If it is declared inside of a class, all instances of the class (i.e. objects) will share the
same copy of the variable, and we can access it without any object by class name outside the class.

- If it is declared inside of a function then its value is preserved between successive calls for
the lifetime of the program, but it cannot be accessd outside the scope or function in which it is declared.
 
```cpp
Example 1: Static Variable inside of a Class
#include <iostream>
using namespace std;
 
class Natural{
public:
    static int num;
 
    void increase(){
        ++num;
    }
};
/* 
  *It is important to initialize the static variable outside of a class
  *we do so by using the class name and scope resolution operator.
*/
int Natural::num = 0;
 
int main()
{   
    //Creating 1st object
    Natural obj1;
 
    //Incrementing Natural::num 2 times
    obj1.increase();
    obj1.increase();
 
    cout << "Num of 1st Object: "<< obj1.num << endl;
 
    //Creating 2nd object
    Natural obj2;
 
    cout << "Num of 2nd Object: "<< obj2.num << endl;
 
    return 0;
}
Output:

Num of 1st Object: 2
Num of 2nd Object: 2
```
Observe the output, the value of num of both the objects are the same,
regardless of the fact that we have not incremented the num of the second object.

The same value of num in both objects proves that a static variable is shared among the objects.
```cpp
Example 2: Static Variable inside a Function
#include <iostream>
using namespace std;
 
void increase(){
    static int num = 0;
    cout << ++num << endl;
}
 
int main(){
    increase();
    increase();
    return 0;
}
Output:

1
2
```
Observe the output in this case. We have called the increase function twice in the main method
and on the second call, the output is the incremented value of the first increase() function call.

This proves that the static variable inside a function is declared only once on the first 
function call and the remaining successive function calls use the same copy.

- What if there exists a local variable with the same name as that of global variable inside a function?

Let us repeat the question once again. The question is : if there is a variable inside a function with 
the same name as that of a global variable and if the function tries to access the variable with that
name, then which variable will be given precedence? Local variable or Global variable? Look at the 
below program to understand the question:  

```cpp
// CPP program to illustrate
// scope of local variables
// and global variables together
#include<iostream>
using namespace std;
 
// global variable
int global = 5;
 
// main function
int main()
{  
    // local variable with same
    // name as that of global variable
     
    int global = 2;
    cout << global << endl;
}
output= 2
```
- Usually when two variable with same name are defined then the compiler produces a compile time error. 
But if the variables are defined in different scopes then the compiler allows it.
- Whenever there is a local variable defined with same name as that of a global variable then the 
compiler will give precedence to the local variable

__How to access a global variable when there is a local variable with same name?__
```cpp
// C++ program to show that we can access a global
// variable using scope resolution operator :: when 
// there is a local variable with same name
#include<iostream>
using namespace std;
  
// Global x 
int x = 0; 
   
int main()
{
  // Local x   
  int x = 10;
  cout << "Value of global x is " << ::x;
  cout<< "\nValue of local x is " << x; 
  return 0;
}
Output: 

Value of global x is 0
Value of local x is 10
```
