- Memory leakage occurs in C++ when programmers allocates memory by using new keyword and forgets to deallocate
the memory by using delete() function or delete[] operator. One of the most memory leakage occurs in 
C++ by using wrong delete operator.

- The delete operator should be used to free a single allocated memory space, whereas the delete [] operator should be used to free an array of data values.
- Disadvantage with memory leakage: 
If a program has memory leaks, then its memory usage is satirically increasing since all systems
have limited amount of memory and memory is costly. Hence it will create problems.

```cpp
// Program with memory leak
#include <bits/stdc++.h>
using namespace std;
 
// function with memory leak
void func_to_show_mem_leak()
{
    int* ptr = new int(5);
 
    // body
 
    // return without deallocating ptr
    return;
}
 
// driver code
int main()
{
 
    // Call the function
    // to get the memory leak
    func_to_show_mem_leak();
 
    return 0;
}
```
How to avoid Memory Leak?

- Instead of managing memory manually, try to use smart pointers where applicable.
- use std::string instead of char *. The std::string class handles all memory management 
internally, and it’s fast and well-optimized.
- Never use a raw pointer unless it’s to interface with an older lib.
- The best way to avoid memory leaks in C++ is to have as few new/delete calls at the program level as possible 
ideally NONE. Anything that requires dynamic memory should be buried inside an RAII object that releases the memory
when it goes out of scope. RAII allocate memory in constructor and release it in destructor, so that memory is guaranteed to be deallocated when the variable leave the current scope.
- Allocate memory by new keyword and deallocate memory by delete keyword and write all code between them.
```cpp
Example to handle memory leaks
 


// CPP program to
// illustrate how to avoid
// memory leak
#include <bits/stdc++.h>
using namespace std;
 
// function to see memory handling
void func_to_handle_mem_leak()
{
    int* ptr = new int(5);
 
    // body
 
    // Now delete pointer ptr using delete
    delete (ptr);
}
 
// Driver code
int main()
{
 
    // Call function to handle
    // the memory leak
    func_to_handle_mem_leak()
 
        return 0;
}
```
Therefore, Always write delete pointer for matching of new pointer in C++ and always write code between these
new and delete as explained in above example. In above example, no memory is wasted because when we are 
coming out from the function we are deallocating the memory by using delete function.
